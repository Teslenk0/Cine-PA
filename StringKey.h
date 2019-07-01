// StringKey.h

#ifndef STRINGKEY_H
#define STRINGKEY_H

#include <string>
using std::string;

#include "Interfaces/Headers/IOrderedKey.h"

struct StringKey : public OrderedKey {
public:
    StringKey(string str);

    ComparisonRes compare(OrderedKey* k) const;

    ~StringKey() {}

private:
    string s;
};

#endif  
