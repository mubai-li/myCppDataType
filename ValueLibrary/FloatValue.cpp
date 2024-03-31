//
// Created by 32509 on 2023/12/25.
//

#include "FloatValue.h"

std::ostream &operator<<(std::ostream &c, const FloatValue &aFloatValue) {
    c << *aFloatValue.mData;
    return c;
}

void FloatValue::ini_ini(const double &aValue) {
    this->mData = new double(aValue);
    this->mDataCount = new int(1);

}

void FloatValue::ini_ini(const int &aValue) {
    this->mData = new double(aValue);
    this->mDataCount = new int(1);
}

void FloatValue::ini_ini(const float &aValue) {
    this->mData = new double(aValue);
    this->mDataCount = new int(1);
}

void FloatValue::ini_ini(const FloatValue &aOther) {
    this->mData = aOther.mData;
    this->mDataCount = aOther.mDataCount;
    (*this->mDataCount)++;
}

FloatValue::FloatValue() {
    this->ini_ini(0.0);
}

FloatValue::FloatValue(const double &aValue) {
    this->ini_ini(aValue);
}

FloatValue::FloatValue(const float &aValue) {
    this->ini_ini(aValue);
}

FloatValue::FloatValue(const int &aValue) {
    this->ini_ini(aValue);
}

FloatValue::FloatValue(const FloatValue &aOther) {
    this->ini_ini(aOther);
}

FloatValue::~FloatValue() {
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

FloatValue::operator bool() const {
    return bool(*this->mData);
}

FloatValue::operator int() const {
    return int(*this->mData);
}

FloatValue::operator double() const {
    return *this->mData;
}

FloatValue::operator float() const {
    return float(*this->mData);
}

FloatValue::operator char *() const {
    int maxSize = 20; // 11 个数字字符 + 1 个负号字符 + 1 个终止符 '\0'
    char *str = (char *) malloc(maxSize * sizeof(char));

    snprintf(str, maxSize, "%.6f", *this->mData);
    size_t strLen = std::strlen(str);

    if (strLen >= maxSize) {
        maxSize = int(strLen) + 1;
        str = (char *) realloc(str, maxSize * sizeof(char));
    }
    return str;
}

FloatValue::operator std::string() const {
    return this->operator char *();
}

FloatValue::operator char() const {
    throw std::runtime_error("could not convert float to char: " + this->operator std::string());
}

FloatValue::operator StringValue() const {
    return *this->mData;
}

FloatValue::operator IntValue() const {
    return int(*this->mData);
}

bool FloatValue::operator==(const IntValue &aOther) const {
    return *this->mData == *aOther.mData;
}

bool FloatValue::operator==(const FloatValue &aOther) const {
    return *this->mData == *aOther.mData;
}

bool FloatValue::operator==(const Value &aOther) const {
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
    throw std::runtime_error("FloatValue aOther Type");
}

bool FloatValue::operator!=(const IntValue &aOther) const {
    return !this->operator==(aOther);
}

bool FloatValue::operator!=(const FloatValue &aOther) const {
    return *this->mData != *aOther.mData;
}

bool FloatValue::operator!=(const Value &aOther) const {
    return !this->operator==(aOther);
}

bool FloatValue::operator>(const IntValue &aOther) const {
    return *this->mData > *aOther.mData;
}

bool FloatValue::operator>(const FloatValue &aOther) const {
    return *this->mData > *aOther.mData;
}

bool FloatValue::operator>(const Value &aOther) const {
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
    throw std::runtime_error(std::string(StringValue("float types cannot be compared with {} types").format({aOther.type()})));
}

bool FloatValue::operator>=(const IntValue &aOther) const {
    return !this->operator<(aOther);

}

bool FloatValue::operator>=(const FloatValue &aOther) const {
    return *this->mData >= *aOther.mData;

}

bool FloatValue::operator>=(const Value &aOther) const {
    return !this->operator<(aOther);
}

bool FloatValue::operator<(const IntValue &aOther) const {
    return *this->mData < *aOther.mData;

}

bool FloatValue::operator<(const FloatValue &aOther) const {
    return *this->mData < *aOther.mData;

}

bool FloatValue::operator<(const Value &aOther) const {
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
    throw std::runtime_error(std::string(StringValue("float types cannot be compared with {} types").format({aOther.type()})));

}

bool FloatValue::operator<=(const IntValue &aOther) const {
    return this->operator>(aOther);

}

bool FloatValue::operator<=(const FloatValue &aOther) const {
    return *this->mData <= *aOther.mData;

}

bool FloatValue::operator<=(const Value &aOther) const {
    return this->operator>(aOther);
}

FloatValue &FloatValue::operator=(const FloatValue &aOther) {
    if (this == &aOther) {
        return *this;
    }
    this->~FloatValue();
    this->ini_ini(aOther);
    return *this;
}

FloatValue &FloatValue::operator=(const IntValue &aOther) {
    this->~FloatValue();
    this->ini_ini(*aOther.mData);
    return *this;
}

FloatValue FloatValue::operator*(const FloatValue &aOther) const {
    return (*this->mData) * (*aOther.mData);
}

FloatValue FloatValue::operator*(const IntValue &aOther) const {
    return (*this->mData) * double(*aOther.mData);
}
Value FloatValue::operator*(const Value &aOther) const {
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
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"str\" and {}").format({aOther.type()})));

}
FloatValue &FloatValue::operator*=(const FloatValue &aOther) {
    (*this->mData) *= (*aOther.mData);
    return *this;
}

FloatValue &FloatValue::operator*=(const IntValue &aOther) {
    (*this->mData) = (*this->mData) * double(*aOther.mData);
    return *this;
}
FloatValue &FloatValue::operator*=(const Value &aOther) {
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
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"str\" and {}").format({aOther.type()})));

}

FloatValue FloatValue::operator/(const FloatValue &aOther) const {
    return (*this->mData) / (*aOther.mData);
}

FloatValue FloatValue::operator/(const IntValue &aOther) const {
    return (*this->mData) / double(*aOther.mData);
}
Value FloatValue::operator/(const Value &aOther) const {
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
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"str\" and {}").format({aOther.type()})));

}
FloatValue &FloatValue::operator/=(const FloatValue &aOther) {
    (*this->mData) /= (*aOther.mData);
    return *this;
}

FloatValue &FloatValue::operator/=(const IntValue &aOther) {
    (*this->mData) /= double(*aOther.mData);
    return *this;
}

FloatValue &FloatValue::operator/=(const Value &aOther) {
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
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"str\" and {}").format({aOther.type()})));

}

FloatValue FloatValue::operator+(const FloatValue &aOther) const {
    return (*this->mData) + (*aOther.mData);
}

FloatValue FloatValue::operator+(const IntValue &aOther) const {
    return (*this->mData) + double(*aOther.mData);
}

Value FloatValue::operator+(const Value &aOther) const {
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
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"str\" and {}").format({aOther.type()})));
}

FloatValue &FloatValue::operator+=(const FloatValue &aOther) {
    (*this->mData) += (*aOther.mData);
    return *this;
}

FloatValue &FloatValue::operator+=(const IntValue &aOther) {
    (*this->mData) += double(*aOther.mData);
    return *this;
}
FloatValue &FloatValue::operator+=(const Value &aOther) {
    switch (aOther.mValueType) {

        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
            *this+=*aOther.mData->i;
            break;
        case Value::TYPE_FLOAT:
            *this+=*aOther.mData->f;
            break;
        default:{
            throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"float\" and {}").format({aOther.type()})));
        }
    }
    return *this;
}

FloatValue FloatValue::operator-(const FloatValue &aOther) const {
    return (*this->mData) - (*aOther.mData);
}

FloatValue FloatValue::operator-(const IntValue &aOther) const {
    return (*this->mData) - double(*aOther.mData);
}

Value FloatValue::operator-(const Value &aOther) const {
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
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"str\" and {}").format({aOther.type()})));

}

FloatValue &FloatValue::operator-=(const FloatValue &aOther) {
    (*this->mData) -= (*aOther.mData);
    return *this;
}


FloatValue &FloatValue::operator-=(const IntValue &aOther) {
    (*this->mData) -= double(*aOther.mData);
    return *this;
}

FloatValue &FloatValue::operator-=(const Value &aOther) {
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
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"str\" and {}").format({aOther.type()})));

}