#make clean
#make all
CC=g++ -std=c++17
CFLAGS= -c -Wall
all: Programon


Programon: main.o FuncionesAux.o Sistema.o StringKey.o IntKey.o Cine.o PagoCredito.o PagoDebito.o Funcion.o Pelicula.o Reserva.o usuario.o Sala.o Puntaje.o Comentario.o DtFecha.o DtPelicula.o DtFuncion.o DtCine.o DtSala.o DtDireccion.o DtUsuario.o DtComentario.o DtPuntaje.o ICollectible.o ICollection.o IIterator.o IDictionary.o IKey.o IOrderedKey.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o
	$(CC) main.o FuncionesAux.o Sistema.o StringKey.o IntKey.o Cine.o PagoCredito.o PagoDebito.o Funcion.o Pelicula.o  Reserva.o usuario.o  Sala.o Puntaje.o Comentario.o DtFecha.o DtPelicula.o DtFuncion.o DtCine.o DtSala.o DtDireccion.o DtUsuario.o DtComentario.o DtPuntaje.o ICollectible.o ICollection.o IIterator.o IDictionary.o IKey.o IOrderedKey.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o -o Programon

main.o : main.cpp ./Classes/Headers/Sistema.h ./Classes/Headers/FuncionesAux.h
	$(CC) $(CFLAGS) main.cpp 

FuncionesAux.o : ./Classes/src/FuncionesAux.cpp ./Classes/Headers/FuncionesAux.h
	$(CC) $(CFLAGS) ./Classes/src/FuncionesAux.cpp

Sistema.o: ./Classes/src/Sistema.cpp  ./Classes/Headers/Sistema.h
	$(CC) $(CFLAGS) ./Classes/src/Sistema.cpp

StringKey.o: ./StringKey.cpp  ./StringKey.h
	$(CC) $(CFLAGS) ./StringKey.cpp

IntKey.o: ./IntKey.cpp  ./IntKey.h
	$(CC) $(CFLAGS) ./IntKey.cpp

Cine.o: ./Classes/src/Cine.cpp  ./Classes/Headers/Cine.h
	$(CC) $(CFLAGS) ./Classes/src/Cine.cpp

PagoCredito.o: ./Classes/src/PagoCredito.cpp ./Classes/Headers/PagoCredito.h
	$(CC) $(CFLAGS) ./Classes/src/PagoCredito.cpp

PagoDebito.o: ./Classes/src/PagoDebito.cpp ./Classes/Headers/PagoDebito.h
	$(CC) $(CFLAGS) ./Classes/src/PagoDebito.cpp

Funcion.o: ./Classes/src/Funcion.cpp ./Classes/Headers/Funcion.h
	$(CC) $(CFLAGS) ./Classes/src/Funcion.cpp

Pelicula.o: ./Classes/src/Pelicula.cpp ./Classes/Headers/Pelicula.h
	$(CC) $(CFLAGS) ./Classes/src/Pelicula.cpp

Reserva.o: ./Classes/src/Reserva.cpp ./Classes/Headers/Reserva.h
	$(CC) $(CFLAGS) ./Classes/src/Reserva.cpp

usuario.o: ./Classes/src/usuario.cpp ./Classes/Headers/usuario.h
	$(CC) $(CFLAGS) ./Classes/src/usuario.cpp

Sala.o: ./Classes/src/Sala.cpp ./Classes/Headers/Sala.h 
	$(CC) $(CFLAGS) ./Classes/src/Sala.cpp

Puntaje.o: ./Classes/src/Puntaje.cpp ./Classes/Headers/Puntaje.h
	$(CC) $(CFLAGS) ./Classes/src/Puntaje.cpp

Comentario.o: ./Classes/src/Comentario.cpp ./Classes/Headers/Comentario.h
	$(CC) $(CFLAGS) ./Classes/src/Comentario.cpp

DtFecha.o: ./Datatypes/src/DtFecha.cpp ./Datatypes/Headers/DtFecha.h 
	$(CC) $(CFLAGS) ./Datatypes/src/DtFecha.cpp

DtPelicula.o: ./Datatypes/src/DtPelicula.cpp ./Datatypes/Headers/DtPelicula.h 
	$(CC) $(CFLAGS) ./Datatypes/src/DtPelicula.cpp

DtFuncion.o: ./Datatypes/src/DtFuncion.cpp ./Datatypes/Headers/DtFuncion.h 
	$(CC) $(CFLAGS) ./Datatypes/src/DtFuncion.cpp

DtCine.o: ./Datatypes/src/DtCine.cpp ./Datatypes/Headers/DtCine.h 
	$(CC) $(CFLAGS) ./Datatypes/src/DtCine.cpp

DtSala.o: ./Datatypes/src/DtSala.cpp ./Datatypes/Headers/DtSala.h 
	$(CC) $(CFLAGS) ./Datatypes/src/DtSala.cpp

DtDireccion.o: ./Datatypes/src/DtDireccion.cpp ./Datatypes/Headers/DtDireccion.h
	$(CC) $(CFLAGS) ./Datatypes/src/DtDireccion.cpp

DtUsuario.o: ./Datatypes/src/DtUsuario.cpp ./Datatypes/Headers/DtUsuario.h
	$(CC) $(CFLAGS) ./Datatypes/src/DtUsuario.cpp

DtComentario.o: ./Datatypes/src/DtComentario.cpp ./Datatypes/Headers/DtComentario.h
	$(CC) $(CFLAGS) ./Datatypes/src/DtComentario.cpp

DtPuntaje.o: ./Datatypes/src/DtPuntaje.cpp ./Datatypes/Headers/DtPuntaje.h
	$(CC) $(CFLAGS) ./Datatypes/src/DtPuntaje.cpp

ICollectible.o: ./Interfaces/src/ICollectible.cpp ./Interfaces/Headers/ICollectible.h 
	$(CC) $(CFLAGS) ./Interfaces/src/ICollectible.cpp

ICollection.o: ./Interfaces/src/ICollection.cpp ./Interfaces/Headers/ICollection.h 
	$(CC) $(CFLAGS) ./Interfaces/src/ICollection.cpp

IIterator.o: ./Interfaces/src/IIterator.cpp ./Interfaces/Headers/IIterator.h 
	$(CC) $(CFLAGS) ./Interfaces/src/IIterator.cpp

IDictionary.o: ./Interfaces/src/IDictionary.cpp ./Interfaces/Headers/IDictionary.h 
	$(CC) $(CFLAGS) ./Interfaces/src/IDictionary.cpp

IKey.o: ./Interfaces/src/IKey.cpp ./Interfaces/Headers/IKey.h 
	$(CC) $(CFLAGS) ./Interfaces/src/IKey.cpp

IOrderedKey.o: ./Interfaces/src/IOrderedKey.cpp ./Interfaces/Headers/IOrderedKey.h 
	$(CC) $(CFLAGS) ./Interfaces/src/IOrderedKey.cpp

List.o: ./Collections/src/List.cpp ./Collections/Headers/List.h
	$(CC) $(CFLAGS) ./Collections/src/List.cpp

ListIterator.o: ./Collections/src/ListIterator.cpp ./Collections/Headers/ListIterator.h
	$(CC) $(CFLAGS) ./Collections/src/ListIterator.cpp

ListNode.o: ./Collections/src/ListNode.cpp ./Collections/Headers/ListNode.h
	$(CC) $(CFLAGS) ./Collections/src/ListNode.cpp

OrderedDictionary.o: ./Collections/src/OrderedDictionary.cpp ./Collections/Headers/OrderedDictionary.h
	$(CC) $(CFLAGS) ./Collections/src/OrderedDictionary.cpp

OrderedDictionaryEntry.o: ./Collections/src/OrderedDictionaryEntry.cpp ./Collections/Headers/OrderedDictionaryEntry.h
	$(CC) $(CFLAGS) ./Collections/src/OrderedDictionaryEntry.cpp

clean:
	rm -rf *o Programon