//
// Created by tesla on 16/06/19.
//

//PARA EVALUAR
/*
#ifndef PA_POSTA_CONTROLADORSESION_H
#define PA_POSTA_CONTROLADORSESION_H

#include "Sistema.h"
//levantamos un controlador sesion

class Sesion : public Sistema {
    protected:
        static Sesion* instance;
        Sesion();
    public:
        Sesion(const Sesion*)= delete; //no permito que se llame el constructor por copia
        Sesion*operator=(const Sesion*)=delete; //no permito que se asigne otra instancia a esta instancia

        static Sesion* getInstance();
        ~Sesion();
};

class SesionAdmin : public Sesion{
    protected:
        static SesionAdmin* instance;
        SesionAdmin();
    public:
        SesionAdmin(const SesionAdmin*)= delete; //no permito que se llame el constructor por copia
        SesionAdmin*operator=(const SesionAdmin*)=delete; //no permito que se asigne otra instancia a esta instancia

        static SesionAdmin* getInstance();
        ~SesionAdmin();
};


#endif //PA_POSTA_CONTROLADORSESION_H
*/