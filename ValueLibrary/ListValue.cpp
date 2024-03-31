////
//// Created by 32509 on 2024/1/8.
////
////
#include "ListValue.h"
//#include "StringValue.h"

std::ostream &operator<<(std::ostream &c, const ListValue &aListValue) {
    c << "[";
    if (aListValue.mDataCount != nullptr) {
        // NOLINTNEXTLINE
        ListValue::_ListTYPE::const_iterator listValueEnd = aListValue.mData->end() - 1;
        // NOLINTNEXTLINE
        for (ListValue::_ListTYPE::const_iterator listValueIndex = aListValue.mData->begin(); listValueIndex != listValueEnd; listValueIndex++) {
            c << **listValueIndex << ", ";
        }
        c << **listValueEnd;
    }
    c << "]";
    return c;
}

void ListValue::listValue_ini() {
    this->mData = new _ListTYPE;
    this->mDataCount = new int(1);
}

void ListValue::listValue_ini(const ListValue &aOther) {
    this->mData = aOther.mData;
    this->mDataCount = aOther.mDataCount;
    (*this->mDataCount)++;

}


ListValue::ListValue() {
    this->listValue_ini();
}

ListValue::ListValue(const std::initializer_list<Value> &aDatas) {
    this->mData = new _ListTYPE;
    this->mData->resize(aDatas.size());
    this->mDataCount = new int(1);
    // NOLINTNEXTLINE
    std::initializer_list<Value>::const_iterator datasIndex = aDatas.begin();
    // NOLINTNEXTLINE
    for (_ListTYPE::iterator thisDataIndex = this->mData->begin(); thisDataIndex != this->mData->end(); thisDataIndex++) {
        *thisDataIndex = new Value(*datasIndex);
        datasIndex++;
    }
}

ListValue::ListValue(const ListValue &aOther) {
    this->listValue_ini(aOther);
}

//ListValue::ListValue(const std::vector<Value> & aValue,...){
//    this->listValue_ini();
//    this->append(aValue); // 添加数据
//}
ListValue::~ListValue() {
    if (this->mData == nullptr) {
        return;
    }
    if (*this->mDataCount == 1) {
        // NOLINTNEXTLINE
        _ListTYPE::const_iterator listValueEnd = this->mData->end();
        // NOLINTNEXTLINE
        for (_ListTYPE::const_iterator listValueIndex = this->mData->begin(); listValueIndex != listValueEnd; listValueIndex++) {
            delete *listValueIndex;
        }
        if (this->mDataCount != nullptr) {
            this->mData->resize(0);
            delete this->mData;
            this->mData = nullptr;
        }

        if (this->mDataCount != nullptr) {
            delete this->mDataCount;
            this->mDataCount = nullptr;
        }

    } else {
        this->mData = nullptr;
        (*this->mDataCount)--;
        this->mDataCount = nullptr;
    }
}

int ListValue::length() const {
    return int(this->mData->size());
}

void ListValue::append(const Value &aValue) {
    this->mData->push_back(new Value(aValue));
}

void ListValue::insert(int pos, const Value &aValue) {
    int thisDataLenght = int(this->mData->size());
    if (pos < 0) {
        pos = thisDataLenght - pos;
        if (pos < 0) {
            pos = 0;
        }
    } else if (pos > thisDataLenght) {
        pos = thisDataLenght;
    }
    this->mData->insert(this->mData->begin() + pos, new Value(aValue));
}

void ListValue::extend(const ListValue &aOther) {
    int thisDataLength = int(this->mData->size());
    this->mData->resize(thisDataLength + aOther.mData->size());
    // NOLINTNEXTLINE
    _ListTYPE::iterator thisDataStart = this->mData->begin();
    // NOLINTNEXTLINE
    for (_ListTYPE::const_iterator otherIndex = aOther.mData->begin(); otherIndex != aOther.mData->end(); otherIndex++) {
        *thisDataStart = new Value(*otherIndex);
    }

}

void ListValue::remove(const Value &aValue) {
    // NOLINTNEXTLINE
    _ListTYPE::iterator thisDataRemoveIndex = this->mData->end();
    // NOLINTNEXTLINE
    for (_ListTYPE::iterator thisDataIndex = this->mData->begin(); thisDataIndex != this->mData->end(); thisDataIndex++) {
        if (**thisDataIndex == aValue) {
            thisDataRemoveIndex = thisDataIndex;
            break;
        }
    }

    if (thisDataRemoveIndex == this->mData->end()) {
        throw std::runtime_error("list.remove(" + std::string(aValue) + "): x not in list");
    }
    delete *thisDataRemoveIndex;
    // NOLINTNEXTLINE
    for (_ListTYPE::iterator thisDataIndex = thisDataRemoveIndex; thisDataIndex != this->mData->end(); thisDataIndex++) {
        *thisDataIndex = *(thisDataIndex + 1);
    }
    this->mData->resize(this->mData->size() - 1);
}

void ListValue::clear() {
    // NOLINTNEXTLINE
    for (_ListTYPE::iterator thisDataIndex = this->mData->begin(); thisDataIndex != this->mData->end(); thisDataIndex++) {
        delete *thisDataIndex;
    }
    this->mData->resize(0);
}

void ListValue::reverse() {
    // NOLINTNEXTLINE
    _ListTYPE::iterator thisDataEnd = this->mData->end();
    Value *temData;
    // NOLINTNEXTLINE
    for (_ListTYPE::iterator thisDataBegin = this->mData->begin();;) {
        temData = *thisDataBegin;
        *thisDataBegin = *thisDataEnd;
        *thisDataEnd = temData;
        thisDataBegin++;
        thisDataEnd--;
        if (thisDataEnd - thisDataBegin <= 0) {
            break;
        }
    }
}

int ListValue::index(const Value &aOther, unsigned int aStart, int aEnd) {
    if (aStart == this->mData->size()) {
        return -1;
    }
    int endNumber;

    if (aEnd < 0) {
        endNumber = int(this->mData->size()) + aEnd;
        if (endNumber < 0) {
            return -1;
        }
    } else {
        if (aEnd >= this->mData->size()) {
            endNumber = int(this->mData->size());
        } else {
            endNumber = aEnd;
        }
    }
    if (endNumber > aStart) {
        return -1;
    }

    // NOLINTNEXTLINE
    _ListTYPE::iterator thisDataBegin = this->mData->begin();
    // NOLINTNEXTLINE
    for (_ListTYPE::iterator thisDataIndex = this->mData->begin() + aStart; thisDataIndex != this->mData->begin() + endNumber; thisDataIndex++) {
        if (**thisDataIndex == aOther) {
            return int(thisDataIndex - thisDataBegin);
        }
    }
    return -1;
}

int ListValue::count(const Value &aOther, unsigned int aStart, int aEnd) {
    if (aStart == this->mData->size()) {
        return -1;
    }
    int endNumber;

    if (aEnd < 0) {
        endNumber = int(this->mData->size()) + aEnd;
        if (endNumber < 0) {
            return -1;
        }
    } else {
        if (aEnd >= this->mData->size()) {
            endNumber = int(this->mData->size());
        } else {
            endNumber = aEnd;
        }
    }
    if (endNumber > aStart) {
        return -1;
    }

    int valueCount=0;
    // NOLINTNEXTLINE
    for (_ListTYPE::iterator thisDataIndex = this->mData->begin() + aStart; thisDataIndex != this->mData->begin() + endNumber; thisDataIndex++) {
        if (**thisDataIndex == aOther) {
            valueCount++;
        }
    }
    return valueCount;

}

ListValue ListValue::indexOf(int pos) const {
    int thisDataLenght = int(this->mData->size());
    if (pos < 0) {
        pos = thisDataLenght - pos;
        if (pos < 0) {
            pos = 0;
        }
    } else if (pos > thisDataLenght) {
        pos = thisDataLenght;
    }
    ListValue resultDatas;

    resultDatas.mData->resize(thisDataLenght - pos);
    // NOLINTNEXTLINE
    _ListTYPE::iterator resultDataIndex = resultDatas.mData->begin();
    // NOLINTNEXTLINE
    for (_ListTYPE::const_iterator thisDataIndex = this->mData->begin() + pos; thisDataIndex != this->mData->end(); thisDataIndex++) {
        *resultDataIndex = new Value(**thisDataIndex);
        resultDataIndex++;
    }
    return resultDatas;
}

ListValue ListValue::indexOf(int pos, int end) const {
    int thisDataLenght = int(this->mData->size());
    if (end < 0) {
        end = thisDataLenght + pos;
        if (end < 0) {
            pos = 0;
        }
    } else if (end > thisDataLenght) {
        end = thisDataLenght;
    }
    if (pos < 0) {
        pos = thisDataLenght + pos;
        if (pos < 0) {
            pos = 0;
        }
    } else if (pos > thisDataLenght) {
        pos = thisDataLenght;
    }
    ListValue resultDatas;

    int length = end - pos;
    if (length < 0) {
        return resultDatas;
    }
    resultDatas.mData->resize(length);
    // NOLINTNEXTLINE
    _ListTYPE::iterator resultDataIndex = resultDatas.mData->begin();
    // NOLINTNEXTLINE
    for (_ListTYPE::const_iterator thisDataIndex = this->mData->begin() + pos; thisDataIndex != this->mData->begin() + end; thisDataIndex++) {
        *resultDataIndex = new Value(**thisDataIndex);
        resultDataIndex++;
    }
    return *this;
}

Value ListValue::pop(int aValueIndex) {
    int thisDataLenght = int(this->mData->size());
    if (aValueIndex < 0) {
        aValueIndex = thisDataLenght + aValueIndex;
        if (aValueIndex < 0) {
            throw std::runtime_error("IndexError: pop index out of range");
        }
    } else if (aValueIndex > thisDataLenght) {
        throw std::runtime_error("IndexError: pop index out of range");
    }
    // NOLINTNEXTLINE
    _ListTYPE::iterator popDataIndex = this->mData->begin() + aValueIndex;
    Value resultValue = **popDataIndex;
    delete *popDataIndex;
    // NOLINTNEXTLINE
    for (_ListTYPE::iterator thisDataIndex = popDataIndex; thisDataIndex != this->mData->end() - 1; thisDataIndex++) {
        *thisDataIndex = *(thisDataIndex + 1);
    }
    this->mData->resize(thisDataLenght - 1);
    return resultValue;
}

ListValue ListValue::copy() {
    ListValue newListValue;
    newListValue.mData->resize(this->mData->size());
    // NOLINTNEXTLINE
    _ListTYPE::const_iterator thisDataBegin = this->mData->begin();
    // NOLINTNEXTLINE
    for (_ListTYPE::iterator newListDataIndex = newListValue.mData->begin(); newListDataIndex != newListValue.mData->end(); newListDataIndex++) {
        *newListDataIndex = new Value(**thisDataBegin);
    }
    newListValue.mDataCount = new int(1);
    return newListValue;

}

Value &ListValue::operator[](const int &aIndex) {
    if (aIndex >= 0 and aIndex < int(this->mData->size())) {
        return *(*this->mData)[aIndex];
    }
    throw std::runtime_error("list index out of range");
}

ListValue::operator bool() const {
    if (this->mData->empty()) {
        return false;
    }
    return true;
}

ListValue::operator int() const {
    throw std::runtime_error("list cannot be converted to int");
}

ListValue::operator float() const {
    throw std::runtime_error("list cannot be converted to float");
}

ListValue::operator double() const {
    throw std::runtime_error("list cannot be converted to double");
}

ListValue::operator char *() const {
    return this->operator StringValue();
}

ListValue::operator std::string() const {
    return this->operator StringValue();
}

ListValue::operator char() const {
    throw std::runtime_error("list cannot be converted to char");
}

ListValue::operator StringValue() const {
    StringValue resultString = "[";
    if (!this->mData->empty()) {
        // NOLINTNEXTLINE
        ListValue::_ListTYPE::const_iterator listValueEnd = this->mData->end() - 1;
        // NOLINTNEXTLINE
        for (ListValue::_ListTYPE::const_iterator listValueIndex = this->mData->begin(); listValueIndex != listValueEnd; listValueIndex++) {
            resultString += (char *) (**listValueIndex);
            resultString += ", ";
        }
        resultString += (char *) (**listValueEnd);
    }
    resultString += "]";
    return resultString;
}

ListValue &ListValue::operator=(const ListValue &aOther) {
    if (this == &aOther) {
        return *this;
    }
    this->listValue_ini(aOther);
    return *this;
}

ListValue ListValue::operator+(const ListValue &aOther) const {
    ListValue newListValue;
    newListValue += *this;
    newListValue += aOther;
    return newListValue;
}

ListValue ListValue::operator+(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_LIST:
            return *this + *aOther.mData->l;
        case Value::TYPE_NONE:
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
        case Value::TYPE_FLOAT:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_DICT:
            break;

    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: \"list\" and {}").format({aOther.type()})));
}

ListValue &ListValue::operator+=(const ListValue &aOther) {
    int thisDataLength = int(this->mData->size());
    // NOLINTNEXTLINE
    _ListTYPE::iterator otherDataIndex = aOther.mData->begin();
    this->mData->resize(this->mData->size() + aOther.mData->size());
    // NOLINTNEXTLINE
    for (_ListTYPE::iterator thisDataIndex = this->mData->begin() + thisDataLength; thisDataIndex != this->mData->end(); thisDataIndex++) {
        *thisDataIndex = new Value(**otherDataIndex);
        otherDataIndex++;
    }
    return *this;
}

ListValue &ListValue::operator+=(const Value &aOther) {
    switch (aOther.mValueType) {
        case Value::DataType::TYPE_LIST:
            return *this += *aOther.mData->l;
        default: {
            throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +=: list and {}").format({aOther.type()})));
        }
    }
    return *this;
}


bool ListValue::operator==(const ListValue &aOther) const {
    if (this->mData->size() != aOther.mData->size()) {
        return false;
    }
    // NOLINTNEXTLINE
    ListValue::_ListTYPE::const_iterator otherValueIndex = aOther.mData->begin();
    // NOLINTNEXTLINE
    for (ListValue::_ListTYPE::const_iterator thisValueIndex = this->mData->begin(); thisValueIndex != this->mData->end(); thisValueIndex++) {
        if (**thisValueIndex != **otherValueIndex) {
            return false;
        }
    }
    return true;
}

bool ListValue::operator==(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_LIST:
            return *this == *aOther.mData->l;
        case Value::TYPE_NONE:
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
        case Value::TYPE_FLOAT:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_DICT:
            return false;

    }
    throw std::runtime_error("not errror");
}

bool ListValue::operator!=(const ListValue &aOther) const {
    return !this->operator==(aOther);
}

bool ListValue::operator>(const ListValue &aOther) const {
    // NOLINTNEXTLINE
    ListValue::_ListTYPE::const_iterator otherValueIndex = aOther.mData->begin();
    // NOLINTNEXTLINE
    for (ListValue::_ListTYPE::const_iterator thisValueIndex = this->mData->begin(); thisValueIndex != this->mData->end(); thisValueIndex++) {
        if (!(**thisValueIndex > **otherValueIndex)) {
            return false;
        }
    }
    return true;
}

bool ListValue::operator>(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_LIST:
            return *this > *aOther.mData->l;
        case Value::TYPE_NONE:
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
        case Value::TYPE_FLOAT:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("list types cannot be compared with {} types").format({aOther.type()})));
}

bool ListValue::operator<(const ListValue &aOther) const {
// NOLINTNEXTLINE
    ListValue::_ListTYPE::const_iterator otherValueIndex = aOther.mData->begin();
    // NOLINTNEXTLINE
    for (ListValue::_ListTYPE::const_iterator thisValueIndex = this->mData->begin(); thisValueIndex != this->mData->end(); thisValueIndex++) {
        if (!(**thisValueIndex < **otherValueIndex)) {
            return false;
        }
    }
    return true;
}

bool ListValue::operator<(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_LIST:
            return *this < *aOther.mData->l;
        case Value::TYPE_NONE:
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
        case Value::TYPE_FLOAT:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("list types cannot be compared with {} types").format({aOther.type()})));
}

