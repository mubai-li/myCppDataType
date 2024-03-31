//
// Created by 32509 on 2023/12/7.
//


#ifndef UNTITLED2_STRINGVALUE_H
#define UNTITLED2_STRINGVALUE_H

#include "tool/tool.h"


class StringValue;

std::ostream &operator<<(std::ostream &c, const StringValue &aStringValue);


class StringValue {
    enum CompairType {
        ET,
        GT,
        LT,
    };
    int mlength = 0;

    friend std::ostream &operator<<(std::ostream &c, const StringValue &aStringValue);

    friend ValueHash;
    friend Tool;

    friend ListValue;
    typedef std::vector<Value *> _stringType;

    void char_assign(const StringValue &aOther);


    void string_ini();

    void string_ini(const std::string &aValue);

    void string_ini(const char *aValue);

    void string_ini(const char &aValue);

    void string_ini(const StringValue &aOther);

    void string_ini(const _stringType &aOther);

    // NOLINTNEXTLINE
    bool compair(const StringValue &aOther, const CompairType &aCom) const;

    template<class T1>
    bool comSymbo(const T1 &aValue1, const T1 &aValue2, const CompairType &aCom) const;

    std::vector<Value *> *mData = nullptr;
    int *mStringCount = nullptr;

    // NOLINTNEXTLINE
    StringValue(const _stringType &aValue);

    StringValue();

    // NOLINTNEXTLINE
    StringValue(std::nullptr_t);


public:
    ~StringValue();


    // NOLINTNEXTLINE
    StringValue(const std::string &aValue);

    // NOLINTNEXTLINE
    StringValue(const char *aValue);

    // NOLINTNEXTLINE
    StringValue(const char &aValue);

    // NOLINTNEXTLINE
    StringValue(const StringValue &aOther);

    // NOLINTNEXTLINE
    StringValue(int aValue);

    // NOLINTNEXTLINE
    StringValue(double aValue);

    bool isDigit();

    bool isInt();

    Value indexOf(int aPos);

    Value indexOf(int aPos, int aEnd);

    // NOLINTNEXTLINE
    StringValue format(const ListValue &aDatas) const;

    StringValue center(const int &aFillInNumber, const StringValue &aOther);


    StringValue ljust(const int &aFillInNumber, const StringValue &aOther);

    StringValue rjust(const int &aFillInNumber, const StringValue &aOther);


    int count(const StringValue &aOther, const int &aStart = 0, const int &aEnd = -1);

    bool startWith(const StringValue &aOther);

    bool endWith(const StringValue &aOther);


    StringValue strip(const StringValue &aOther);


    StringValue lstrip(const StringValue &aOther);


    StringValue rstrip(const StringValue &aOther);


    int find(const StringValue &aOther, int aPos);

    int find(const StringValue &aOther, int aPos, int aEnd);


    int rfind(const StringValue &aOther, int aPos);

    int rfind(const StringValue &aOther, int aPos, int aEnd);


    // replace and rreplace
    StringValue replace(const StringValue &aOther, const StringValue &aReplaceOther, const int &aMaxNumber = 0);


    StringValue rreplace(const StringValue &aOther, const StringValue &aReplaceOther, const int &aMaxNumber = 0);

    // NOLINTNEXTLINE
    int length() const;

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

    Value &operator[](const int &aIndex);

    StringValue &operator=(const std::string &aValue);

    StringValue &operator=(const StringValue &aOther);

    StringValue &operator=(const char *aValue);

    StringValue &operator=(const char &aValue);

    StringValue &operator+=(const std::string &aValue);

    StringValue &operator+=(const StringValue &aOther);

    StringValue &operator+=(const char *aValue);

    StringValue &operator+=(const char &aValue);

    StringValue &operator+=(const Value &aOther);

    StringValue operator+(char *aValue) const;

    StringValue operator+(const std::string &aOther) const;

    StringValue operator+(const StringValue &aOther) const;

    StringValue operator+(const Value &aOther) const;


    bool operator>(const StringValue &aOther) const;

    bool operator>(const CharValue &aOther) const;

    bool operator>(const Value &aOther) const;

    bool operator>=(const StringValue &aOther) const;

    bool operator>=(const CharValue &aOther) const;

    bool operator>=(const Value &aOther) const;

    bool operator<(const StringValue &aOther) const;

    bool operator<(const CharValue &aOther) const;

    bool operator<(const Value &aOther) const;

    bool operator<=(const StringValue &aOther) const;

    bool operator<=(const CharValue &aOther) const;

    bool operator<=(const Value &aOther) const;

    bool operator==(const StringValue &aOther) const;

    bool operator==(const CharValue &aOther) const;

    bool operator==(const Value &aOther) const;

    bool operator!=(const StringValue &aOther) const;

    bool operator!=(const CharValue &aOther) const;

    bool operator!=(const Value &aOther) const;


};


#endif //UNTITLED2_STRINGVALUE_H
