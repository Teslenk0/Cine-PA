//
// Created by brahian on 10/06/19.
//

#include "../Headers/DtDireccion.h"

DtDireccion::DtDireccion(){

}

DtDireccion::DtDireccion(string street,string city,int number,string department){
    this->calle=street;
    this->ciudad=city;
    this->nro=number;
    this->departamento=department;
}

string DtDireccion::getCalle()const{
    return this->calle;
}

string DtDireccion::getCiudad()const{
    return this->ciudad;
}
int DtDireccion::getNro()const{
    return this->nro;
}
string DtDireccion::getDepartamento()const{
    return this->departamento;
}
DtDireccion::~DtDireccion(){

}