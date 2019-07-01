//
// Created by tesla on 16/06/19.
//

#include "../../Datatypes/Headers/DtCine.h"
#include "../Headers/Sistema.h"
#include "../Headers/usuario.h"
#include "../../Collections/Headers/OrderedDictionary.h"
#include "../../StringKey.h"
#include "../Headers/Cine.h"
#include "../../IntKey.h"
#include "../Headers/Pelicula.h"
#include "../../Datatypes/Headers/DtFecha.h"

Sistema::Sistema() {
    usuarios=new OrderedDictionary();
    cines=new OrderedDictionary();
    functions=new FuncionesAux();
    peliculas=new OrderedDictionary();
}

Sistema* Sistema::instance=nullptr;

Sistema *Sistema::getInstance() {
    if (instance == nullptr){
        instance = new Sistema();
        instance->precargoRoot();
    }
    return instance;
}

void Sistema::precargoRoot(){
    Usuario* root=new Usuario("root","123456","raiz",true);
    StringKey* sk=new StringKey(root->getNick());
    usuarios->add(sk,root);

    Usuario* tesla=new Usuario("tesla","1","capo",false);
    StringKey* sk1=new StringKey(tesla->getNick());
    usuarios->add(sk1,tesla);

    this->altaPelicula(new DtPelicula("Cars","Carreras de autos","Auto Rojo",0,0));

}

bool Sistema::registroUsuario(DtUsuario* user) {
    StringKey* sk = new StringKey(user->getNick());
    if (!usuarios->member(sk)) {
        Usuario* u=new Usuario(user);
        usuarios->add(sk,u);
        return true;
    }else{
        return false;
    }
}

ICollection* Sistema::listarPeliculas() {
    IIterator* it=this->peliculas->getIterator();
    ICollection* pelis=new List();
    while(it->hasCurrent()){
        Pelicula* aux=dynamic_cast<Pelicula*>(it->getCurrent());
        DtPelicula* p=aux->getPelicula();
        pelis->add(p);
        it->next();
    }
    delete it;
    return pelis;
}

bool Sistema::validarSesion(string user, string password) {
    StringKey* sk=new StringKey(user);
    if(usuarios->member(sk)){
        Usuario* u=dynamic_cast<Usuario*>(usuarios->find(sk));
        if(u->validarPass(password)){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

//EVALUAR LA CREACION DE UNA VARIABLE DE SESION O BIEN UN CONTROLADOR QUE SOLO TENGA UNA SOLA INSTANCIA
void Sistema::iniciarSesion(){
    this->sesionIniciada=true;
}

void Sistema::cerrarSesion(){
    this->sesionIniciada=false;
}

bool Sistema::isSesionAdmin(string nick){
    StringKey* sk=new StringKey(nick);
    Usuario* u= dynamic_cast<Usuario*>(usuarios->find(sk));
    if(u->isAdmin()){
        return true;
    }else{
        return false;
    }
}
ICollection* Sistema::listarCines(){
    ICollection* cinemas=new List();
    IIterator* it=cines->getIterator();
    while(it->hasCurrent()){
        Cine* cinema= dynamic_cast<Cine*>(it->getCurrent());
        DtCine* c=cinema->getCine();
        cinemas->add(c);
        it->next();
    }
    delete it;
    return cinemas;
}



ICollection *Sistema::peliculaxCines(string title){
    ICollection* c=new List();
    IIterator* it=cines->getIterator();
    while(it->hasCurrent()){
        Cine* aux=dynamic_cast<Cine*>(it->getCurrent());
        if(aux->existePeli(title)){
            c->add(aux->getCine()); //guardo en la coleccion los DTcine en los que se pasa esa peli
        }
        it->next();
    }
    delete it;
    return c;
}


void Sistema::borrarPelicula(DtPelicula* p) {
    StringKey* sk=new StringKey(p->getTitulo());
    Pelicula* pelicula= dynamic_cast<Pelicula*>(peliculas->find(sk));
    peliculas->remove(sk);
    delete pelicula;
}

bool Sistema::existePeli(string title){
    StringKey* sk=new StringKey(title);
    return this->peliculas->member(sk);
}

void Sistema::altaPelicula(DtPelicula* peli){
    StringKey* sk=new StringKey(peli->getTitulo());
    Pelicula *p = new Pelicula(peli);
    this->peliculas->add(sk, p);
    this->cantPelis += 1;
}

//probando
void Sistema::altaCine(DtCine* c) {
    Cine* cine=new Cine(c);
    IntKey* ikC=new IntKey(cine->getNro());
    this->cines->add(ikC,cine);
    this->cantCines+=1;
}

Sistema::~Sistema() {
    IIterator* it = usuarios->getIterator();
    while (it->hasCurrent()) {
        Usuario* temp = dynamic_cast<Usuario*>(it->getCurrent());       //BORRO LOS USUARIOS
        it->next();
        delete temp;
    }
    delete usuarios;

    it= nullptr;
    it=peliculas->getIterator();
    while (it->hasCurrent()) {
        Pelicula* peli = dynamic_cast<Pelicula*>(it->getCurrent());  //BORRO LAS PELICULAS
        it->next();
        delete peli;
    }
    delete peliculas;

    it= nullptr;
    it=cines->getIterator();
    while (it->hasCurrent()) {
        Cine* cine = dynamic_cast<Cine*>(it->getCurrent());         //BORRO LOS CINES
        it->next();
        delete cine;
    }
    delete cines;

    it= nullptr;
    //seguir

    delete it;
    delete functions;
    //seguir agregando para eliminar las otras colecciones

    instance = nullptr;// esto va al final
}

void Sistema::altaFuncion(DtCine* c,DtFuncion* f) {
    IntKey* ik=new IntKey(c->getID());
    Cine* cine= dynamic_cast<Cine*>(cines->find(ik));
    cine->agregoFunciones(f);
}


void Sistema::eliminoCine(DtCine *c) {
    IntKey* ik=new IntKey(c->getID());
    Cine* cine= dynamic_cast<Cine*>(cines->find(ik));
    cines->remove(ik);
    delete cine;
}

bool Sistema::existeUsuario(string nick) {
    StringKey* sk=new StringKey(nick);
    return usuarios->member(sk);
}


void Sistema::crearReservaCredito(DtCine *c, int nroFunc, float costo, int asientos, string financiera) {
    IntKey* ik=new IntKey(c->getID());
    Cine* cinema= dynamic_cast<Cine*>(cines->find(ik));
    cinema->agregarReserva(nroFunc,costo,asientos,false,financiera);
}

void Sistema::crearReservaDebito(DtCine *c, int nroFunc, float costo, int asientos, string banco) {
    IntKey* ik=new IntKey(c->getID());
    Cine* cinema= dynamic_cast<Cine*>(cines->find(ik));
    cinema->agregarReserva(nroFunc,costo,asientos,true,banco);
}

void Sistema::puntuarPelicula(DtPelicula *p, string user, int puntaje) {
    StringKey* sk=new StringKey(user);
    Usuario* u= dynamic_cast<Usuario*>(usuarios->find(sk));
    DtUsuario* aux=u->getUsuario();

    StringKey* skP=new StringKey(p->getTitulo());
    Pelicula* peli= dynamic_cast<Pelicula*>(peliculas->find(skP));
    peli->agregoPuntuacion(aux,puntaje);
}

int Sistema::buscoPuntaje(DtPelicula *p, string user) {
    StringKey* sk=new StringKey(user);
    Usuario* u= dynamic_cast<Usuario*>(usuarios->find(sk));
    DtUsuario* aux=u->getUsuario();

    StringKey* skP=new StringKey(p->getTitulo());
    Pelicula* peli= dynamic_cast<Pelicula*>(peliculas->find(skP));
    return peli->buscoPuntaje(aux);
}

ICollection* Sistema::listarComentarios(DtPelicula* p){
    /*StringKey* sk=new StringKey(p->getTitulo());
    Pelicula* peli= dynamic_cast<Pelicula*>(peliculas->find(sk));
    return peli->getComentarios();*/
    return nullptr;
}

ICollection *Sistema::listarPuntajes(DtPelicula *p) {
    StringKey* sk=new StringKey(p->getTitulo());
    Pelicula *peli= dynamic_cast<Pelicula*>(peliculas->find(sk));
    return peli->getPuntajes();
}
