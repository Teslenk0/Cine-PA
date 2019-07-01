//
// Created by tesla on 13/06/19.
//

#include "../Headers/DtCine.h"

DtCine::DtCine(){

}
DtCine::DtCine(int ID,DtDireccion* dir){
    this->id=ID;
    this->direccion=new DtDireccion();
    this->direccion=dir;
    this->cantSalas=0;
    this->salas=new List();
}

DtCine::DtCine(int ID, DtDireccion *dir, ICollection *salinhas, ICollection *functions, ICollection *pelis) {
    this->id=ID;
    this->direccion=new DtDireccion();
    this->direccion=dir;
    this->cantSalas=salinhas->getSize();
    this->salas=salinhas;
    this->funciones=functions;
    this->peliculas=pelis;
}

int DtCine::getID()const{
    return this->id;
}

void DtCine::agregoSala(int asientos) {
    DtSala* s=new DtSala(this->cantSalas+1,asientos);
    this->salas->add(s);
    this->cantSalas+=1;
}

DtDireccion *DtCine::getDireccion()const{
    return this->direccion;
}
ICollection* DtCine::getSalas() const {
    return this->salas;
}

ICollection* DtCine::getFuncionesPosterioresAhora(DtFecha *ahora,string title) {
    IIterator* it=funciones->getIterator();
    ICollection* col=new List();
    while(it->hasCurrent()){
        DtFuncion* aux=dynamic_cast<DtFuncion*>(it->getCurrent());
        if((ahora>aux->getFecha()) && (aux->getPelicula()->getTitulo()==title)){
            col->add(aux);
        }
        it->next();
    }
    delete it;
    return col;
}

DtCine::~DtCine(){
    delete this->direccion;
}

ICollection *DtCine::getFunciones() const {
    return this->funciones;
}

ICollection *DtCine::getPelis() const {
    return this->peliculas;
}
