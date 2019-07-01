//
// Created by brahian on 10/06/19.
//

#ifndef LAB_PA_DTFECHA_H
#define LAB_PA_DTFECHA_H

#include "../../Interfaces/Headers/ICollectible.h"

class DtFecha : public ICollectible{
    private:
        int dia;
        int mes;
        int anio;
        int hora;
        int minuto;
    public:
        DtFecha();
        DtFecha(int,int,int,int,int);
        int getDia()const;
        int getMes()const;
        int getAnio()const;
        int getHora()const;
        int getMinuto()const;
        bool operator<(const DtFecha&)const;
        ~DtFecha();
};


#endif //LAB_PA_DTFECHA_H
