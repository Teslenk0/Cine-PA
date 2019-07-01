//
// Created by tesla on 13/06/19.
//

#ifndef LAB_PA_DTCINE_H
#define LAB_PA_DTCINE_H

#include "DtDireccion.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/ICollection.h"
#include "../../Collections/Headers/List.h"
#include "DtSala.h"
#include "DtFecha.h"
#include "DtFuncion.h"

class DtCine : public ICollectible {
    private:
        int id;
        DtDireccion* direccion;
        ICollection* salas;
        ICollection* funciones;
        ICollection* peliculas;
        int cantSalas;
    public:
        DtCine();
        DtCine(int,DtDireccion*);
        DtCine(int,DtDireccion*,ICollection*,ICollection*,ICollection*);
        int getID()const;
        DtDireccion *getDireccion()const;
        ICollection* getSalas()const;
        ICollection* getFunciones()const;
        ICollection* getPelis()const;
        ICollection* getFuncionesPosterioresAhora(DtFecha*,string title);
        void agregoSala(int);
        ~DtCine();
};


#endif //LAB_PA_DTCINE_H
