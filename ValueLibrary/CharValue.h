//
// Created by 32509 on 2024/1/11.
//

#ifndef MYCPPDATATYPE_CHARVALUE_H
#define MYCPPDATATYPE_CHARVALUE_H

#include "tool/tool.h"

class CharValue;

std::ostream &operator<<(std::ostream &c, const CharValue &aStringValue);

class CharValue {
    friend Value;
    static bool _ini;
    static ListValue _allCharValue;
    friend std::ostream &operator<<(std::ostream &c, const CharValue &aStringValue);

    friend StringValue;
    friend ValueHash;
    char *mData = nullptr;
    int *mDataCount = nullptr;

    void ini_ini(const char &aValue);

    void ini_ini(const CharValue &aOther);

    CharValue();

    // NOLINTNEXTLINE
    CharValue(const char &aValue);

    CharValue(const CharValue &aOther);

    ~CharValue();

public:


    // NOLINTNEXTLINE
    operator bool() const;

    // NOLINTNEXTLINE
    operator int() const;

    // NOLINTNEXTLINE
    operator double() const;

    // NOLINTNEXTLINE
    operator float() const;

    // NOLINTNEXTLINE
    operator char *() const;

    // NOLINTNEXTLINE
    operator std::string() const;

    // NOLINTNEXTLINE
    operator char() const;

    // NOLINTNEXTLINE
    operator StringValue() const;

    CharValue &operator=(const CharValue &) ;

    bool operator==(const CharValue &aOther) const;
    bool operator==(const Value &aOther) const;

    bool operator!=(const CharValue &aOther) const;

    bool operator>(const CharValue &aOther) const;
    bool operator>(const Value &aOther) const;

    bool operator>=(const CharValue &aOther) const;

    bool operator<(const CharValue &aOther) const;
    bool operator<(const Value &aOther) const;

    bool operator<=(const CharValue &aOther) const;
};


#endif //MYCPPDATATYPE_CHARVALUE_H
