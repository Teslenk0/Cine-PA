//
// Created by tesla on 16/06/19.
//
#include "../Headers/Reserva.h"

Reserva::Reserva(){

}

Reserva::Reserva(int cant, float costo){
    this->cantAsientos = cant;
    this->costo = costo;
}

int Reserva::getCantAsientos() const{
    return this->cantAsientos;
}

float Reserva::getCosto() const{
    return this->costo;
}

void Reserva::setCantAsientos(int cantSeats){
    this->cantAsientos=cantSeats;
}

void Reserva::setCosto(float price) {
    this->costo=price;
}

Reserva::~Reserva(){

}
