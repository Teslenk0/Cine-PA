//
// Created by tesla on 16/06/19.
//

#include "../Headers/DtFuncion.h"

DtFuncion::DtFuncion() {

}

DtFuncion::DtFuncion(int id,DtFecha* fec, DtPelicula* p, DtSala* s) {
    this->numero=id;
    this->sala=s;
    this->peli=p;
    this->fecha=fec;
}

int DtFuncion::getNro() const{
    return this->numero;
}

DtSala* DtFuncion::getSala() const{
    return this->sala;
}

DtFecha* DtFuncion::getFecha() const{
    return this->fecha;
}

DtPelicula* DtFuncion::getPelicula()const{
    return this->peli;
}

DtFuncion::~DtFuncion(){

}