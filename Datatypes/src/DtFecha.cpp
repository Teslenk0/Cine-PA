//
// Created by brahian on 10/06/19.
//

#include "../Headers/DtFecha.h"

DtFecha::DtFecha(){

}

DtFecha::DtFecha(int d,int m,int a,int h,int min){
    this->dia=d;
    this->mes=m;
    this->anio=a;
    this->hora=h;
    this->minuto=min;
}

int DtFecha::getDia()const{
    return this->dia;
}

int DtFecha::getMes()const{
    return this->mes;
}

int DtFecha::getAnio()const{
    return this->anio;
}

int DtFecha::getHora()const{
    return this->hora;
}

int DtFecha::getMinuto()const{
    return this->minuto;
}

bool DtFecha::operator<(const DtFecha& fechaB)const{
    if(this->anio < fechaB.getAnio()){
        return true;
    }else if (this->anio == fechaB.getAnio()){
        if(this->mes < fechaB.getMes()){
            return true;
        }else if (this->mes == fechaB.getMes()){
            if(this->dia < fechaB.getDia())
                return true;
        }   else if(this->dia ==fechaB.getDia()){
                if(this->hora < fechaB.getHora()){
                    return true;
                }else if(this->hora == fechaB.getHora()){
                    if(this->minuto < fechaB.getMinuto()){
                        return true;
                    }
                }
        }
    }
    return false;

}

DtFecha::~DtFecha(){

}