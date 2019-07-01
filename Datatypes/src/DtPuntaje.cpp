//
// Created by tesla on 30/06/19.
//

#include "../Headers/DtPuntaje.h"

DtPuntaje::DtPuntaje() {

}

DtPuntaje::DtPuntaje(int p, DtUsuario *u) {
    this->puntaje=p;
    this->user=u;
}

int DtPuntaje::getPuntaje() const {
    return this->puntaje;
}

DtUsuario* DtPuntaje::getUsuario() const {
    return this->user;
}

DtPuntaje::~DtPuntaje() {
    delete user;
}