//
// Created by tesla on 16/06/19.
//

#ifndef PA_POSTA_RESERVA_H
#define PA_POSTA_RESERVA_H

#include "../../Interfaces/Headers/ICollectible.h"

class Reserva : public ICollectible{
    protected:
        int cantAsientos;
        float costo;
    public:
        Reserva();
        Reserva(int, float);

        int getCantAsientos() const;
        virtual float getCosto() const;

        void setCantAsientos(int);
        void setCosto(float);

        ~Reserva();
};


#endif //PA_POSTA_RESERVA_H
