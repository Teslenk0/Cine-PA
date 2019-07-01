//
// Created by tesla on 16/06/19.
//

#ifndef PA_POSTA_DTFUNCION_H
#define PA_POSTA_DTFUNCION_H

#include "DtFecha.h"
#include "DtPelicula.h"
#include "DtSala.h"

class DtFuncion : public ICollectible {
    private:
        int numero;
        DtSala* sala;
        DtPelicula* peli;
        DtFecha *fecha;
    public:
        DtFuncion();
        DtFuncion(int,DtFecha*,DtPelicula*,DtSala*);

        int getNro() const;
        DtSala* getSala() const;
        DtFecha* getFecha() const;
        DtPelicula* getPelicula()const;

        ~DtFuncion();
};


#endif //PA_POSTA_DTFUNCION_H
