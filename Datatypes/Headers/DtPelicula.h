//
// Created by tesla on 13/06/19.
//

#ifndef LAB_PA_DTPELICULA_H
#define LAB_PA_DTPELICULA_H

#include <iostream>
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/ICollection.h"
#include "../../Collections/Headers/List.h"

using namespace std;

class DtPelicula : public ICollectible{
    private:
        string titulo;
        string poster;
        string sipnosis;
        float puntaje;
        int cantPuntuaciones; //se setea a 0 en el constructor
        ICollection* puntajes;
        ICollection* comentarios;
    public:
        DtPelicula();
        DtPelicula(string, string, string,int,float);
        DtPelicula(string, string, string,int,float,ICollection*);
        DtPelicula(string, string, string,int,float,ICollection*,ICollection*);
        string getTitulo() const;
        string getPoster()const;
        string getSipnosis() const;
        ICollection* getPuntajes()const;
        ICollection* getComentarios()const;
        float getPuntaje() const;
        int getCantPuntuaciones()const;

        ~DtPelicula();
};


#endif //LAB_PA_DTPELICULA_H
