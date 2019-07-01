//
// Created by tesla on 16/06/19.
//

#include "../Headers/FuncionesAux.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

FuncionesAux::FuncionesAux() {
    this->cantCines=0;
    this->cantPelis=0;
    this->cantFunciones=0;
}

void FuncionesAux::menuPrincipal() const{
    system("clear");
    cout<<"=================================="<<endl;
    cout<<"=== Administracion del cine 3D ==="<<endl;
    cout<<"=================================="<<endl;
    cout<<endl;
    cout<<"1-Iniciar Sesion"<<endl;
    cout<<"2-Registrarse"<<endl;
    cout<<"0-Salir"<<endl;
}

int FuncionesAux::menuPago() {
    cout<<"------ FORMAS DE PAGO -------"<<endl;
    cout<<"1-Pago con tarjeta de debito"<<endl;
    cout<<"2-Pago con tarjeta de credito"<<endl;
    switch (this->ingresoOpcion()){
        case 1:{
            return 1;
        }
        case 2:{
            return 2;
        }
        default:{
            return 0;
        }
    }
}

void FuncionesAux::menuInicioSesion(){
    cin.get();
    cout<<"=================================="<<endl;
    cout<<"Usuario: ";
    string user, pass;
    getline(cin,user);
    cout<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Password: ";
    getline(cin,pass);
    this->setNick(user);
    this->setPass(pass);
}
void FuncionesAux::muestroCines(ICollection* cines)const{
    system("clear");                    //PRONTO
    cout<<"====================================="<<endl;
    cout<<"======== LISTADO DE CINES ======="<<endl;
    cout<<"-------------------------------------"<<endl;
    if(!cines->isEmpty()) {
        IIterator *it = cines->getIterator();
        while (it->hasCurrent()) {
            DtCine *aux = dynamic_cast<DtCine *>(it->getCurrent());
            cout << "Numero: " << aux->getID() << endl << "Calle: " << aux->getDireccion()->getCalle() << "->"
                 << aux->getDireccion()->getNro() << endl << "Ciudad: " << aux->getDireccion()->getCiudad() << endl
                 << "Departamento: " << aux->getDireccion()->getDepartamento() << endl << "-----------" << endl;
            it->next();
        }
        delete it;
    }else{
        throw invalid_argument("No hay cines en el sistema");
    }
}

void FuncionesAux::muestroPeliculas(ICollection *pelis) const {
    cout<<"====================================="<<endl;
    cout<<"======== LISTADO DE PELICULAS ======="<<endl;
    cout<<"-------------------------------------"<<endl;
    if(!pelis->isEmpty()) {
        IIterator *it = pelis->getIterator();
        while (it->hasCurrent()) {
            DtPelicula *aux = dynamic_cast<DtPelicula *>(it->getCurrent());
            cout << "Titulo: " << aux->getTitulo() << endl
                 << "Poster: " << aux->getPoster() << endl
                 << "Sipnosis: " << aux->getSipnosis() << endl <<
                 "-------------------------------------" << endl;
            it->next();
        }
        delete it;
    }else{
        throw invalid_argument("No hay peliculas en el sistema");
    }
}

void FuncionesAux::setNick(string user){
    this->nick=user;
}
void FuncionesAux::setPass(string pass) {
    this->pass=pass;
}

int FuncionesAux::getOpcion()const{
    return this->opcion;
}

bool FuncionesAux::getAdm() const {
    return this->isAdmin;
}

string FuncionesAux::getNick() const {
    return this->nick;
}

string FuncionesAux::getPass() const {
    return this->pass;
}

string FuncionesAux::getImg() const {
    return this->imagen;
}
int FuncionesAux::ingresoOpcion(){
    cout<<"=================================="<<endl;
    cout<<"Ingrese la opcion deseada: ";
    cin>>this->opcion;
    return this->opcion;
}

DtPelicula* FuncionesAux::seleccionoPeli(ICollection* pelis){
    string titulo;
    cin.get();
    this->muestroPeliculas(pelis);
    cout << "Pelicula: ";
    getline(cin, titulo);
    IIterator *it = pelis->getIterator();
    while (it->hasCurrent()) {
        DtPelicula *p = dynamic_cast<DtPelicula *>(it->getCurrent());
        if (p->getTitulo() == titulo) {
            return p;
        }
        it->next();
    }
    delete it;
    throw invalid_argument("La pelicula no existe");
}

DtCine* FuncionesAux::seleccionoCine(ICollection* c){
    this->muestroCines(c);
    cout<<"ID Cine: ";
    int cine;
    cin>>cine;
    IIterator* it=c->getIterator();
    while (it->hasCurrent()){
        DtCine* aux= dynamic_cast<DtCine*>(it->getCurrent());
        if(aux->getID()==cine){
            return aux;
        }
        it->next();
    }
    delete it;
    throw invalid_argument("El cine no existe");
}

void FuncionesAux::verFuncionesPosteriores(DtCine* cine,string title) {
    cout<<"-------------FUNCIONES----------------"<<endl;
    ICollection* funcionesPosteriores=cine->getFuncionesPosterioresAhora(this->fechaActual(),title); //LE PASO LA FECHA DE AHORA
    if(!funcionesPosteriores->isEmpty()) {
        IIterator *it = funcionesPosteriores->getIterator();
        while (it->hasCurrent()) {
            DtFuncion *aux = dynamic_cast<DtFuncion *>(it->getCurrent());
            cout << aux->getNro() << "->" <<
                 aux->getFecha()->getDia() << "/" <<
                 aux->getFecha()->getMes() << "/" <<
                 aux->getFecha()->getAnio() << " a las " <<
                 aux->getFecha()->getHora() << ":" <<
                 aux->getFecha()->getMinuto() << endl;
            it->next();
        }
        delete it;
    }else{
        throw invalid_argument("No hay funciones asociadas a ese cine");
    }
}

void FuncionesAux::muestroSalas(ICollection* s)const{
    cout<<"----------------SALAS----------------"<<endl;
    IIterator* it=s->getIterator();
    while (it->hasCurrent()){
        DtSala* aux= dynamic_cast<DtSala*>(it->getCurrent());
        cout<<"Numero: "<<aux->getID()<<"-> Asientos: "<<aux->getCantAsientos()<<endl<<"-------------------------------------"<<endl;
        it->next();
    }
    delete it;
}

DtSala* FuncionesAux::seleccionoSala(DtCine* c){
    this->muestroSalas(c->getSalas());
    cout<<"Sala: ";
    int s;
    cin>>s;
    IIterator* it=c->getSalas()->getIterator();
    while (it->hasCurrent()){
        DtSala* aux= dynamic_cast<DtSala*>(it->getCurrent());
        if(aux->getID()==s){
            return aux;
        }
        it->next();
    }
    delete it;
    throw invalid_argument("La sala no existe");
}

DtFecha* FuncionesAux::cargoFecha(){
    string minuto,hora,dia,mes,anio,fecha;
    cout<<"Fecha(MM:HH:DD:MM:AAAA): ";
    cin>>fecha;
    minuto=fecha.substr(0,2);
    hora=fecha.substr(3,5);
    dia=fecha.substr(6,8);
    mes=fecha.substr(9,11);
    anio=fecha.substr(12,16);
    DtFecha *fec=new DtFecha(stoi(dia),stoi(mes),stoi(anio),stoi(hora),stoi(minuto));
    return fec;
}

DtFuncion* FuncionesAux::agregoFuncion(DtPelicula* p, DtSala* s, DtFecha* f){
    this->cantFunciones+=1;
    return new DtFuncion(this->cantFunciones,f,p,s);
}

FuncionesAux::~FuncionesAux() {

}

void FuncionesAux::menuRegistrarse() {
    system("clear");
    string user,pass,imagen;
    int clave=0;
    char admin;
    cin.get();
    cout<<"=================================="<<endl;
    cout<<"====== REGISTRO  DE  USUARIO ====="<<endl;
    cout<<"=================================="<<endl;
    cout<<"Usuario: ";
    getline(cin,user);
    this->setNick(user);
    cout<<"----------------------------------"<<endl;
    cout<<"Password: ";
    getline(cin,pass);
    this->setPass(pass);
    cout<<"----------------------------------"<<endl;
    cout<<"Imagen: ";
    getline(cin,imagen);
    cout<<"----------------------------------"<<endl;
    cout<<"Admin?(y/n): ";
    cin>>admin;
    if((admin=='y')||(admin=='Y')){
        cout<<"Ingrese clave: ";
        cin>>clave;
        if (clave==this->claveAdmin){
            isAdmin=true;
        }else{
            throw invalid_argument("La clave ADMIN ingresada es incorrecta");
        }
    }
    cout<<"=================================="<<endl;
    cout<<"Procesando registro...";
    cin.get();
    system("sleep 2");
}
void FuncionesAux::menuUsuario() {
    system("clear");
    cout<<"=================================="<<endl;
    cout<<"======       CLIENTE       ======"<<endl;
    cout<<"=================================="<<endl;
    cout<<"1-Ver informacion de pelicula"<<endl;
    cout<<"2-Sistema de Reservas"<<endl;
    cout<<"3-Puntuar pelicula"<<endl;
    cout<<"4-Ver Puntuaciones"<<endl;
    cout<<"5-Comentar pelicula"<<endl;
    cout<<"6-Ver Comentarios"<<endl;
    cout<<"0-Cerrar Sesion"<<endl;
}

void FuncionesAux::menuADM() const {
    system("clear");
    cout<<"=================================="<<endl;
    cout<<"======       SYSADMIN       ======"<<endl;
    cout<<"=================================="<<endl;
    cout<<"1-Agregar cine"<<endl;
    cout<<"2-Eliminar cine"<<endl;
    cout<<"3-Listar cines"<<endl;
    cout<<"4-Agregar pelicula"<<endl;
    cout<<"5-Eliminar pelicula"<<endl;
    cout<<"6-Listar peliculas"<<endl;
    cout<<"7-Agregar funcion"<<endl;
    cout<<"0-Cerrar Sesion"<<endl;
}

DtDireccion* FuncionesAux::cargoDireccion(){
    cin.get();
    string calle,ciudad,departamento;
    int nro;
    cout<<"Ingrese calle: ";
    getline(cin,calle);
    cout<<"Ingrese nro(0 para S/N): ";
    cin>>nro;
    cin.get();
    cout<<"Ingrese ciudad: ";
    getline(cin,ciudad);
    cout<<"Ingrese departamento: ";
    getline(cin,departamento);
    DtDireccion* aux=new DtDireccion(calle,ciudad,nro,departamento);
    return aux;
}

DtFecha* FuncionesAux::fechaActual(){
    int minuto,hora,dia,mes,anio;
    time_t fec = time(NULL);
    struct tm *actual = localtime(&fec);
    minuto=actual->tm_min;
    hora=actual->tm_hour;
    dia=actual->tm_mday;
    mes=actual->tm_mon + 1;
    anio=actual->tm_year + 1900;
    DtFecha* aux=new DtFecha(dia,mes,anio,hora,minuto);
    return aux;
}

DtCine* FuncionesAux::agregoCine() {
    system("clear");
    cout<<"--------------------------------"<<endl;
    cout<<"      DIRECCION DEL CINE        "<<endl;
    cout<<"--------------------------------"<<endl;
    DtDireccion* dir=this->cargoDireccion();
    cout<<"--------------------------------"<<endl;
    DtCine* cinema=new DtCine(this->cantCines+1,dir);
    int cant=0,c=1;
    char seguir='y';
    while(seguir=='y'||seguir=='Y') {
        cout<<"--------------------------------" << endl;
        cout<<"Sala " << c << "-> Asientos: ";
        cin >> cant;
        cinema->agregoSala(cant);
        cout<<"--------------------------------"<<endl;
        cout<<"Desea seguir ingresando salas(y/n): ";
        cin>>seguir;
        c+=1;
    }
    cout<<"=================================="<<endl;
    cout<<"Procesando cine, espere...";
    ungetc('a',stdin);
    this->cantCines+=1;
    cin.get();
    cin.get();
    system("sleep 2");
    return cinema;
}

DtPelicula* FuncionesAux::agregoPeli() {
    system("clear");
    cin.get();
    string title,poster,sipnosis;
    cout<<"=================================="<<endl;
    cout<<"========  ALTA PELICULA  ========="<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Titulo: ";
    getline(cin,title);
    cout << "Poster: ";
    getline(cin, poster);
    cout << "Sipnosis: ";
    getline(cin, sipnosis);
    DtPelicula* peli=new DtPelicula(title,poster,sipnosis,0,0);
    this->cantPelis+=1;
    cout<<"=================================="<<endl;
    ungetc('a',stdin); //para que el sistema aprete "a" porque si saco el cin de abajo se rompe todo
    cout<<"Procesando, espere...";
    cin.get();
    system("sleep 2");

    return peli;
}

float FuncionesAux::calculoPrecioCredito(int seats, string financiera) {
    bool descuento=false;
    string financieras[5]={"Santander","OCA","Scotiabank","ITAU","Microfin"};
    for(int i=0;i++;i<5){
        if(financieras[i]==financiera){
            descuento=true;
        }
    }
    if(descuento){
        cout<<"** DESCUENTO -> 10% **"<<endl;
        return (seats*this->precioReserva)*0.90;
    }else{
        cout<<"**NO TIENE DESCUENTO**"<<endl;
        return (seats*this->precioReserva);
    }
}

float FuncionesAux::calculoPrecioDebito(int asientos) {
    return this->precioReserva*asientos;
}

DtPelicula* FuncionesAux::puntuoPeli(ICollection *peliculas) {
    system("clear");
    cout<<"====================================="<<endl;
    cout<<"--------- PUNTUAR PELICULA ----------"<<endl;
    cout<<"-------------------------------------"<<endl;
    DtPelicula* peli=seleccionoPeli(peliculas);
    return peli;
}

DtPelicula* FuncionesAux::comentoPeli(ICollection *peliculas) {
    system("clear");
    cout<<"====================================="<<endl;
    cout<<"--------- COMENTAR PELICULA ---------"<<endl;
    cout<<"-------------------------------------"<<endl;
    DtPelicula* peli=seleccionoPeli(peliculas);
    return peli;
}

void FuncionesAux::muestroComentarios(ICollection *comentarios) {
    /*cout<<"====================================="<<endl;
    cout<<"------------ COMENTARIOS ------------"<<endl;
    cout<<"-------------------------------------"<<endl;
    if(comentarios->isEmpty()){
        cout<<"**LA PELICULA NO TIENE COMENTARIOS**"<<endl;
    }else{
        IIterator* it=comentarios->getIterator();
        while(it->hasCurrent()){


            it->next();
        }
        delete it;
    }*/
}

void FuncionesAux::muestroPuntajes(ICollection *puntajes) {
    cout<<"====================================="<<endl;
    cout<<"-------------  PUNTAJES  ------------"<<endl;
    cout<<"-------------------------------------"<<endl;
    if(puntajes->isEmpty()){
        cout<<"**LA PELICULA NO TIENE PUNTUACIONES**"<<endl;
    }else{
        IIterator* it=puntajes->getIterator();
        while(it->hasCurrent()){
            DtPuntaje* point= dynamic_cast<DtPuntaje*>(it->getCurrent());
            cout<<"Usuario: "<<point->getUsuario()->getNick()<<" -> "<<point->getPuntaje()<<" puntos"<<endl;
            cout<<"-------------------------------------"<<endl;
            it->next();
        }
        delete it;
    }
}
