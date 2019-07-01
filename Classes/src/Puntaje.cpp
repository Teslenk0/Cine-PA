//
// Created by tesla on 30/06/19.
//

#include "../Headers/Puntaje.h"


Puntaje::Puntaje() {

}

Puntaje::Puntaje(int points,DtUsuario *u) {
    this->puntaje=points;
    this->user=u;
}

int Puntaje::getPuntaje() const {
    return this->puntaje;
}

DtUsuario* Puntaje::getUsuario() const {
    return this->user;
}

void Puntaje::setPuntaje(int p) {
    this->puntaje=p;
}

void Puntaje::setUsuario(DtUsuario *u) {
    this->user=u;
}


Puntaje::~Puntaje() {
    delete this->user;
}

DtPuntaje *Puntaje::getPuntajeCompleto() {
    return new DtPuntaje(this->puntaje,this->user);
}
