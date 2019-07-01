//
// Created by tesla on 14/06/19.
//

#ifndef LAB_PA_CINE_H
#define LAB_PA_CINE_H

#include <iostream>
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Datatypes/Headers/DtCine.h"
#include "../../Datatypes/Headers/DtDireccion.h"
#include "Sala.h"
#include "Pelicula.h"
#include "../../Datatypes/Headers/DtFecha.h"
#include "../../StringKey.h"
#include "Funcion.h"
using namespace std;

class Cine : public ICollectible{
    private:
        int nro;
        int cantFunciones;
        DtDireccion *direccion;
        IDictionary *salas;
        IDictionary *funciones;
        IDictionary *pelis;
    public:
        Cine();
        Cine(int, DtDireccion*);
        Cine(DtCine*);

        DtCine *getCine() const;

        int getNro() const;
        DtDireccion *getDireccion() const;
        int getCantSalas()const;

        void listarSalas();
        void agregoFunciones(DtFuncion*);
        void agregarReserva(int,float,int,bool,string);
        bool existePeli(string title); //si existe devuelve el numero de cine
        void setNro(int);
        void setDireccion(DtDireccion *);

        void agregoSala(int);

        ~Cine();
};


#endif //LAB_PA_CINE_H
