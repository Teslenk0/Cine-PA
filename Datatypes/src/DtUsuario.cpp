//
// Created by tesla on 28/06/19.
//

#include "../Headers/DtUsuario.h"

DtUsuario::DtUsuario() {

}

DtUsuario::DtUsuario(string nickname, string password, string imagen, bool adm) {
    this->nick=nickname;
    this->admin=adm;
    this->pass=password;
    this->imagen=imagen;
}


bool DtUsuario::isAdmin() {
    return this->admin;
}

string DtUsuario::getImagen() const {
    return this->imagen;
}

string DtUsuario::getPass() const {
    return this->pass;
}

string DtUsuario::getNick() const {
    return this->nick;
}

DtUsuario::~DtUsuario() {

}