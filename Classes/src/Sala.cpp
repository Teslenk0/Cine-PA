//
// Created by tesla on 16/06/19.
//

#include "../Headers/Sala.h"

Sala::Sala(){
}

Sala::Sala(int idSala, int cant){
    this->id = idSala;
    this->cantAsientos = cant;
}

Sala::Sala(DtSala *s) {
    this->id=s->getID();
    this->cantAsientos=s->getCantAsientos();
}

DtSala *Sala::getSala() const{
    return new DtSala(this->id, this->cantAsientos);
}

int Sala::getID() const{
    return this->id;
}

int Sala::getCantAsientos() const{
    return this->cantAsientos;
}

void Sala::setID(int NroSala){
    this->id = NroSala;
}

void Sala::setCantAsientos(int Capacidad){
    this->cantAsientos = Capacidad;
}

Sala::~Sala(){
    // ELIMINAR Sala
}
