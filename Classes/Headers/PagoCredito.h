//
// Created by tesla on 16/06/19.
//

#ifndef PA_POSTA_PAGOCREDITO_H
#define PA_POSTA_PAGOCREDITO_H

#include <iostream>
#include "Reserva.h"
using namespace std;

class PagoCredito : public Reserva {
    private:
        string Financiera;
    public:
        PagoCredito();
        PagoCredito(int, float, string);

        float getCosto() const;
        string getFinanciera()const;

        void setFinanciera(string);

        ~PagoCredito();
};


#endif //PA_POSTA_PAGOCREDITO_H
