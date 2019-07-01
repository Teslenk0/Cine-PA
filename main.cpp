#include <iostream>
#include "Classes/Headers/Sistema.h"
#include "Classes/Headers/FuncionesAux.h"

using namespace std;

//contrasena usuario root -> 123456

int main(){
    Sistema* i=Sistema::getInstance(); //guardo la unica instancia de sistema para trabajar con ella
    FuncionesAux* f=new FuncionesAux;
    f->menuPrincipal();
    while(f->ingresoOpcion()!=0){
        try {
            switch (f->getOpcion()){
                case 1:{
                    f->menuInicioSesion();
                    if(i->validarSesion(f->getNick(),f->getPass())){
                        if(i->isSesionAdmin(f->getNick())){ //iniciar sesion como administrador
                            f->menuADM();
                            while(f->ingresoOpcion()!=0) {
                                try {
                                    switch (f->getOpcion()) {
                                        case 1: {
                                            i->altaCine(f->agregoCine()); //PRONTO
                                            break;
                                        }
                                        case 2: {
                                            system("clear");
                                            cout<<"======= ELIMINAR CINE ========="<<endl;
                                            DtCine* cine=f->seleccionoCine(i->listarCines());
                                            i->eliminoCine(cine);
                                            break;
                                        }
                                        case 3:{
                                            system("clear");
                                            f->muestroCines(i->listarCines()); //PRONTO
                                            cout<<"Presione cualquier tecla para continuar...";
                                            cin.get();
                                            cin.get();
                                            break;
                                        }
                                        case 4:{
                                            system("clear");
                                            DtPelicula* p=f->agregoPeli();
                                            if(!i->existePeli(p->getTitulo())){    //PRONTO
                                                i->altaPelicula(p);
                                            }else{
                                                throw invalid_argument("La pelicula ya existe");
                                            }
                                            break;
                                        }
                                        case 5:{
                                            system("clear");
                                            cout<<"======= ELIMINAR PELICULA ========="<<endl;
                                            DtPelicula* peli=f->seleccionoPeli(i->listarPeliculas());
                                            i->borrarPelicula(peli);
                                            break;
                                        }
                                        case 6:{
                                            system("clear");
                                            f->muestroPeliculas(i->listarPeliculas());  //PRONTO
                                            cout<<"Presione cualquier tecla para continuar...";
                                            cin.get();
                                            cin.get();
                                            break;
                                        }
                                        case 7:{
                                            system("clear");
                                            cout<<"=======ALTA FUNCION========="<<endl;
                                            DtPelicula* peli=f->seleccionoPeli(i->listarPeliculas());
                                            DtCine* cine=f->seleccionoCine(i->listarCines());
                                            DtSala* sala=f->seleccionoSala(cine);                   //PRONTO
                                            DtFecha* fecha=f->cargoFecha();
                                            i->altaFuncion(cine,f->agregoFuncion(peli,sala,fecha));
                                            cout<<"Presione cualquier tecla para continuar...";
                                            cin.get();
                                            cin.get();
                                            break;
                                        }
                                        default: {
                                            throw invalid_argument("La opcion ingresada no es correcta");
                                            break;
                                        }
                                    }
                                }catch(exception &e){
                                    cout<<"ERROR: "<<e.what()<<endl<<"Pulse cualquier tecla para continuar..."<<endl;
                                    cin.get();
                                    cin.get();
                                }
                                f->menuADM();
                            }
                            i->cerrarSesion();
                        }else{
                            f->menuUsuario();
                            while(f->ingresoOpcion()!=0) {
                                try {
                                    switch (f->getOpcion()) {
                                        case 1: {
                                            system("clear");
                                            DtPelicula* peli=f->seleccionoPeli(i->listarPeliculas());       //PRONTO
                                            cout<<"Desea ver informacion adicional(y/n): ";
                                            char adc;
                                            cin>>adc;
                                            if(adc=='y'||adc=='Y'){
                                                DtCine* cine=f->seleccionoCine(i->peliculaxCines(peli->getTitulo()));
                                                f->verFuncionesPosteriores(cine,peli->getTitulo());
                                                cout<<"Presione cualquier tecla para continuar...";
                                                cin.get();
                                                cin.get();
                                            }
                                            break;
                                        }
                                        case 2:{
                                            system("clear");
                                            cout<<"==============================================="<<endl;      //PRONTO
                                            cout<<"============  SISTEMA DE RESERVAS  ============"<<endl;
                                            cout<<"-----------------------------------------------"<<endl;
                                            //CREAR RESERVA
                                            DtPelicula* peli=f->seleccionoPeli(i->listarPeliculas());
                                            cout<<"Desea ver informacion adicional(y/n): ";
                                            char adc;
                                            cin>>adc;
                                            if(adc=='y'||adc=='Y'){
                                                DtCine* cine=f->seleccionoCine(i->peliculaxCines(peli->getTitulo()));
                                                f->verFuncionesPosteriores(cine,peli->getTitulo());
                                                cout<<endl<<"Funcion: ";
                                                int nro;
                                                cin>>nro; //nro de funcion
                                                cout<<"Cantidad de asientos: ";
                                                int cant;
                                                cin>>cant; //cantidad de asientos
                                                switch (f->menuPago()){
                                                    case 1:{
                                                        cin.get();
                                                        string bank;
                                                        cout<<"Banco: ";
                                                        getline(cin,bank);
                                                        int costo=f->calculoPrecioDebito(cant);
                                                        cout<<"Precio: "<<costo<<endl;
                                                        cout<<"Confirma(y/n): ";
                                                        char confirma;
                                                        cin>>confirma;
                                                        if(confirma){
                                                            i->crearReservaDebito(cine,nro,costo,cant,bank);
                                                        }
                                                        break;
                                                    }
                                                    case 2:{
                                                        cin.get();
                                                        string financiera;
                                                        cout<<"Financiera: ";
                                                        getline(cin,financiera);
                                                        int costo=f->calculoPrecioCredito(cant,financiera);
                                                        cout<<"Precio: "<<costo<<endl;
                                                        cout<<"Confirma(y/n): ";
                                                        char confirma;
                                                        cin>>confirma;
                                                        if(confirma){
                                                            i->crearReservaCredito(cine,nro,costo,cant,financiera);
                                                        }
                                                        break;
                                                        break;
                                                    }
                                                    default:{
                                                        throw invalid_argument("La forma de pago no es correcta");
                                                    }
                                                }
                                                cout<<"Presione cualquier tecla para continuar...";
                                                cin.get();
                                                cin.get();
                                            }
                                            break;
                                        }
                                        case 3: {
                                            system("clear");
                                            DtPelicula *peli = f->puntuoPeli(i->listarPeliculas());
                                            cout<<"Puntaje(1->10): ";
                                            int points;
                                            cin>>points;
                                            if(points>0 && points<11) {
                                                int puntuacionAnterior=i->buscoPuntaje(peli,f->getNick());
                                                if(puntuacionAnterior==0) {
                                                    i->puntuarPelicula(peli, f->getNick(),points);//le paso la pelicula y el usuario
                                                    cout<<"Puntaje ingresado correctamente"<<endl;
                                                }else{
                                                    cout<<"Ya ha puntuado "<<peli->getTitulo()<<" con "<<puntuacionAnterior<<" puntos"<<endl;
                                                }
                                                cout<<"====================================="<<endl;
                                                cout<<"Presione cualquier tecla para continuar..."<<endl;
                                                cin.get();
                                                cin.get();
                                            }else{
                                                throw invalid_argument("El puntaje ingresado es incorrecto");
                                            }
                                            break;
                                        }
                                        case 4:{
                                            system("clear");
                                            DtPelicula *peli = f->seleccionoPeli(i->listarPeliculas());
                                            f->muestroPuntajes(i->listarPuntajes(peli));
                                            cout<<"====================================="<<endl;
                                            cout<<"Presione cualquier tecla para continuar..."<<endl;
                                            cin.get();
                                            cin.get();
                                            break;
                                        }
                                        case 5:{
                                            system("clear");
                                            cout<<"NO IMPLEMENTADO";
                                            //DtPelicula *peli = f->comentoPeli(i->listarPeliculas());
                                            //f->muestroComentarios(i->listarComentarios(peli));
                                            cout<<"====================================="<<endl;
                                            cout<<"Presione cualquier tecla para continuar..."<<endl;
                                            cin.get();
                                            cin.get();
                                            break;
                                        }
                                        default: {
                                            throw invalid_argument("La opcion ingresada no es correcta");
                                            break;
                                        }
                                    }
                                }catch(exception &e){
                                    cout<<"ERROR: "<<e.what()<<endl<<"Pulse cualquier tecla para continuar..."<<endl;
                                    cin.get();
                                    cin.get();
                                }
                                f->menuUsuario();
                            }
                            i->cerrarSesion();
                        }
                    }else{
                        if(i->existeUsuario(f->getNick())){
                            throw invalid_argument("La contrasena es incorrecta");
                        }else{
                            throw invalid_argument("El usuario no existe");
                        }
                    }

                    break;
                }
                case 2:{
                    f->menuRegistrarse(); //FUNCIONANDO
                    if(i->registroUsuario(new DtUsuario(f->getNick(),f->getPass(),f->getImg(),f->getAdm()))){
                        cout<<endl<<"Usuario registrado correctamente, presione cualquier tecla para continuar...";
                        cin.get();
                        cin.get();
                    }else{
                        throw invalid_argument("El usuario ya existe");
                    }
                    break;
                }
                case 3:{
                    system("clear"); //para verificar que se agreguen correctamente
//                    i->listarUsuarios();
                    cin.get();
                    cin.get();
                    break;
                }
                default:
                    throw invalid_argument("La opcion ingresada no es correcta");
                    break;
            }
        }catch(exception &e){
            cout<<"ERROR: "<<e.what()<<endl<<"Pulse cualquier tecla para continuar..."<<endl;
            cin.get();
            cin.get();
        }
        f->menuPrincipal();
    }
    delete i;   //elimino el sistema
    delete f;   //elimino las funciones
    return 0;
}