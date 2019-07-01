//
// Created by tesla on 30/06/19.
//

#ifndef PA_POSTA_DTCOMENTARIO_H
#define PA_POSTA_DTCOMENTARIO_H
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Datatypes/Headers/DtUsuario.h"
#include "../../Interfaces/Headers/ICollection.h"
#include "../../Collections/Headers/List.h"

class DtComentario {
    private:
        string coment;
        DtUsuario* usuario;
        ICollection* respuestas;
    public:
        DtComentario();
        DtComentario(string com,DtUsuario* user);
        DtComentario(string com,DtUsuario* user,ICollection* resp);

        string getComentario()const ;
        DtUsuario* getUsuario()const ;
        ICollection* getRespuestas()const;

        void setComentario(string);
        void setUsuario(DtUsuario*);

        ~DtComentario();

};


#endif //PA_POSTA_DTCOMENTARIO_H
