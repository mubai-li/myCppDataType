//
// Created by mubai on 2023/12/8.
//
#include "tool/tool.h"


#ifndef UNTITLED2_INTVALUE_H
#define UNTITLED2_INTVALUE_H


class IntValue;

std::ostream &operator<<(std::ostream &c, const IntValue &aIntValue);

class IntValue {
    friend std::ostream &operator<<(std::ostream &c, const IntValue &aIntValue);

    friend FloatValue;
    friend ValueHash;

    int *mData = nullptr;
    int *mDataCount = nullptr;

    void int_ini(const int &aValue);

    void int_ini(const IntValue &aOther);
    void int_ini(const FloatValue &aOther);

public:
    IntValue();

    // NOLINTNEXTLINE
    IntValue(const int &aValue);

    // NOLINTNEXTLINE
    IntValue(const IntValue &aOther);

    ~IntValue();

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
    operator FloatValue() const;

    // NOLINTNEXTLINE
    operator StringValue() const;

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


    IntValue &operator=(const IntValue &aOther);

    IntValue &operator=(const FloatValue &aOther);


    IntValue operator*(const IntValue &aOther) const;

    FloatValue operator*(const FloatValue &aOther) const;
    Value operator*(const Value &aOther) const;

    IntValue &operator*=(const IntValue &aOther);

    IntValue &operator*=(const FloatValue &aOther);
    IntValue &operator*=(const Value &aOther);


    IntValue operator/(const IntValue &aOther) const;

    FloatValue operator/(const FloatValue &aOther) const;
    Value operator/(const Value &aOther) const;

    IntValue &operator/=(const IntValue &aOther);

    IntValue &operator/=(const FloatValue &aOther);
    IntValue &operator/=(const Value &aOther);

    IntValue operator+(const IntValue &aOther) const;

    FloatValue operator+(const FloatValue &aOther) const;
    Value operator+(const Value &aOther) const;

    IntValue &operator+=(const IntValue &aOther);

    IntValue &operator+=(const FloatValue &aOther);

    IntValue &operator+=(const Value &aOther);

    IntValue operator-(const IntValue &aOther) const;

    FloatValue operator-(const FloatValue &aOther) const;
    Value operator-(const Value &aOther) const;

    IntValue &operator-=(const IntValue &aOther);

    IntValue &operator-=(const FloatValue &aOther);
    IntValue &operator-=(const Value &aOther);
};


#endif //UNTITLED2_INTVALUE_H
