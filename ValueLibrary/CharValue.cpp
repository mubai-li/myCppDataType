//
// Created by 32509 on 2024/1/11.
//

#include "CharValue.h"

bool CharValue::_ini = false;
ListValue CharValue::_allCharValue;

std::ostream &operator<<(std::ostream &c, const CharValue &aStringValue) {
    c << *aStringValue.mData;
    return c;
}

void CharValue::ini_ini(const char &aValue) {
    if (!CharValue::_ini) {
        CharValue::_allCharValue.mData->resize(256);
        // NOLINTNEXTLINE
        ListValue::_ListTYPE::iterator allCharValueIndex = CharValue::_allCharValue.mData->begin();
//        for(int index=-128;index !=128;index++){
        for (int index = -128; index != 128; index++) {
            *allCharValueIndex = new Value();
            (*allCharValueIndex)->mData = new Value::Data;
            (*allCharValueIndex)->mData->c = new CharValue();
            (*allCharValueIndex)->mValueType = Value::DataType::TYPE_CHAR;
            (*allCharValueIndex)->mData->c->mData = new char(char(index));
            (*allCharValueIndex)->mData->c->mDataCount = new int(1);
            allCharValueIndex++;
        }

    }
    this->ini_ini(*CharValue::_allCharValue[int(aValue) + 128].mData->c);
}

void CharValue::ini_ini(const CharValue &aOther) {
    this->mData = aOther.mData;
    this->mDataCount = aOther.mDataCount;
    (*this->mDataCount)++;
}

CharValue::CharValue() = default;


CharValue::CharValue(const char &aValue) {
    this->ini_ini(aValue);
}

CharValue::CharValue(const CharValue &aOther) {
    this->ini_ini(aOther);
}

CharValue::~CharValue() {
    if (*this->mDataCount == 1) {
        delete this->mData;
        this->mData = nullptr;
        delete this->mDataCount;
        this->mDataCount = nullptr;
    } else {
        this->mData = nullptr;
        (*this->mDataCount)--;
        this->mDataCount = nullptr;
    }
}

CharValue::operator bool() const {
    return *this->mData;
}

CharValue::operator int() const {
    return *this->mData;
}

CharValue::operator float() const {
    return *this->mData;
}

CharValue::operator double() const {
    return *this->mData;
}

CharValue::operator char *() const {
    return this->mData;
}

CharValue::operator std::string() const {
    return {*this->mData, 1};
}

CharValue::operator char() const {
    return *this->mData;
}


CharValue::operator StringValue() const {
    return *this->mData;
}

// NOLINTNEXTLINE
CharValue &CharValue::operator=(const CharValue &) {
    throw std::runtime_error("can't change");
}

bool CharValue::operator==(const CharValue &aOther) const {
    return *this->mData == *aOther.mData;
}

bool CharValue::operator==(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::DataType::TYPE_NONE:
            return false;
        case Value::DataType::TYPE_CHAR:
            return *this == *aOther.mData->c;
        case Value::DataType::TYPE_STRING:
            return StringValue(*this) == *aOther.mData->s;
        case Value::DataType::TYPE_BOOL:
        case Value::DataType::TYPE_INT:
        case Value::DataType::TYPE_FLOAT:
        case Value::DataType::TYPE_LIST:
        case Value::DataType::TYPE_DICT:
            return false;
    }
    throw std::runtime_error("charValue == Value");
}

bool CharValue::operator!=(const CharValue &aOther) const {
    return *this->mData != *aOther.mData;
}

bool CharValue::operator>(const CharValue &aOther) const {
    return *this->mData > *aOther.mData;
}

bool CharValue::operator>(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::DataType::TYPE_NONE:
            return false;
        case Value::DataType::TYPE_CHAR:
            return *this == *aOther.mData->c;
        case Value::DataType::TYPE_STRING:
            return StringValue(*this) == *aOther.mData->s;
        case Value::DataType::TYPE_BOOL:
        case Value::DataType::TYPE_INT:
        case Value::DataType::TYPE_FLOAT:
        case Value::DataType::TYPE_LIST:
        case Value::DataType::TYPE_DICT:
            throw std::runtime_error(std::string(StringValue("String types cannot be compared with {} types").format({aOther.type()})));

    }
    throw std::runtime_error("charValue > Value");
}

bool CharValue::operator>=(const CharValue &aOther) const {
    return *this->mData >= *aOther.mData;
}

bool CharValue::operator<(const CharValue &aOther) const {
    return *this->mData < *aOther.mData;
}

bool CharValue::operator<(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::DataType::TYPE_NONE:
            return false;
        case Value::DataType::TYPE_CHAR:
            return *this == *aOther.mData->c;
        case Value::DataType::TYPE_STRING:
            return StringValue(*this) == *aOther.mData->s;
        case Value::DataType::TYPE_BOOL:
        case Value::DataType::TYPE_INT:
        case Value::DataType::TYPE_FLOAT:
        case Value::DataType::TYPE_LIST:
        case Value::DataType::TYPE_DICT:
            throw std::runtime_error(std::string(StringValue("String types cannot be compared with {} types").format({aOther.type()})));
    }
    throw std::runtime_error("charValue < Value");
}

bool CharValue::operator<=(const CharValue &aOther) const {
    return *this->mData <= *aOther.mData;
}
