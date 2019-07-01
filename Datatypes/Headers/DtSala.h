//
// Created by tesla on 16/06/19.
//

#ifndef PA_POSTA_DTSALA_H
#define PA_POSTA_DTSALA_H



#include "../../Interfaces/Headers/ICollectible.h"

class DtSala : public ICollectible {
    private:
        int id, cantAsientos;
    public:
        DtSala();
        DtSala(int,int);


        int getID() const;
        int getCantAsientos()const;

        ~DtSala();
};



#endif //PA_POSTA_DTSALA_H
