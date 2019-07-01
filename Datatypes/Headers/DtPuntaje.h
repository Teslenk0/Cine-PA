//
// Created by tesla on 30/06/19.
//

#ifndef PA_POSTA_DTPUNTAJE_H
#define PA_POSTA_DTPUNTAJE_H

#include "DtUsuario.h"
#include "../../Interfaces/Headers/ICollectible.h"

class DtPuntaje : public ICollectible{
    private:
        int puntaje;
        DtUsuario* user;

    public:
        DtPuntaje();
        DtPuntaje(int,DtUsuario*);

        int getPuntaje()const;
        DtUsuario* getUsuario()const;

        ~DtPuntaje();
};


#endif //PA_POSTA_DTPUNTAJE_H
