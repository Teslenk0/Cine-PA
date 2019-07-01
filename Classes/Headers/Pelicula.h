//
// Created by tesla on 13/06/19.
//

#ifndef LAB_PA_PELICULA_H
#define LAB_PA_PELICULA_H

#include <iostream>
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Datatypes/Headers/DtPelicula.h"
#include "../../Interfaces/Headers/ICollection.h"
#include "../../Collections/Headers/List.h"
#include "../../Datatypes/Headers/DtUsuario.h"
#include "Comentario.h"
#include "Puntaje.h"
using namespace std;

class Pelicula : public ICollectible{
    private:
        string titulo;
        string poster;
        string sipnosis;
        ICollection* puntajes;
        //ICollection* comentarios;
        float puntaje;
        int cantPuntuaciones;
    public:
        Pelicula();
        Pelicula(string,string,string);
        Pelicula(DtPelicula*);

        string getTitulo()const;
        string getPoster()const;
        string getSipnosis()const;
        float getPuntaje()const;
        DtPelicula *getPelicula()const;
        int getCantPuntuaciones()const;
        ICollection* getPuntajes()const;
        ICollection* getComentarios()const;
        void calculoPromedio();

        int buscoPuntaje(DtUsuario*);

        void setTitulo(string);
        void setPoster(string);
        void setSipnosis(string);
        void setPuntaje(float);

        void agregoPuntuacion(DtUsuario*,int);

        ~Pelicula();
};


#endif //LAB_PA_PELICULA_H
