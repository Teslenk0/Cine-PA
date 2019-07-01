//
// Created by tesla on 28/06/19.
//

#ifndef PA_POSTA_DTUSUARIO_H
#define PA_POSTA_DTUSUARIO_H

#include <iostream>

#include "../../Interfaces/Headers/ICollectible.h"
using namespace std;

class DtUsuario : public ICollectible{
    private:
        string nick;
        string pass;
        string imagen;
        bool admin=false;
    public:
        //constructores
        DtUsuario();
        DtUsuario(string,string,string,bool);
        //-------------------------
        string getNick() const;
        string getImagen() const;
        string getPass() const;
        bool isAdmin();

        //Destructor
        ~DtUsuario();
};


#endif //PA_POSTA_DTUSUARIO_H
