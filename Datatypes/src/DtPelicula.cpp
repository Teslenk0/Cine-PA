//
// Created by tesla on 13/06/19.
//

#include "../Headers/DtPelicula.h"

DtPelicula::DtPelicula() {

}

DtPelicula::DtPelicula(string titulo, string poster, string sipnosis,int cant,float puntaje) {
    this->titulo=titulo;
    this->poster=poster;
    this->sipnosis=sipnosis;
    this->cantPuntuaciones=cant;
    this->puntaje=puntaje;
    this->puntajes=new List();
    this->comentarios=new List();
}

DtPelicula::DtPelicula(string titulo, string poster, string sipnosis,int cant,float puntaje, ICollection *pun) {
    this->titulo=titulo;
    this->poster=poster;
    this->sipnosis=sipnosis;
    this->cantPuntuaciones=cant;
    this->puntaje=puntaje;
    this->puntajes=pun;
    this->comentarios=new List();
}

DtPelicula::DtPelicula(string titulo, string poster, string sipnosis,int cant,float puntaje, ICollection *pun, ICollection* com) {
    this->titulo = titulo;
    this->poster = poster;
    this->sipnosis = sipnosis;
    this->cantPuntuaciones = cant;
    this->puntaje = puntaje;
    this->puntajes = pun;
    this->comentarios = com;
}


string DtPelicula::getTitulo() const{
    return this->titulo;
}
string DtPelicula::getPoster()const{
    return  this->poster;
}
string DtPelicula::getSipnosis() const{
    return this->sipnosis;
}
float DtPelicula::getPuntaje() const{
    return this->puntaje;
}
int DtPelicula::getCantPuntuaciones()const{
    return this->cantPuntuaciones;
}

ICollection* DtPelicula::getPuntajes() const {
    return this->puntajes;
}

ICollection* DtPelicula::getComentarios()const{
    return this->comentarios;
}

DtPelicula::~DtPelicula(){

}