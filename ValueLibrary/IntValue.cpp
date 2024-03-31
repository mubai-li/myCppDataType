//
// Created by mubai on 2023/12/8.
//

#include "IntValue.h"


std::ostream &operator<<(std::ostream &c, const IntValue &aIntValue) {
    c << *aIntValue.mData;
    return c;
}


void IntValue::int_ini(const int &aValue) {
    this->mData = new int(aValue);
    this->mDataCount = new int(1);
}


void IntValue::int_ini(const IntValue &aOther) {
    this->mData = aOther.mData;
    this->mDataCount = aOther.mDataCount;
    (*this->mDataCount)++;
}
void IntValue::int_ini(const FloatValue &aOther) {
    this->mData = new int(int(*aOther.mData));
    this->mDataCount = new int(1);
}

IntValue::IntValue() {
    this->int_ini(0);
}

IntValue::IntValue(const int &aValue) {
    this->int_ini(aValue);
}

IntValue::IntValue(const IntValue &aOther) {
    this->int_ini(aOther);
}

IntValue::~IntValue() {
    if (this->mData != nullptr) {
        if (*this->mDataCount == 1) {
            delete this->mData;
            this->mData = nullptr;
            delete this->mDataCount;
            this->mDataCount = nullptr;
        } else {
            (*this->mDataCount)--;
            this->mDataCount = nullptr;
            this->mData = nullptr;
        }
    }
}

IntValue::operator bool() const {
    return *this->mData;
}

IntValue::operator int() const {
    return *this->mData;
}

IntValue::operator float() const {
    return float(*this->mData);
}

IntValue::operator double() const {
    return *this->mData;
}

IntValue::operator char *() const {
    int maxSize = 12; // 11 个数字字符 + 1 个负号字符 + 1 个终止符 '\0'
    char *str = (char *) malloc(maxSize * sizeof(char));

    snprintf(str, maxSize, "%d", *this->mData);
    size_t strLen = std::strlen(str);

    if (strLen >= maxSize) {
        maxSize = int(strLen) + 1;
        str = (char *) realloc(str, maxSize * sizeof(char));
    }
    return str;
}

IntValue::operator std::string() const {
    return this->operator char *();
}

IntValue::operator char() const {
    return char(*this->mData);
}

IntValue::operator FloatValue() const {
    return *this->mData;
}

IntValue::operator StringValue() const {
    return *this->mData;
}

bool IntValue::operator==(const IntValue &aOther) const {
    return *this->mData == *aOther.mData;

}

bool IntValue::operator==(const FloatValue &aOther) const {
    return *this->mData == *aOther.mData;

}

bool IntValue::operator==(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            return *this == *aOther.mData->i;
        case Value::TYPE_FLOAT:
            return *this == *aOther.mData->f;
        case Value::TYPE_NONE:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            return false;
    }
    return false;

}

bool IntValue::operator!=(const IntValue &aOther) const {
    return *this->mData != *aOther.mData;
}

bool IntValue::operator!=(const FloatValue &aOther) const {
    return *this->mData != *aOther.mData;
}

bool IntValue::operator!=(const Value &aOther) const {
    return !this->operator==(aOther);
}

bool IntValue::operator>(const IntValue &aOther) const {
    return *this->mData > *aOther.mData;
}

bool IntValue::operator>(const FloatValue &aOther) const {
    return *this->mData > *aOther.mData;
}

bool IntValue::operator>(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            return *this > *aOther.mData->i;
        case Value::TYPE_FLOAT:
            return *this > *aOther.mData->f;
        case Value::TYPE_NONE:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("int types cannot be compared with {} types").format({aOther.type()})));


}

bool IntValue::operator>=(const IntValue &aOther) const {
    return *this->mData >= *aOther.mData;
}

bool IntValue::operator>=(const FloatValue &aOther) const {
    return !this->operator<(aOther);
}

bool IntValue::operator>=(const Value &aOther) const {
    return !this->operator<(aOther);
}

bool IntValue::operator<(const IntValue &aOther) const {
    return *this->mData < *aOther.mData;
}

bool IntValue::operator<(const FloatValue &aOther) const {
    return *this->mData < *aOther.mData;
}

bool IntValue::operator<(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            return *this < *aOther.mData->i;
        case Value::TYPE_FLOAT:
            return *this < *aOther.mData->f;
        case Value::TYPE_NONE:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;

    }
    throw std::runtime_error(std::string(StringValue("int types cannot be compared with {} types").format({aOther.type()})));

}

bool IntValue::operator<=(const IntValue &aOther) const {
    return *this->mData <= *aOther.mData;
}

bool IntValue::operator<=(const FloatValue &aOther) const {
    return !this->operator>(aOther);
}

bool IntValue::operator<=(const Value &aOther) const {
    return !this->operator>(aOther);
}

IntValue &IntValue::operator=(const IntValue &aOther) {
    if (this == &aOther) {
        return *this;
    }
    this->~IntValue();
    this->int_ini(aOther);
    return *this;
}

IntValue &IntValue::operator=(const FloatValue &aOther) {
    this->~IntValue();
    this->int_ini(aOther);
    return *this;
}

IntValue IntValue::operator*(const IntValue &aOther) const {
    return (*this->mData) * (*aOther.mData);

}

FloatValue IntValue::operator*(const FloatValue &aOther) const {
    return double((*this->mData)) * (*aOther.mData);

}
Value IntValue::operator*(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            return *this * *aOther.mData->i;
        case Value::TYPE_FLOAT:
            return *this * *aOther.mData->f;
        case Value::TYPE_NONE:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"int\" and {}").format({aOther.type()})));


}
IntValue &IntValue::operator*=(const IntValue &aOther) {
    (*this->mData) *= (*aOther.mData);
    return *this;
}

IntValue &IntValue::operator*=(const FloatValue &aOther) {
    (*this->mData) = int(double(*this->mData) * (*aOther.mData));
    return *this;
}
IntValue & IntValue::operator*=(const Value &aOther){
    switch (aOther.mValueType) {
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            return *this *= *aOther.mData->i;
        case Value::TYPE_FLOAT:
            return *this *= *aOther.mData->f;
        case Value::TYPE_NONE:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"int\" and {}").format({aOther.type()})));

}
IntValue IntValue::operator/(const IntValue &aOther) const {
    return (*this->mData) / (*aOther.mData);
}

FloatValue IntValue::operator/(const FloatValue &aOther) const {
    return double(*this->mData) / (*aOther.mData);
}
Value IntValue::operator/(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            return *this / *aOther.mData->i;
        case Value::TYPE_FLOAT:
            return *this / *aOther.mData->f;
        case Value::TYPE_NONE:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"int\" and {}").format({aOther.type()})));

}
IntValue &IntValue::operator/=(const IntValue &aOther) {
    (*this->mData) /= (*aOther.mData);
    return *this;
}

IntValue &IntValue::operator/=(const FloatValue &aOther) {
    (*this->mData) = int(double(*this->mData) / (*aOther.mData));

    return *this;
}
IntValue & IntValue::operator/=(const Value &aOther){
    switch (aOther.mValueType) {
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            return *this /= *aOther.mData->i;
        case Value::TYPE_FLOAT:
            return *this /= *aOther.mData->f;
        case Value::TYPE_NONE:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"int\" and {}").format({aOther.type()})));

}

IntValue IntValue::operator+(const IntValue &aOther) const {
    return (*this->mData) + (*aOther.mData);
}

FloatValue IntValue::operator+(const FloatValue &aOther) const {
    return double(*this->mData) + (*aOther.mData);
}
Value IntValue::operator+(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            return *this + *aOther.mData->i;
        case Value::TYPE_FLOAT:
            return *this + *aOther.mData->f;
        case Value::TYPE_NONE:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"int\" and {}").format({aOther.type()})));
}
IntValue &IntValue::operator+=(const IntValue &aOther) {
    (*this->mData) += (*aOther.mData);
    return *this;
}

IntValue &IntValue::operator+=(const FloatValue &aOther) {
    (*this->mData) = int(double(*this->mData) + (*aOther.mData));
    return *this;
}
IntValue &IntValue::operator+=(const Value &aOther) {
    switch (aOther.mValueType) {

        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            *this+=*aOther.mData->i;
            break;
        case Value::TYPE_FLOAT:
            *this+=*aOther.mData->f;
            break;
        default:{
            throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"int\" and {}").format({aOther.type()})));
        }
    }
    return *this;
}
IntValue IntValue::operator-(const IntValue &aOther) const {
    return (*this->mData) - (*aOther.mData);
}

FloatValue IntValue::operator-(const FloatValue &aOther) const {
    return double(*this->mData) - (*aOther.mData);
}
Value IntValue::operator-(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            return *this - *aOther.mData->i;
        case Value::TYPE_FLOAT:
            return *this - *aOther.mData->f;
        case Value::TYPE_NONE:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"int\" and {}").format({aOther.type()})));
}
IntValue &IntValue::operator-=(const IntValue &aOther) {
    (*this->mData) -= (*aOther.mData);
    return *this;
}

IntValue &IntValue::operator-=(const FloatValue &aOther) {
    (*this->mData) = int(double(*this->mData) - (*aOther.mData));
    return *this;
}IntValue &IntValue::operator-=(const Value &aOther) {
    switch (aOther.mValueType) {
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            return *this -= *aOther.mData->i;
        case Value::TYPE_FLOAT:
            return *this -= *aOther.mData->f;
        case Value::TYPE_NONE:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"int\" and {}").format({aOther.type()})));

}