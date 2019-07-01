//
// Created by tesla on 16/06/19.
//

#ifndef LAB_PA_FUNCION_H
#define LAB_PA_FUNCION_H
#include "../../Datatypes/Headers/DtFecha.h"
//#include "../../Interfaces/Headers/ICollection.h"
#include "../../Datatypes/Headers/DtFuncion.h"
#include "../../Collections/Headers/OrderedDictionary.h"
#include "PagoCredito.h"
#include "PagoDebito.h"
#include "Sala.h"
#include "Pelicula.h"
#include "../../IntKey.h"
class Funcion : public ICollectible{
    private:
        int numero;
        Sala* sala;
        DtFecha *fecha;
        Pelicula* pelicula;
        IDictionary* reservas;
        int cantReservas;
    public:
        Funcion();
        Funcion(int, Sala*, DtFecha*,Pelicula*);
        Funcion(DtFuncion*);

        DtFuncion* getFuncion() const;

        int getNro() const;
        int getIDsala() const;
        DtFecha* getFecha() const;
        DtSala* getSala()const;
        DtPelicula* getPeli()const;
        string getTituloPeli()const;
        void agregarReserva(float,int,bool,string);
        void setNro(int);
        void setIDsala(int);
        void setFecha(DtFecha*);

        ~Funcion();
};


#endif //LAB_PA_FUNCION_H
