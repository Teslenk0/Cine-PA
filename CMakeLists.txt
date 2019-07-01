cmake_minimum_required(VERSION 3.14)
project(PA_POSTA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Classes)
include_directories(Classes/Headers)
include_directories(Collections)
include_directories(Datatypes/Headers)
include_directories(Interfaces/Headers)

add_executable(PA_POSTA
        Classes/Headers/Cine.h
        Classes/Headers/Pelicula.h
        Classes/Headers/usuario.h
        Classes/src/Cine.cpp
        Classes/src/Pelicula.cpp
        Classes/src/usuario.cpp
        Classes/src/Funcion.cpp
        Classes/Headers/Funcion.h
        Collections/src/List.cpp
        Collections/Headers/List.h
        Collections/src/ListIterator.cpp
        Collections/Headers/ListIterator.h
        Collections/src/ListNode.cpp
        Collections/Headers/ListNode.h
        Collections/src/OrderedDictionary.cpp
        Collections/Headers/OrderedDictionary.h
        Collections/src/OrderedDictionaryEntry.cpp
        Collections/Headers/OrderedDictionaryEntry.h
        Datatypes/Headers/DtCine.h
        Datatypes/Headers/DtDireccion.h
        Datatypes/Headers/DtFecha.h
        Datatypes/Headers/DtPelicula.h
        Datatypes/src/DtCine.cpp
        Datatypes/src/DtDireccion.cpp
        Datatypes/src/DtFecha.cpp
        Datatypes/src/DtPelicula.cpp
        Interfaces/Headers/ICollectible.h
        Interfaces/Headers/ICollection.h
        Interfaces/Headers/IDictionary.h
        Interfaces/Headers/IIterator.h
        Interfaces/Headers/IKey.h
        Interfaces/Headers/IOrderedKey.h
        Interfaces/src/ICollectible.cpp
        Interfaces/src/ICollection.cpp
        Interfaces/src/IDictionary.cpp
        Interfaces/src/IIterator.cpp
        Interfaces/src/IKey.cpp
        Interfaces/src/IOrderedKey.cpp
        main.cpp
        StringKey.h
        StringKey.cpp
        IntKey.h
        IntKey.cpp
        Datatypes/src/DtFuncion.cpp Datatypes/Headers/DtFuncion.h Classes/src/Reserva.cpp Classes/Headers/Reserva.h Classes/src/Sala.cpp Classes/Headers/Sala.h Datatypes/src/DtSala.cpp Datatypes/Headers/DtSala.h Classes/src/PagoDebito.cpp Classes/Headers/PagoDebito.h Classes/src/PagoCredito.cpp Classes/Headers/PagoCredito.h Classes/src/Sistema.cpp Classes/Headers/Sistema.h Classes/src/FuncionesAux.cpp Classes/Headers/FuncionesAux.h Classes/src/controladorSesion.cpp Classes/Headers/controladorSesion.h Datatypes/src/DtUsuario.cpp Datatypes/Headers/DtUsuario.h Classes/src/Puntaje.cpp Classes/Headers/Puntaje.h Classes/src/Comentario.cpp Classes/Headers/Comentario.h Datatypes/src/DtComentario.cpp Datatypes/Headers/DtComentario.h Datatypes/src/DtPuntaje.cpp Datatypes/Headers/DtPuntaje.h)
