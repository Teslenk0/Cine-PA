//
// Created by tesla on 16/06/19.
//

#ifndef PA_POSTA_FUNCIONESAUX_H
#define PA_POSTA_FUNCIONESAUX_H

#include <iostream>
#include "../../Datatypes/Headers/DtDireccion.h"
#include "../../Datatypes/Headers/DtFecha.h"
#include "../../Datatypes/Headers/DtCine.h"
#include "../../Datatypes/Headers/DtPelicula.h"
#include "../../Datatypes/Headers/DtFuncion.h"
#include "../../Datatypes/Headers/DtPuntaje.h"

using namespace std;

class FuncionesAux {
    private:
        int opcion;
        string nick;
        string pass;
        string imagen;
        const static int claveAdmin=777;
        const static int precioReserva=320;
        bool isAdmin=false;
        int cantCines;
        int cantPelis;
        int cantFunciones;
    public:
        FuncionesAux();
        void menuPrincipal()const;
        int menuPago();
        void muestroCines(ICollection* cines)const;
        void menuInicioSesion();
        void menuRegistrarse();
        void muestroPeliculas(ICollection*)const;
        void muestroSalas(ICollection*)const;
        void verFuncionesPosteriores(DtCine*,string);
        float calculoPrecioDebito(int);
        float calculoPrecioCredito(int,string);
        DtPelicula* puntuoPeli(ICollection* peliculas);
        int getOpcion()const;
        DtCine* agregoCine();
        DtCine* seleccionoCine(ICollection*);
        DtPelicula* agregoPeli();
        DtPelicula* seleccionoPeli(ICollection*);
        DtPelicula* comentoPeli(ICollection*);
        DtSala* seleccionoSala(DtCine*);
        DtFuncion* agregoFuncion(DtPelicula* p, DtSala* s, DtFecha* f);
        void muestroComentarios(ICollection*);
        void muestroPuntajes(ICollection*);
        string getNick()const;
        string getPass()const;
        string getImg()const;
        bool getAdm()const;
        int ingresoOpcion();
        void setNick(string);
        void setPass(string);
        void menuADM()const;
        void menuUsuario();
        DtDireccion* cargoDireccion();
        DtFecha* cargoFecha();
        DtFecha* fechaActual();
        ~FuncionesAux();
};


#endif //PA_POSTA_FUNCIONESAUX_H
