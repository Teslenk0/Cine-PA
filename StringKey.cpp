// StringKey.cpp

#include <stdexcept>
#include "StringKey.h"

StringKey::StringKey(string str) : s {str}
{
}

ComparisonRes StringKey::compare(OrderedKey* k) const
{
    StringKey* sk = dynamic_cast<StringKey*>(k);
    if (sk == nullptr)
        throw std::invalid_argument("Invalid key k");

    if (s == sk->s)
        return EQUAL;
    else if (s > sk->s)
        return GREATER;
    else
        return LESSER;
}
