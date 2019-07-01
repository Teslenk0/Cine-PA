//
// Created by tesla on 16/06/19.
//
#include <iostream>
#include "../Headers/Funcion.h"
#include "../../Datatypes/Headers/DtFuncion.h"
using namespace std;


Funcion::Funcion() {

}

Funcion::Funcion(int id,Sala* s,DtFecha* fec,Pelicula* peli) {
    this->numero=id;
    this->sala=s;
    this->fecha=new DtFecha();
    this->pelicula= peli;
    this->fecha=fec;
    this->reservas=new OrderedDictionary();
    this->cantReservas=0;
}

Funcion::Funcion(DtFuncion* f){
    this->numero=f->getNro();
    this->sala=new Sala(f->getSala());
    this->pelicula=new Pelicula(f->getPelicula());
    this->fecha=f->getFecha();
    this->reservas=new OrderedDictionary();
    this->cantReservas=0;
}

DtFuncion *Funcion::getFuncion()const{
    return new DtFuncion(this->numero,this->fecha,this->getPeli(),this->getSala());
}

int Funcion::getNro() const{
    return this->numero;
}
int Funcion::getIDsala() const{
    return this->sala->getID();
}
DtFecha* Funcion::getFecha() const{
    return this->fecha;
}

DtSala* Funcion::getSala()const{
    return new DtSala(this->sala->getID(),this->sala->getCantAsientos());
}

DtPelicula* Funcion::getPeli() const {
    return new DtPelicula(this->pelicula->getTitulo(),this->pelicula->getPoster(),this->pelicula->getSipnosis(),this->pelicula->getCantPuntuaciones(),this->pelicula->getPuntaje());
}

void Funcion::setNro(int id){
    this->numero=id;
}

void Funcion::setIDsala(int id){
    this->sala->setID(id);
}

void Funcion::setFecha(DtFecha* fec){
    this->fecha=fec;
}

string Funcion::getTituloPeli() const {
    return this->pelicula->getTitulo();
}

void Funcion::agregarReserva(float costo, int asientos, bool isDebito, string bancoFinan) {
    if(isDebito){
        Reserva* reser=new PagoDebito(asientos,costo,bancoFinan);
        IntKey* ik=new IntKey(this->cantReservas+1);
        reservas->add(ik,reser);
    }else{
        Reserva* reser=new PagoCredito(asientos,costo,bancoFinan);
        IntKey* ik=new IntKey(this->cantReservas+1);
        reservas->add(ik,reser);
    }
    this->cantReservas+=1;
}

Funcion::~Funcion(){
    delete this->sala;
    delete this->pelicula;
    delete this->fecha;
    IIterator* it=reservas->getIterator();
    while (it->hasCurrent()) {
        Reserva* reserva = dynamic_cast<Reserva*>(it->getCurrent());         //BORRO LOS CINES
        it->next();
        delete reserva;
    }
    delete reservas;
    delete it;
}