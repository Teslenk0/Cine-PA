//
// Created by tesla on 14/06/19.
//

#include "../../Collections/Headers/OrderedDictionary.h"
#include "../Headers/Cine.h"
#include "../../IntKey.h"

Cine::Cine() {

}

Cine::Cine(int number, DtDireccion *dir) {
    this->nro=number;
    this->direccion=new DtDireccion();
    this->direccion=dir;
    this->salas= new OrderedDictionary();
    this->funciones=new OrderedDictionary();
    this->pelis=new OrderedDictionary();
    this->cantFunciones=0;
}

Cine::Cine(DtCine* c) {
    this->nro=c->getID();
    this->direccion=c->getDireccion();
    ICollection* s=c->getSalas();
    IIterator* it=s->getIterator();
    this->salas=new OrderedDictionary();
    while(it->hasCurrent()){
        DtSala* aux=dynamic_cast<DtSala*>(it->getCurrent());
        Sala* s=new Sala(aux);  //paso de la coleccion de dtsala a sala
        IntKey* ikC=new IntKey(s->getID());
        salas->add(ikC,s);
        it->next();
    }
    delete it;
    this->funciones=new OrderedDictionary();
    this->pelis=new OrderedDictionary();
}

DtCine *Cine::getCine() const {
    ICollection* f=new List();
    IIterator* it=this->funciones->getIterator();
    while(it->hasCurrent()){
        Funcion* func= dynamic_cast<Funcion*>(it->getCurrent());
        cout<<func->getNro();
        DtFuncion* aux1=func->getFuncion();
        f->add(aux1);
        it->next();
    }
    ICollection* films=new List();
    it= nullptr;
    it=pelis->getIterator();
    while(it->hasCurrent()){
        Pelicula* peli= dynamic_cast<Pelicula*>(it->getCurrent());
        DtPelicula* aux2=peli->getPelicula();
        films->add(aux2);
        it->next();
    }
    ICollection* rooms=new List();
    it= nullptr;
    it=salas->getIterator();
    while(it->hasCurrent()){
        Sala* auxiliar= dynamic_cast<Sala*>(it->getCurrent());
        DtSala* aux3=auxiliar->getSala();
        rooms->add(aux3);
        it->next();
    }
    delete it;
    DtCine* completo=new DtCine(this->nro,this->direccion,rooms,f,films);
    return completo;
    //return new DtCine(this->getNro(),this->getDireccion());
}

int Cine::getNro() const {
    return this->nro;
}

DtDireccion *Cine::getDireccion() const {
    return this->direccion;
}

void Cine::setDireccion(DtDireccion* dir) {
    this->direccion=dir;
}

void Cine::setNro(int number) {
    this->nro=number;
}
int Cine::getCantSalas()const {
    return salas->getSize();
}
void Cine::agregoSala(int cantAsientos) {
    int maximo=this->getCantSalas()+1;
    Sala* s=new Sala(maximo,cantAsientos);
    IntKey* iK=new IntKey(maximo);
    salas->add(iK,s);
}

void Cine::agregoFunciones(DtFuncion* f) {
    Funcion* func=new Funcion(f);
    IntKey* ikF=new IntKey(f->getNro());
    funciones->add(ikF,func);
    Pelicula* p=new Pelicula(f->getPelicula());
    StringKey* skP=new StringKey(p->getTitulo());
    pelis->add(skP,p);
}

void Cine::listarSalas(){
    IIterator* it=salas->getIterator();
    while(it->hasCurrent()){
        Sala* aux=dynamic_cast<Sala*>(it->getCurrent());
        cout<<"ID: "<<aux->getID()<<" ->Asientos: "<<aux->getCantAsientos()<<endl<<"-------------------------------------"<<endl;
        it->next();
    }
    delete it;
}

bool Cine::existePeli(string title) {
    StringKey* sk=new StringKey(title);
    return this->pelis->member(sk);
}

Cine::~Cine() {
    delete direccion;

    IIterator* it=salas->getIterator();
    while (it->hasCurrent()) {
        Sala* sala = dynamic_cast<Sala*>(it->getCurrent());         //BORRO LAS SALAS
        it->next();
        delete sala;
    }
    delete salas;


    it= nullptr;
    it=funciones->getIterator();
    while (it->hasCurrent()) {
        Funcion* funcion = dynamic_cast<Funcion*>(it->getCurrent());         //BORRO LOS CINES
        it->next();
        delete funcion;
    }
    delete funciones;

    it= nullptr;
    it=pelis->getIterator();
    while (it->hasCurrent()) {
        Pelicula* peli = dynamic_cast<Pelicula*>(it->getCurrent());         //BORRO LOS CINES
        it->next();
        delete peli;
    }
    delete pelis;


}

void Cine::agregarReserva(int nroFunc, float costo, int asientos, bool isDebito, string bancoFinan) {
    IntKey* ik=new IntKey(nroFunc);
    Funcion* f= dynamic_cast<Funcion*>(funciones->find(ik));
    f->agregarReserva(costo,asientos,isDebito,bancoFinan);
}
