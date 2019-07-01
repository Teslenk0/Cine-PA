//
// Created by tesla on 16/06/19.
//

#include "../Headers/PagoCredito.h"

PagoCredito::PagoCredito(){

}
PagoCredito::PagoCredito(int cantSeats, float amount, string finan):Reserva(cantSeats,amount){
    this->Financiera=finan;
}

float PagoCredito::getCosto() const{
    return this->costo;
}
string PagoCredito::getFinanciera()const{
    return this->Financiera;
}

void PagoCredito::setFinanciera(string finan){
    this->Financiera=finan;
}

PagoCredito::~PagoCredito(){

}