//
// Created by tesla on 13/06/19.
//

#include "../Headers/usuario.h"

Usuario::Usuario() {

}

Usuario::Usuario(string nickname, string password, string imagen, bool adm) {
    this->nick=nickname;
    this->pass=password;
    this->imagen=imagen;
    this->admin=adm;
}

Usuario::Usuario(DtUsuario *user) {
    this->nick=user->getNick();
    this->pass=user->getPass();
    this->imagen=user->getImagen();
    this->admin=user->isAdmin();
}

bool Usuario::validarPass(string password) {
    if(this->pass==password){
        return true;
    }else{
        return false;
    }
}

DtUsuario* Usuario::getUsuario()const{
    return new DtUsuario(this->nick,this->pass,this->imagen,this->admin);
}

string Usuario::getNick() const {
    return this->nick;
}

string Usuario::getPass() const {
    return this->pass;
}

string Usuario::getImagen() const {
    return this->imagen;
}

bool Usuario::isAdmin() {
    return this->admin;
}

void Usuario::setNick(string nickname) {
    this->nick=nickname;
}

void Usuario::setPass(string password) {
    this->pass=password;
}

void Usuario::setImagen(string imagen) {
    this->imagen=imagen;
}

Usuario::~Usuario() {

}