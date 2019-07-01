//
// Created by brahian on 10/06/19.
//

#ifndef LAB_PA_DTDIRECCION_H
#define LAB_PA_DTDIRECCION_H
#include <iostream>
using namespace std;

class DtDireccion {
    private:
        string calle;
        string ciudad;
        int nro;
        string departamento;
    public:
        DtDireccion();
        DtDireccion(string,string,int,string);
        string getCalle()const;
        string getCiudad()const;
        int getNro()const;
        string getDepartamento()const;
        ~DtDireccion();
};


#endif //LAB_PA_DTDIRECCION_H
