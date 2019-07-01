//
// Created by tesla on 13/06/19.
//

#ifndef LAB_PA_USUARIO_H
#define LAB_PA_USUARIO_H

#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Datatypes/Headers/DtUsuario.h"

using namespace std;

class Usuario : public ICollectible{
    private:
        string nick;
        string pass;
        string imagen;
        bool admin=false;
    public:
        //constructores
        Usuario();
        Usuario(string,string,string,bool);
        Usuario(DtUsuario*);
        //-------------------------
        bool validarPass(string password);
        string getNick() const;
        string getImagen() const;
        string getPass() const;
        DtUsuario* getUsuario()const;
        bool isAdmin();

        void setNick(string);
        void setPass(string);
        void setImagen(string imagen);

        //Destructor
        ~Usuario();
};


#endif //LAB_PA_USUARIO_H
