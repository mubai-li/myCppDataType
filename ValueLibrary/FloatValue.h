//
// Created by 32509 on 2023/12/25.
//
#include "tool/tool.h"

#ifndef MYCPPDATATYPE_FLOATVALUE_H
#define MYCPPDATATYPE_FLOATVALUE_H


class FloatValue;

std::ostream &operator<<(std::ostream &c, const FloatValue &aFloatValue);

class FloatValue {
    friend std::ostream &operator<<(std::ostream &c, const FloatValue &aFloatValue);

    friend IntValue;
    friend ValueHash;

    double *mData = nullptr;
    int *mDataCount = nullptr;

    void ini_ini(const double &aValue);

    void ini_ini(const int &aValue);

    void ini_ini(const float &aValue);

    void ini_ini(const FloatValue &aOther);

public:
    FloatValue();

    // NOLINTNEXTLINE
    FloatValue(const double &aValue);

    // NOLINTNEXTLINE
    FloatValue(const float &aValue);

    // NOLINTNEXTLINE
    FloatValue(const int &aValue);


    FloatValue(const FloatValue &aOther);

    ~FloatValue();

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

    // NOLINTNEXTLINE
    operator IntValue() const;

    bool operator==(const IntValue &aOther) const;

    bool operator==(const FloatValue &aOther) const;

    bool operator==(const Value &aOther) const;

    bool operator!=(const IntValue &aOther) const;

    bool operator!=(const FloatValue &aOther) const;

    bool operator!=(const Value &aOther) const;

    bool operator>(const IntValue &aOther) const;

    bool operator>(const FloatValue &aOther) const;

    bool operator>(const Value &aOther) const;

    bool operator>=(const IntValue &aOther) const;

    bool operator>=(const FloatValue &aOther) const;

    bool operator>=(const Value &aOther) const;

    bool operator<(const IntValue &aOther) const;

    bool operator<(const FloatValue &aOther) const;

    bool operator<(const Value &aOther) const;

    bool operator<=(const IntValue &aOther) const;

    bool operator<=(const FloatValue &aOther) const;

    bool operator<=(const Value &aOther) const;

    FloatValue &operator=(const FloatValue &aOther);

    FloatValue &operator=(const IntValue &aOther);

    FloatValue operator*(const FloatValue &aOther) const;

    FloatValue operator*(const IntValue &aOther) const;

    Value operator*(const Value &aOther) const;

    FloatValue &operator*=(const FloatValue &aOther);

    FloatValue &operator*=(const IntValue &aOther);

    FloatValue &operator*=(const Value &aOther);

    FloatValue operator/(const FloatValue &aOther) const;

    FloatValue operator/(const IntValue &aOther) const;

    Value operator/(const Value &aOther) const;

    FloatValue &operator/=(const FloatValue &aOther);

    FloatValue &operator/=(const IntValue &aOther);

    FloatValue &operator/=(const Value &aOther);

    FloatValue operator+(const FloatValue &aOther) const;

    FloatValue operator+(const IntValue &aOther) const;

    Value operator+(const Value &aOther) const;

    FloatValue &operator+=(const FloatValue &aOther);

    FloatValue &operator+=(const IntValue &aOther);

    FloatValue &operator+=(const Value &aOther);

    FloatValue operator-(const FloatValue &aOther) const;

    FloatValue operator-(const IntValue &aOther) const;

    Value operator-(const Value &aOther) const;

    FloatValue &operator-=(const FloatValue &aOther);

    FloatValue &operator-=(const IntValue &aOther);

    FloatValue &operator-=(const Value &aOther);
};


#endif //MYCPPDATATYPE_FLOATVALUE_H
