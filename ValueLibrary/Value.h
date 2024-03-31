#ifndef UNTITLED2_VALUE_H
#define UNTITLED2_VALUE_H

#include "iostream"
#include <cstring>
#include <cmath>

class IntValue;

class FloatValue;

class StringValue;

class ListValue;

class DictValue;

class CharValue;


class Value;

std::ostream &operator<<(std::ostream &c, const Value &aValue);

struct ValueHash;

class Value {
    friend std::ostream &operator<<(std::ostream &c, const Value &aValue);

    friend IntValue;
    friend FloatValue;
    friend CharValue;
    friend StringValue;
    friend ListValue;
    friend DictValue;
    friend ValueHash;
    enum CompairType {
        ET,
        GT,
        LT,
    };
public:

    enum DataType {
        TYPE_NONE,
        TYPE_BOOL,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_CHAR,
        TYPE_STRING,
        TYPE_LIST,
        TYPE_DICT,
    };
private:
    union Data {
        CharValue *c;
        IntValue *i;
        FloatValue *f;
        StringValue *s;
        ListValue *l;
        DictValue *d;
    };
    Data *mData = nullptr;
    DataType mValueType = TYPE_NONE;

    static bool noneComSymbo(const Value &aOther, const CompairType &aCom);

    template<class T>
    static bool comSymbo(const T &aOther, const Value &aNext, const CompairType &aCom);

    // NOLINTNEXTLINE
    static bool compair(const Value &aOther, const Value &aNext, const CompairType &aCom);

    void charValue_ini(const char &aValue);

    void charValue_ini(const Value &aOther);

    void boolValue_ini(const bool &aValue);

    void intValue_ini(const int &aValue);

    void floatValue_ini(const float &aValue);

    void doubleValue_ini(const double &aValue);

    void stringValue_ini(const std::string &aValue);

    void stringValue_ini(const char *aValue);

    void stringValue_ini(const char &aValue);

    void stringValue_ini(const StringValue &aValue);

    void dictValue_ini(const DictValue &aOther);

    void listValue_ini(const ListValue &aValue);

    void listValue_ini(const std::initializer_list<Value> &aDatas);

    void value_ini(const IntValue &aOther);

    void value_ini(const FloatValue &aOther);

    void value_ini(const StringValue &aOther);

    void value_ini(const ListValue &aOther);

    void value_ini(const CharValue &aOther);

    void value_ini(const DictValue &aOther);

    void value_ini(const Value &aOther);

    template<class transfromType>
    transfromType _transfromType(const std::string &aErrorType = "") const;

    // NOLINTNEXTLINE
    operator CharValue &() const;

    // NOLINTNEXTLINE
    StringValue &getStringValue() const;

public:

    Value();

    // NOLINTNEXTLINE
    Value(std::nullptr_t);

    // NOLINTNEXTLINE
    Value(const bool &aValue);

    // NOLINTNEXTLINE
    Value(const int &aValue);

    // NOLINTNEXTLINE
    // NOLINTNEXTLINE
    Value(const float &aValue);

    // NOLINTNEXTLINE
    Value(const double &aValue);

    // NOLINTNEXTLINE
    // NOLINTNEXTLINE
    Value(const std::string &aValue);

    // NOLINTNEXTLINE
    Value(const char *aValue);

    // NOLINTNEXTLINE
    Value(const char &aValue);

    // NOLINTNEXTLINE
    Value(const std::initializer_list<Value> &aDatas);

    // NOLINTNEXTLINE
    Value(const IntValue &aOther);

    // NOLINTNEXTLINE
    Value(const FloatValue &aOther);

    // NOLINTNEXTLINE
    Value(const StringValue &aOther);

    // NOLINTNEXTLINE
    Value(const ListValue &aOther);

    // NOLINTNEXTLINE
    Value(const CharValue &aOther);

    // NOLINTNEXTLINE
    Value(const DictValue &aOther);

    Value(const Value &aOther);


    ~Value();

    // NOLINTNEXTLINE
    int length() const;

    void append(const Value &aValue);

    void insert(int aPos, const Value &aValue);

    void extend(const ListValue &aOther);

    void remove(const Value &aValue);

    void clear();

    void reverse();


    int index(const Value &aOther, const int &aPos, const int &aEnd);

    int count(const Value &aOther, const int &aPos, const int &aEnd);

    // NOLINTNEXTLINE
    Value indexOf(int aPos) const;

    // NOLINTNEXTLINE
    Value indexOf(int aPos, int aEnd) const;

    Value pop(const Value &aValue);

    Value pop(const int &aValue);

    Value pop(const float &aValue);

    Value pop(const double &aValue);

    Value pop(const char &aValue);

    Value pop(const char *aValue);

    Value copy();

    // NOLINTNEXTLINE
    Value format(const ListValue &aDatas) const;

    Value center(const int &aFillInNumber, const Value &aOther);


    Value ljust(const int &aFillInNumber, const Value &aOther);

    Value rjust(const int &aFillInNumber, const Value &aOther);


    bool startWith(const Value &aOther);

    bool endWith(const Value &aOther);


    Value strip(const Value &aOther);


    Value lstrip(const Value &aOther);


    Value rstrip(const Value &aOther);


    int find(const Value &aOther, int aPos);

    int find(const Value &aOther, int aPos, int aEnd);


    int rfind(const Value &aOther, int aPos);

    int rfind(const Value &aOther, int aPos, int aEnd);


    // replace and rreplace
    Value replace(const Value &aOther, const Value &aReplaceOther, const int &aMaxNumber = 0);


    Value rreplace(const Value &aOther, const Value &aReplaceOther, const int &aMaxNumber = 0);

    bool isDigit();

    bool isInt();

    Value get(const Value &key);

    void changeOrSetDefault(const Value &key, const Value &value);

    bool setDefault(const Value &key, const Value &value);


    // NOLINTNEXTLINE
    Value type() const;

    bool comparerType(const DataType &aDataType);

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
    operator IntValue() const;

    // NOLINTNEXTLINE
    operator FloatValue() const;

    // NOLINTNEXTLINE
    operator StringValue() const;

    // NOLINTNEXTLINE
    operator ListValue() const;

    Value &operator[](const Value &aIndex);

    Value &operator[](const int &aIndex);

    Value &operator[](const float &aIndex);

    Value &operator[](const double &aIndex);

    Value &operator[](const char &aIndex);

    Value &operator[](const char *aIndex);

    Value operator+(const Value &aOther) const;

    Value operator-(const Value &aOther) const;

    Value operator*(const Value &aOther) const;

    Value operator/(const Value &aOther) const;

    Value &operator+=(const Value &aOther);

    Value &operator-=(const Value &aOther);

    Value &operator*=(const Value &aOther);

    Value &operator/=(const Value &aOther);

    Value &operator=(const Value &aOther);

    Value &operator=(const DictValue &aOther);

    bool operator==(std::nullptr_t) const;

    bool operator==(const Value &aOther) const;

    bool operator!=(const Value &aOther) const;

    bool operator>(const Value &aOther) const;

    bool operator>=(const Value &aOther) const;

    bool operator<(const Value &aOther) const;

    bool operator<=(const Value &aOther) const;

};

#include "StringValue.h"
#include "ListValue.h"
#include "DictValue.h"
#include "IntValue.h"
#include "FloatValue.h"
#include "CharValue.h"
//
#endif //UNTITLED2_VALUE_H
