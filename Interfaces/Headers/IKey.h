#pragma once

class IKey{

public:
    /**
     *  Retorna true sii this es igual al argumento
     */
    virtual bool equals(IKey *) const = 0;

    virtual ~IKey();
};
