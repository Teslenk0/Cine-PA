//
// Created by tesla on 16/06/19.
//

#ifndef PA_POSTA_SISTEMA_H
#define PA_POSTA_SISTEMA_H

#include <iostream>
#include <ctime>
#include "../../Interfaces/Headers/IDictionary.h"
#include "../Headers/FuncionesAux.h"
#include "../../Datatypes/Headers/DtUsuario.h"
using namespace std;


//definimos Sistema  como singleton
// https://www.youtube.com/watch?v=1AIoJ9rPi80


class Sistema {
    private:
        int cantPelis=0;
        int cantCines=0;
        bool sesionIniciada=false;
        void precargoRoot();
        static Sistema* instance;
        Sistema();
        IDictionary* usuarios;
        IDictionary* peliculas;
        IDictionary* cines;
        FuncionesAux* functions;
    public:
        Sistema(const Sistema*)= delete; //no permito que se llame el constructor por copia
        Sistema*operator=(const Sistema*)=delete; //no permito que se asigne otra instancia a esta instancia
        ~Sistema();

        static Sistema* getInstance();

        //metodos para usuarios
        bool registroUsuario(DtUsuario*);
        void iniciarSesion();
        void cerrarSesion();
        bool validarSesion(string user, string password);
        bool existeUsuario(string);
        bool isSesionAdmin(string);

        //metodos para peliculas
        bool existePeli(string);
        void altaPelicula(DtPelicula*);
        ICollection* listarPeliculas();
        ICollection* listarComentarios(DtPelicula* p);
        ICollection* listarPuntajes(DtPelicula* p);
        void puntuarPelicula(DtPelicula*,string,int);
        int buscoPuntaje(DtPelicula*, string);
        void borrarPelicula(DtPelicula*);


        //metodos para reserva
        void crearReservaCredito(DtCine*,int,float,int,string);
        void crearReservaDebito(DtCine*,int,float,int,string);

        //metodos para funcion
        void altaFuncion(DtCine*,DtFuncion*);

        //metodos para cines
        void altaCine(DtCine*);
        void eliminoCine(DtCine*);
        ICollection* listarCines();
        ICollection* peliculaxCines(string title);
};


#endif //PA_POSTA_SISTEMA_H
