//
// Created by tesla on 30/06/19.
//

#include "../Headers/Comentario.h"

Comentario::Comentario() {
    this->respuestas=new List();
}

Comentario::Comentario(string com, DtUsuario *user) {
    this->coment=com;
    this->usuario=user;
    this->respuestas=new List();
}

Comentario::Comentario(DtComentario* c) {
    this->coment=c->getComentario();
    this->usuario=c->getUsuario();
    this->respuestas=c->getRespuestas();
}

DtUsuario* Comentario::getUsuario() const {
    return this->usuario;
}

string Comentario::getComentario() const {
    return this->coment;
}

ICollection* Comentario::getRespuestas()const{
    return this->respuestas;
}

void Comentario::setComentario(string c) {
    this->coment=c;
}

void Comentario::setUsuario(DtUsuario *u) {
    this->usuario=u;
}

DtComentario* Comentario::getComentCompleto() const {
    IIterator* it=this->respuestas->getIterator();
    ICollection* aux=new List();
    while(it->hasCurrent()){

    }
    return new DtComentario(this->coment,this->usuario,aux);
}

Comentario::~Comentario() {

}