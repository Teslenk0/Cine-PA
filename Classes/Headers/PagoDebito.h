//
// Created by tesla on 16/06/19.
//

#ifndef PA_POSTA_PAGODEBITO_H
#define PA_POSTA_PAGODEBITO_H

#include "Reserva.h"
#include <iostream>

using namespace std;

class PagoDebito : public Reserva{
    private:
        string Banco;
    public:
        PagoDebito();
        PagoDebito(int, float, string);

        float getCosto() const;
        string getBanco()const;

        void setBanco(string);

        ~PagoDebito();
};


#endif //PA_POSTA_PAGODEBITO_H
