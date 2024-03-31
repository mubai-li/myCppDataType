//
// Created by 32509 on 2024/1/8.
//
#include "tool/tool.h"

#ifndef MYCPPDATATYPE_DICTVALUE_H
#define MYCPPDATATYPE_DICTVALUE_H

#include <unordered_map>

class DictValue;

std::ostream &operator<<(std::ostream &c, const DictValue &aDictValue);


struct ValueHash {
    std::size_t operator()(const Value &obj) const;

    bool operator()(const Value &a, const Value &b) const;
};

class DictValue {

    friend std::ostream &operator<<(std::ostream &c, const DictValue &aDictValue);

    // NOLINTNEXTLINE
    typedef std::unordered_map<Value, Value, ValueHash, ValueHash> _DICTTYPE;
    _DICTTYPE *mData = nullptr;
    int *mDataCount = nullptr;

    void dictValue_ini();
    void dictValue_ini(const DictValue &aOther);

public:
    DictValue();
    DictValue(const DictValue &aOther);

    ~DictValue();

    bool setDefault(const Value &key, const Value &value);

    void changeOrSetDefault(const Value &key, const Value &value);

    Value get(const Value &key);

    Value pop(const Value &key);

    Value &operator[](const Value &key);

    bool operator==(const Value &aOther) const;

    bool operator>(const Value &aOther) const;

    bool operator<(const Value &aOther) const;


};


#endif //MYCPPDATATYPE_DICTVALUE_H
