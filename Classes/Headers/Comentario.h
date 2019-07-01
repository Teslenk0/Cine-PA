//
// Created by tesla on 30/06/19.
//

#ifndef PA_POSTA_COMENTARIO_H
#define PA_POSTA_COMENTARIO_H

#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Datatypes/Headers/DtUsuario.h"
#include "../../Interfaces/Headers/ICollection.h"
#include "../../Collections/Headers/List.h"
#include "../../Datatypes/Headers/DtComentario.h"

class Comentario : public ICollectible{
    public:
        string coment;
        DtUsuario* usuario;
        ICollection* respuestas;
    private:
        Comentario();
        Comentario(string com,DtUsuario* user);
        Comentario(DtComentario*);

        string getComentario()const ;
        DtComentario* getComentCompleto()const;
        DtUsuario* getUsuario()const ;
        ICollection* getRespuestas()const;

        void setComentario(string);
        void setUsuario(DtUsuario*);

        ~Comentario();

};


#endif //PA_POSTA_COMENTARIO_H
