//
// Created by tesla on 16/06/19.
//

#include "../Headers/PagoDebito.h"

PagoDebito::PagoDebito() {

}

PagoDebito::PagoDebito(int cantAsientos, float costo, string bank):Reserva(cantAsientos,costo){
    this->Banco=bank;
}

float PagoDebito::getCosto() const {
    return this->costo;
}

string PagoDebito::getBanco() const {
    return this->Banco;
}

void PagoDebito::setBanco(string bank) {
    this->Banco=bank;
}

PagoDebito::~PagoDebito() {
    
}