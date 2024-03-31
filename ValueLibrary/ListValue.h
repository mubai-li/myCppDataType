//
// Created by 32509 on 2024/1/8.
//
#include "tool/tool.h"

#ifndef MYCPPDATATYPE_LISTVALUE_H
#define MYCPPDATATYPE_LISTVALUE_H

class ListValue;

std::ostream &operator<<(std::ostream &c, const ListValue &aListValue);

class ListValue {
    friend StringValue;
    friend CharValue;
public:
    // NOLINTNEXTLINE
    typedef std::vector<Value *> _ListTYPE;
private:
    friend std::ostream &operator<<(std::ostream &c, const ListValue &aListValue);
    friend ValueHash;

    _ListTYPE *mData = nullptr;
    int *mDataCount = nullptr;

    void listValue_ini();

    void listValue_ini(const ListValue &aOther);

public:
    ListValue();

    ListValue(const std::initializer_list<Value> &aDatas);

    ListValue(const ListValue &aOther);


    ~ListValue();

    // NOLINTNEXTLINE
    int length() const;

    void append(const Value &aValue);

    void insert(int pos, const Value &aValue);

    void extend(const ListValue &aOther);

    void remove(const Value &aValue);

    void clear();

    void reverse();


    int index(const Value &aOther,  unsigned  int aStart,  int aEnd);

    int count(const Value &aOther,  unsigned int pos,  int end);

    // NOLINTNEXTLINE
    ListValue indexOf(int pos) const;

    // NOLINTNEXTLINE
    ListValue indexOf(int pos, int end) const;

    Value pop(int aValueIndex);

    ListValue copy();

    Value &operator[](const int &aIndex);

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

    ListValue &operator=(const ListValue &aOther);

    ListValue operator+(const ListValue &aOther) const;
    ListValue operator+(const Value &aOther) const;

    ListValue &operator+=(const ListValue &aOther);
    ListValue &operator+=(const Value &aOther);

    bool operator==(const ListValue &aOther) const;

    bool operator!=(const ListValue &aOther) const;
    bool operator==(const Value &aOther) const;
    bool operator>(const ListValue &aOther) const;
    bool operator>(const Value &aOther) const;
    bool operator<(const ListValue &aOther) const;
    bool operator<(const Value &aOther) const;

};


#endif //MYCPPDATATYPE_LISTVALUE_H
