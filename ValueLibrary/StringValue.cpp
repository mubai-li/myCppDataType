//
// Created by 32509 on 2023/12/7.
//


#include "StringValue.h"


std::ostream &operator<<(std::ostream &c, const StringValue &aStringValue) {

    c << "\"";
    if (aStringValue.mData != nullptr) {
        // NOLINTNEXTLINE
        for (StringValue::_stringType::const_iterator stringValueBegin = aStringValue.mData->begin();
             stringValueBegin != aStringValue.mData->end(); stringValueBegin++) {
            c << **stringValueBegin;
        }
    }
    c << "\"";
    return c;
}

bool StringValue::isDigit() {
    return Tool::_StringIsDigit(*this->mData);
}

bool StringValue::isInt() {
    return Tool::_StringIsDigit(*this->mData, true);
}

Value StringValue::indexOf(int aPos) {
    int thisDataLenght = int(this->mData->size());
    if (aPos < 0) {
        aPos = thisDataLenght - aPos;
        if (aPos < 0) {
            aPos = 0;
        }
    } else if (aPos > thisDataLenght) {
        aPos = thisDataLenght;
    }
    StringValue resultStringValue;
    resultStringValue.mData = new StringValue::_stringType;
    resultStringValue.mData->resize(thisDataLenght - aPos);
    resultStringValue.mStringCount = new int(1);
    // NOLINTNEXTLINE
    StringValue::_stringType::iterator resultDataIndex = resultStringValue.mData->begin();
    // NOLINTNEXTLINE
    for (StringValue::_stringType::const_iterator thisDataIndex = this->mData->begin() + aPos;
         thisDataIndex != this->mData->end(); thisDataIndex++) {
        *resultDataIndex = new Value();
        (*resultDataIndex)->charValue_ini(**thisDataIndex);
        resultDataIndex++;
    }
    resultStringValue.mlength = Tool::_StringLength(*resultStringValue.mData);
    return resultStringValue;
}

Value StringValue::indexOf(int aPos, int aEnd) {
    int thisDataLenght = int(this->mData->size());
    if (aEnd < 0) {
        aEnd = thisDataLenght + aPos;
        if (aEnd < 0) {
            aPos = 0;
        }
    } else if (aEnd > thisDataLenght) {
        aEnd = thisDataLenght;
    }
    if (aPos < 0) {
        aPos = thisDataLenght - aPos;
        if (aPos < 0) {
            aPos = 0;
        }
    } else if (aPos > thisDataLenght) {
        aPos = thisDataLenght;
    }
    StringValue resultStringValue;

    int length = aEnd - aPos;
    if (length < 0) {
        return resultStringValue;
    }
    resultStringValue.mData->resize(length);
    // NOLINTNEXTLINE
    StringValue::_stringType::iterator resultDataIndex = resultStringValue.mData->begin();
    // NOLINTNEXTLINE
    for (StringValue::_stringType::const_iterator thisDataIndex = this->mData->begin() + aPos;
         thisDataIndex != this->mData->begin() + aEnd; thisDataIndex++) {
        *resultDataIndex = new Value();
        (*resultDataIndex)->charValue_ini(**thisDataIndex);
        resultDataIndex++;
    }
    resultStringValue.mlength = Tool::_StringLength(*resultStringValue.mData);

    return resultStringValue;
}

StringValue StringValue::format(const ListValue &aDatas) const {
    int datasLength = int(aDatas.mData->size());
    // NOLINTNEXTLINE
    ListValue::_ListTYPE::const_iterator datasBegin = aDatas.mData->begin();
    // NOLINTNEXTLINE
    ListValue::_ListTYPE::const_iterator datasEnd = aDatas.mData->end();

    ListValue stringList;
    stringList.mData->resize(datasLength);
    // NOLINTNEXTLINE
    ListValue::_ListTYPE::iterator stringListBegin = stringList.mData->begin();
    // NOLINTNEXTLINE
    ListValue::_ListTYPE::iterator stringListEnd = stringList.mData->end();
    // NOLINTNEXTLINE
    ListValue::_ListTYPE::iterator stringListIndex = stringListBegin;


    int allCount = 0;
    // NOLINTNEXTLINE
    for (ListValue::_ListTYPE::const_iterator datasIndex = datasBegin; datasIndex != datasEnd; datasIndex++) {
        StringValue newStringValue(**datasIndex);
        allCount += int(newStringValue.mData->size());
        *stringListIndex = new Value(newStringValue);
        stringListIndex++;
    }
    aDatas.~ListValue();
    stringListIndex = stringListBegin;

    StringValue resultString;
    resultString.mData = new StringValue::_stringType;
    resultString.mStringCount = new int(1);

    allCount += int(this->mData->size());
    resultString.mData->resize(allCount);
    // NOLINTNEXTLINE
    StringValue::_stringType::iterator resultStringIndex = resultString.mData->begin();
    // NOLINTNEXTLINE
    StringValue::_stringType::const_iterator thisDataEnd = this->mData->end();
    // NOLINTNEXTLINE
    for (StringValue::_stringType::const_iterator thisDataIndex = this->mData->begin();
         thisDataIndex != thisDataEnd; thisDataIndex++) {
        switch (*(*thisDataIndex)->mData->c->mData) {
            case '{': {
                thisDataIndex++;
                allCount--;
                if (thisDataIndex == this->mData->end()) {
                    throw std::runtime_error("Single '{' encountered in format string");
                }
                switch (*(*thisDataIndex)->mData->c->mData) {
                    case '{': {
                        *resultStringIndex = new Value();
                        (*resultStringIndex)->charValue_ini('{');
                        resultStringIndex++;
                        break;
                    }
                    case '}': {
                        allCount--;
                        if (stringListIndex == stringListEnd) {
                            throw std::runtime_error("Replacement index out ");
                        }
                        // NOLINTNEXTLINE
                        for (ListValue::_ListTYPE::const_iterator stringIndex = (*stringListIndex)->mData->s->mData->begin();
                             stringIndex != (*stringListIndex)->mData->s->mData->end(); stringIndex++) {
                            *resultStringIndex = new Value();
                            (*resultStringIndex)->charValue_ini(**stringIndex);
                            resultStringIndex++;
                        }
                        stringListIndex++;
                        break;

                    }
                    default:
                        throw std::runtime_error(&"key error"[*(*thisDataIndex)->mData->c->mData]);
                }
                break;

            }
            case '}': {
                thisDataIndex++;
                allCount--;
                if (thisDataIndex == this->mData->end()) {
                    throw std::runtime_error("Single '}' encountered in format string");
                }
                switch (*(*thisDataIndex)->mData->c->mData) {
                    case '}': {
                        *resultStringIndex = new Value();
                        (*resultStringIndex)->charValue_ini('}');
                        resultStringIndex++;
                        break;
                    }
                    default:
                        throw std::runtime_error("Single '}' encountered in format string");
                }
                break;

            }
            default: {
                *resultStringIndex = new Value();
                (*resultStringIndex)->charValue_ini(**thisDataIndex);
                resultStringIndex++;
            }
        }

    }
    resultString.mData->resize(allCount);

    resultString.mlength = Tool::_StringLength(*resultString.mData);

    return resultString;
}


StringValue StringValue::center(const int &aFillInNumber, const StringValue &aOther) {
    return Tool::_StringCenterCN(*this->mData, aFillInNumber, *aOther.mData);
}


StringValue StringValue::ljust(const int &aFillInNumber, const StringValue &aOther) {
    return Tool::_StringCenterCN(*this->mData, aFillInNumber, *aOther.mData, -1);
}


StringValue StringValue::rjust(const int &aFillInNumber, const StringValue &aOther) {
    return Tool::_StringCenterCN(*this->mData, aFillInNumber, *aOther.mData, 1);
}


int StringValue::count(const StringValue &aOther, const int &aStart, const int &aEnd) {
    return int(Tool::_StringFind(Tool::_StringIndexOf(*this->mData, aStart, aEnd), *aOther.mData).size());
}

bool StringValue::startWith(const StringValue &aOther) {
    return Tool::_StringStartWithString(*this->mData, *aOther.mData);
}


bool StringValue::endWith(const StringValue &aOther) {
    return Tool::_StringStartWithString(*this->mData, *aOther.mData, true);
}


StringValue StringValue::strip(const StringValue &aOther) {
    return Tool::_StringStrip(*this->mData, *aOther.mData, 0);
}


StringValue StringValue::lstrip(const StringValue &aOther) {
    return Tool::_StringStrip(*this->mData, *aOther.mData, -1);
}


StringValue StringValue::rstrip(const StringValue &aOther) {
    return Tool::_StringStrip(*this->mData, *aOther.mData, 1);
}


int StringValue::find(const StringValue &aOther, int aPos) {
    return Tool::_StringFindFirst(*this->mData, *aOther.mData, false, aPos, int(this->mData->size()));
}

int StringValue::find(const StringValue &aOther, int aPos, int aEnd) {
    return Tool::_StringFindFirst(*this->mData, *aOther.mData, false, aPos, aEnd);
}

int StringValue::rfind(const StringValue &aOther, int aPos) {
    return Tool::_StringFindFirst(*this->mData, *aOther.mData, true, aPos, int(this->mData->size()));

}

int StringValue::rfind(const StringValue &aOther, int aPos, int aEnd) {
    return Tool::_StringFindFirst(*this->mData, *aOther.mData, true, aPos, aEnd);

}


// replace 方法
StringValue StringValue::replace(const StringValue &aOther, const StringValue &aReplaceOther, const int &aMaxNumber) {

    return Tool::_StringReplace(*this->mData, *aOther.mData, *aReplaceOther.mData, aMaxNumber);
}


StringValue StringValue::rreplace(const StringValue &aOther, const StringValue &aReplaceOther, const int &aMaxNumber) {

    return Tool::_StringReplace(*this->mData, *aOther.mData, *aReplaceOther.mData, aMaxNumber, true);
}

int StringValue::length() const {
    return this->mlength;
}

StringValue::operator bool() const {
    return this->mlength;
}

StringValue::operator int() const {
    return Tool::_StringToInt(*this->mData);
}

StringValue::operator double() const {
    return Tool::_StringToDouble(*this->mData);
}

StringValue::operator float() const {
    return float(Tool::_StringToDouble(*this->mData));
}

StringValue::operator std::string() const {
    int resultStringSize = int(this->mData->size());
    std::string resultString;
    resultString.resize(resultStringSize);

    // NOLINTNEXTLINE
    StringValue::_stringType::const_iterator thisDataIndex = this->mData->begin();
    // NOLINTNEXTLINE
    for (std::string::iterator resultStringIndex = resultString.begin();
         resultStringIndex != resultString.end(); resultStringIndex++) {
        *resultStringIndex = char(**thisDataIndex);
        thisDataIndex++;
    }
    return resultString;
}

StringValue::operator char *() const {
    return const_cast<char *>(this->operator std::string().c_str());

}

StringValue::operator char() const {
    return *this->mData->at(0);
}

Value &StringValue::operator[](const int &aIndex) {
    return *this->mData->at(aIndex);
}

void StringValue::char_assign(const StringValue &aOther) {
    this->mData = aOther.mData;
    this->mStringCount = aOther.mStringCount;
    this->mlength = 1;
    (*this->mStringCount)++;
}


void StringValue::string_ini() {
    this->mData = new StringValue::_stringType;
    this->mStringCount = new int(1);
    this->mlength = 0;

}

void StringValue::string_ini(const std::string &aValue) {
    this->mData = new StringValue::_stringType;
    this->mData->resize(aValue.size());
    std::string::const_iterator valueIndex = aValue.begin();
    // NOLINTNEXTLINE
    for (StringValue::_stringType::iterator thisDataIndex = this->mData->begin();
         thisDataIndex != this->mData->end(); thisDataIndex++) {
        *thisDataIndex = new Value();
        (*thisDataIndex)->charValue_ini(*valueIndex);
        valueIndex++;
    }
    this->mlength = Tool::_StringLength(*this->mData);
    this->mStringCount = new int(1);

}

void StringValue::string_ini(const char *currentChar) {
    this->string_ini(std::string(currentChar));
}

void StringValue::string_ini(const char &aValue) {
    this->mData = new StringValue::_stringType;
    this->mData->resize(1);
//    (*this->mData->begin())->charValue_ini(aValue);
    *this->mData->begin() = new Value();
    (*this->mData->begin())->charValue_ini(aValue);
    this->mlength = Tool::_StringLength(*this->mData);
    this->mStringCount = new int(1);
}

void StringValue::string_ini(const StringValue &aOther) {
    this->mData = aOther.mData;
    this->mlength = aOther.mlength;
    this->mStringCount = aOther.mStringCount;
    (*this->mStringCount)++;
}

void StringValue::string_ini(const std::vector<Value *> &aValue) {
    this->mData = new StringValue::_stringType;
    this->mData->resize(aValue.size());
    // NOLINTNEXTLINE
    StringValue::_stringType::const_iterator valueIndex = aValue.begin();
    // NOLINTNEXTLINE
    for (StringValue::_stringType::iterator thisDataIndex = this->mData->begin();
         thisDataIndex != this->mData->end(); thisDataIndex++) {
        *thisDataIndex = new Value();
        (*thisDataIndex)->charValue_ini(**valueIndex);
        valueIndex++;
    }
    this->mlength = Tool::_StringLength(*this->mData);
    this->mStringCount = new int(1);
}

StringValue::StringValue(const std::vector<Value *> &aValue) {
    this->string_ini(aValue);

}

StringValue::StringValue() {
    this->mlength = 0;
}

StringValue::StringValue(std::nullptr_t) {
    this->mlength = 0;
}

StringValue::StringValue(const std::string &aValue) {
    this->string_ini(aValue);
}

StringValue::StringValue(const char *aValue) {
    this->string_ini(aValue);
}

StringValue::StringValue(const char &aValue) {
    this->string_ini(aValue);
}

StringValue::StringValue(const StringValue &aOther) {
    this->string_ini(aOther);
}


StringValue::StringValue(int aValue) {
    char buffer[20];
    sprintf(buffer, "%d", aValue);
    this->string_ini(buffer);
}

StringValue::StringValue(double aValue) {
    char buffer[64];
    snprintf(buffer, 64, "%.16g", aValue);
    this->string_ini(buffer);

}


StringValue::~StringValue() {
    if (this->mStringCount == nullptr) {
        return;
    }

    if (*this->mStringCount == 1) {
        // NOLINTNEXTLINE
        for (StringValue::_stringType::iterator thisDataIndex = this->mData->begin();
             thisDataIndex != this->mData->end(); thisDataIndex++) {
            delete *thisDataIndex;
        }

        delete this->mData;
        this->mData = nullptr;
        delete this->mStringCount;
        this->mStringCount = nullptr;
        this->mlength = 0;
    } else {
        (*this->mStringCount)--;
        this->mStringCount = nullptr;
        this->mData = nullptr;
        this->mlength = 0;
    }
}


StringValue &StringValue::operator=(const std::string &aValue) {
    this->~StringValue();
    this->string_ini(aValue);
    return *this;
}

StringValue &StringValue::operator=(const StringValue &aOther) {
    if (this == &aOther) {
        return *this;
    }
    this->~StringValue();
    this->string_ini(aOther);
    return *this;
}

StringValue &StringValue::operator=(const char *aValue) {
    this->~StringValue();
    this->string_ini(aValue);
    return *this;
}

StringValue &StringValue::operator=(const char &aValue) {
    this->~StringValue();
    this->string_ini(aValue);
    return *this;
}

StringValue &StringValue::operator+=(const std::string &aValue) {
    int thisDatamlength = int(this->mData->size());
    this->mData->resize(thisDatamlength + aValue.size());
    std::string::const_iterator valueIterator = aValue.begin();
    // NOLINTNEXTLINE
    for (StringValue::_stringType::iterator thisDataIterator = this->mData->begin() + thisDatamlength;
         thisDataIterator != this->mData->end(); thisDataIterator++) {
        *thisDataIterator = new Value();
        (*thisDataIterator)->charValue_ini(*valueIterator);

        valueIterator++;
    }
    mlength += Tool::_StringLength(*StringValue(aValue).mData);


    return *this;
}

// 阉割版本
//StringValue &StringValue::operator+=(const std::string &aValue) {
//    for(std::string::const_iterator valueIterator= aValue.begin();valueIterator!= aValue.end();valueIterator++){
//        this->mData->push_back(*valueIterator);
//    }
//    return *this;
//}
StringValue &StringValue::operator+=(const StringValue &aOther) {
    int thisDatamlength = int(this->mData->size());
    this->mData->resize(thisDatamlength + aOther.mData->size());
    // NOLINTNEXTLINE
    StringValue::_stringType::const_iterator valueIterator = aOther.mData->begin();
    // NOLINTNEXTLINE
    for (StringValue::_stringType::iterator thisDataIterator = this->mData->begin() + thisDatamlength;
         thisDataIterator != this->mData->end(); thisDataIterator++) {

        *thisDataIterator = new Value();
        (*thisDataIterator)->charValue_ini(**valueIterator);
        valueIterator++;
    }
    mlength += Tool::_StringLength(*aOther.mData);
    return *this;
}

StringValue &StringValue::operator+=(const char *aValue) {
    return this->operator+=(StringValue(aValue));
}

StringValue &StringValue::operator+=(const char &aValue) {
    return this->operator+=(StringValue(aValue));
}

StringValue &StringValue::operator+=(const Value &aOther) {
    switch (aOther.mValueType) {
        case Value::TYPE_CHAR:
            *this += StringValue(*aOther.mData->c);
            break;
        case Value::TYPE_STRING:
            *this += *aOther.mData->s;
            break;
        default: {
            throw std::runtime_error(
                    std::string(StringValue("unsupported operand type(s) for +: str and {}").format({aOther.type()})));

        }
    }
    return *this;
}

StringValue StringValue::operator+(char *aValue) const {
    return this->operator+(StringValue(aValue));
}

StringValue StringValue::operator+(const std::string &aValue) const {
    return this->operator+(StringValue(aValue));
}

StringValue StringValue::operator+(const StringValue &aOther) const {
    StringValue resultStringValue(*this);
    int thisDataLength = int(this->mData->size());
    // NOLINTNEXTLINE
    StringValue::_stringType::iterator otherStringIndex = aOther.mData->begin();
    resultStringValue.mData->resize(thisDataLength + aOther.mData->size());
    // NOLINTNEXTLINE
    for (StringValue::_stringType::iterator restStringIndex = resultStringValue.mData->begin() + thisDataLength;
         restStringIndex != resultStringValue.mData->end(); restStringIndex++) {
        *restStringIndex = new Value();
        (*restStringIndex)->charValue_ini((*otherStringIndex)->mData->c);
        otherStringIndex++;
    }
    return resultStringValue;
}

StringValue StringValue::operator+(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_CHAR:
            return *this + StringValue(*aOther.mData->c);
        case Value::TYPE_STRING:
            return *this + *aOther.mData->s;
        case Value::TYPE_NONE:
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
        case Value::TYPE_FLOAT:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(
            std::string(StringValue("unsupported operand type(s) for +: \"str\" and {}").format({aOther.type()})));
}

bool StringValue::compair(const StringValue &aOther, const CompairType &aCom) const {
    // NOLINTNEXTLINE
    StringValue::_stringType::const_iterator otherDataIndex = aOther.mData->begin();
    // NOLINTNEXTLINE
    StringValue::_stringType::const_iterator otherDataEnd = aOther.mData->end();
//    // NOLINTNEXTLINE
//    for (StringValue::_stringType::const_iterator thisDataIndex = this->mData->begin(); thisDataIndex != this->mData->end(); thisDataIndex++) {
//        if (!this->comSymbo(*(*thisDataIndex)->mData->c ,*(*otherDataIndex)->mData->c,aCom)){
//            return false;
//        }
//        otherDataIndex++;
//
//        if (otherDataIndex == otherDataEnd) {
//            return true;
//        }
//    }

    switch (aCom) {
        case ET: {
            if (this->mData->size() != aOther.mData->size()) {
                return false;
            }
            // NOLINTNEXTLINE
            for (StringValue::_stringType::const_iterator thisDataIndex = this->mData->begin();
                 thisDataIndex != this->mData->end(); thisDataIndex++) {
                if (!this->comSymbo(*(*thisDataIndex)->mData->c, *(*otherDataIndex)->mData->c, aCom)) {
                    return false;
                }
                otherDataIndex++;

                if (otherDataIndex == otherDataEnd) {
                    return true;
                }
            }
            throw std::runtime_error("str不能出现的问题");
        }
        case GT:
        case LT: {
            // NOLINTNEXTLINE
            for (StringValue::_stringType::const_iterator thisDataIndex = this->mData->begin();
                 thisDataIndex != this->mData->end(); thisDataIndex++) {
                if (this->comSymbo(*(*thisDataIndex)->mData->c, *(*otherDataIndex)->mData->c, aCom)) {
                    return true;
                } else if (*(*thisDataIndex)->mData->c == *(*otherDataIndex)->mData->c) {
                    otherDataIndex++;

                    if (otherDataIndex == otherDataEnd) {
                        int thisDataStep = int(this->mData->end() - thisDataIndex);
                        if (thisDataStep > 1) {
                            return true;
                        }
                        return false;
                    }
                } else {
                    return false;
                }

            }
            return false;
        }
    }
    throw std::runtime_error("qtawenti");
}

template<class T1>
bool StringValue::comSymbo(const T1 &aValue1, const T1 &aValue2, const CompairType &aCom) const {
    switch (aCom) {
        case CompairType::GT:
            return aValue1 > aValue2;
        case CompairType::LT:
            return aValue1 < aValue2;
        case CompairType::ET:
            return aValue1 == aValue2;
    }
    throw std::runtime_error("不可能报错");
}

bool StringValue::operator>(const StringValue &aOther) const {
    return this->compair(aOther, StringValue::CompairType::GT);
}

bool StringValue::operator>(const CharValue &aOther) const {
    return this->operator>(StringValue(aOther));
}

bool StringValue::operator>(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_CHAR:
            return *this > *aOther.mData->c;
        case Value::TYPE_STRING:
            return *this > *aOther.mData->s;
        case Value::TYPE_NONE:
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
        case Value::TYPE_FLOAT:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(
            std::string(StringValue("str types cannot be compared with {} types").format({aOther.type()})));

}

bool StringValue::operator>=(const StringValue &aOther) const {
    return !this->operator<(aOther);
}

bool StringValue::operator>=(const CharValue &aOther) const {
    return !this->operator<(aOther);

}

bool StringValue::operator>=(const Value &aOther) const {
    return !this->operator<(aOther);
}

bool StringValue::operator<(const StringValue &aOther) const {
    return this->compair(aOther, StringValue::CompairType::LT);

}

bool StringValue::operator<(const CharValue &aOther) const {
    return this->operator<(StringValue(aOther));


}

bool StringValue::operator<(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_CHAR:
            return *this < *aOther.mData->c;
        case Value::TYPE_STRING:
            return *this < *aOther.mData->s;
        case Value::TYPE_NONE:
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
        case Value::TYPE_FLOAT:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(
            std::string(StringValue("str types cannot be compared with {} types").format({aOther.type()})));
}

bool StringValue::operator<=(const StringValue &aOther) const {
    return !this->operator>(aOther);

}

bool StringValue::operator<=(const CharValue &aOther) const {
    return !this->operator>(aOther);

}

bool StringValue::operator<=(const Value &aOther) const {
    return !this->operator>(aOther);

}

bool StringValue::operator==(const StringValue &aOther) const {
    return this->compair(aOther, StringValue::CompairType::ET);

}

bool StringValue::operator==(const CharValue &aOther) const {
    return this->operator==(StringValue(aOther));
}

bool StringValue::operator==(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_CHAR:
            return *this == *aOther.mData->c;
        case Value::TYPE_STRING:
            return *this == *aOther.mData->s;
        case Value::TYPE_NONE:
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
        case Value::TYPE_FLOAT:
        case Value::TYPE_LIST:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(
            std::string(StringValue("str types cannot be compared with {} types").format({aOther.type()})));
}

bool StringValue::operator!=(const StringValue &aOther) const {
    return !this->operator==(aOther);

}


bool StringValue::operator!=(const CharValue &aOther) const {
    return !this->operator==(aOther);

}

bool StringValue::operator!=(const Value &aOther) const {
    return !this->operator==(aOther);

}

