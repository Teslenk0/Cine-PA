//
// Created by tesla on 30/06/19.
//

#ifndef PA_POSTA_PUNTAJE_H
#define PA_POSTA_PUNTAJE_H


#include "../../Datatypes/Headers/DtUsuario.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Datatypes/Headers/DtPuntaje.h"

class Puntaje : public ICollectible{
    private:
        int puntaje;
        DtUsuario* user;

    public:
        Puntaje();
        Puntaje(int,DtUsuario*);

        int getPuntaje()const;
        DtUsuario* getUsuario()const;
        DtPuntaje* getPuntajeCompleto();

        void setPuntaje(int);
        void setUsuario(DtUsuario*);

        ~Puntaje();
};


#endif //PA_POSTA_PUNTAJE_H
