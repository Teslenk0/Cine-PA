//
// Created by tesla on 16/06/19.
//

#ifndef PA_POSTA_SALA_H
#define PA_POSTA_SALA_H
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Datatypes/Headers/DtSala.h"

class Sala : public ICollectible{
    private:
        int id, cantAsientos;
    public:
        Sala();
        Sala(int,int);
        Sala(DtSala*);

        DtSala* getSala() const;

        int getID() const;
        int getCantAsientos()const;

        void setID(int);
        void setCantAsientos(int);

        ~Sala();
};



#endif //PA_POSTA_SALA_H
