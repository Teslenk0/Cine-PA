// IntKey.cpp

#include <stdexcept>
#include "IntKey.h"

IntKey::IntKey(int entero)
{
    num = entero;
}

ComparisonRes IntKey::compare(OrderedKey* k) const
{
    IntKey* ik = dynamic_cast<IntKey*>(k);
    if (ik == nullptr)
        throw std::invalid_argument("Invalid key k");

    if (num == ik->num)
        return EQUAL;
    else if (num > ik->num)
        return GREATER;
    else
        return LESSER;
}
