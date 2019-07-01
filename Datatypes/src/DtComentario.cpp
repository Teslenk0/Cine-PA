//
// Created by tesla on 30/06/19.
//

#include "../Headers/DtComentario.h"

DtComentario::DtComentario() {

}

DtComentario::DtComentario(string com, DtUsuario *user) {
    this->coment=com;
    this->usuario=user;
    this->respuestas=new List();
}

DtComentario::DtComentario(string com, DtUsuario *user, ICollection *resp) {
    this->coment=com;
    this->usuario=user;
    this->respuestas=resp;
}

string DtComentario::getComentario() const {
    return this->coment;
}

ICollection *DtComentario::getRespuestas() const {
    return this->respuestas;
}

DtUsuario* DtComentario::getUsuario() const {
    return this->usuario;
}

void DtComentario::setComentario(string c) {
    this->coment=c;
}

void DtComentario::setUsuario(DtUsuario *u) {
    this->usuario=u;
}

DtComentario::~DtComentario() {

}



