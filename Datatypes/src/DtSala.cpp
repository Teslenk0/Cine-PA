//
// Created by tesla on 16/06/19.
//

#include "../Headers/DtSala.h"

DtSala::DtSala(){
}

DtSala::DtSala(int idSala, int cant){
    this->id = idSala;
    this->cantAsientos = cant;
}

int DtSala::getID() const{
    return this->id;
}

int DtSala::getCantAsientos() const{
    return this->cantAsientos;
}

DtSala::~DtSala(){
    // ELIMINAR Sala
}
