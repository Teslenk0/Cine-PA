//
// Created by tesla on 13/06/19.
//
#include "../Headers/Pelicula.h"

Pelicula::Pelicula() {

}

Pelicula::Pelicula(string titulo, string poster, string sipnosis) {
    this->poster=poster;
    this->titulo=titulo;
    this->sipnosis=sipnosis;
    this->puntaje=0;
    this->cantPuntuaciones=0;
    this->puntajes=new List();
    //this->comentarios=new List();
}

Pelicula::Pelicula(DtPelicula *peli) {
    this->titulo=peli->getTitulo();
    this->poster=peli->getPoster();
    this->sipnosis=peli->getSipnosis();
    this->puntaje=peli->getPuntaje();
    this->cantPuntuaciones=peli->getCantPuntuaciones();
    this->puntajes=peli->getPuntajes();
    //this->comentarios=peli->getComentarios();
}

string Pelicula::getTitulo() const {
    return this->titulo;
}

string Pelicula::getPoster() const {
    return this->poster;
}

float Pelicula::getPuntaje() const {
    return this->puntaje;
}

string Pelicula::getSipnosis() const {
    return this->sipnosis;
}

int Pelicula::getCantPuntuaciones()const{
    return this->cantPuntuaciones;
}

//ACORDARSE DE CAMBIAR EL RETORNO JUNTO CON LOS COMENTARIOS
DtPelicula* Pelicula::getPelicula() const {
    return new DtPelicula(this->titulo,this->poster, this->sipnosis,this->cantPuntuaciones,this->puntaje,this->puntajes);
}

ICollection* Pelicula::getPuntajes() const {
    ICollection* auxCol=new List();
    IIterator* it=puntajes->getIterator();
    while (it->hasCurrent()){
        Puntaje* punt= dynamic_cast<Puntaje*>(it->getCurrent());
        auxCol->add(punt->getPuntajeCompleto());
        it->next();
    }
    delete it;
    return auxCol;
}

ICollection* Pelicula::getComentarios() const {
    /*ICollection* auxDT=new List();
    IIterator* it=this->comentarios->getIterator();
    while(it->hasCurrent()){
        Comentario* com= dynamic_cast<Comentario*>(it->getCurrent());

        it->next();
    }

    return auxDT;*/
    return nullptr;
}

void Pelicula::setTitulo(string title) {
    this->titulo=title;
}

void Pelicula::setPoster(string post) {
    this->poster=post;
}

void Pelicula::setPuntaje(float points) {
    this->puntaje=points;
}

void Pelicula::setSipnosis(string sip) {
    this->sipnosis=sip;
}

void Pelicula::agregoPuntuacion(DtUsuario* u,int puntaje) {
    Puntaje* p=new Puntaje(puntaje,u);
    puntajes->add(p);
    this->cantPuntuaciones+=1;
    this->calculoPromedio();
}

void Pelicula::calculoPromedio(){
    IIterator* it=puntajes->getIterator();
    int suma=0;
    while(it->hasCurrent()){
        Puntaje* p= dynamic_cast<Puntaje*>(it->getCurrent());
        suma+=p->getPuntaje();
        it->next();
    }
    delete it;
    this->cantPuntuaciones=suma/puntajes->getSize();
}

Pelicula::~Pelicula() {
    IIterator* it=puntajes->getIterator();
    while (it->hasCurrent()) {
        Puntaje* temp = dynamic_cast<Puntaje*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete puntajes;
}

int Pelicula::buscoPuntaje(DtUsuario *u) {
    IIterator* it=puntajes->getIterator();
    while(it->hasCurrent()){
        Puntaje* p= dynamic_cast<Puntaje*>(it->getCurrent());
        if(p->getUsuario()->getNick()==u->getNick()){
            return p->getPuntaje();
        }
        it->next();
    }
    delete it;
    return 0;
}









