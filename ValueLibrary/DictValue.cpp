//
// Created by 32509 on 2024/1/8.
//

#include "DictValue.h"

std::ostream &operator<<(std::ostream &c, const DictValue &aDictValue) {
    c << '{';
//    aDictValue.mData->size()
    if (aDictValue.mData != nullptr and !aDictValue.mData->empty()) {
        int dictValueLength = int(aDictValue.mData->size());
        // NOLINTNEXTLINE
        DictValue::_DICTTYPE::const_iterator dataEnd = aDictValue.mData->end();
        // NOLINTNEXTLINE
        for (DictValue::_DICTTYPE::const_iterator dataIndex = aDictValue.mData->begin(); dataIndex != dataEnd;) {
            c << dataIndex->first << ": " << dataIndex->second;
            dictValueLength--;
            if (dictValueLength != 0) {
                c << ", ";
            }
            dataIndex++;


        }
    }
    c << '}';
    return c;
}
// 自定义哈希函数

std::size_t ValueHash::operator()(const Value &obj) const {
    // 自定义哈希算法，可以根据需要进行实现
    size_t hash = 0;
    switch (obj.mValueType) {
        case Value::DataType::TYPE_STRING: {
            // NOLINTNEXTLINE
            for (StringValue::_stringType::const_iterator stringIndex = obj.mData->s->mData->begin(); stringIndex != obj.mData->s->mData->end(); stringIndex++) {
                hash ^= std::hash<unsigned long long>()(*(*stringIndex)->mData->c->mData);
            }
            hash ^= std::hash<unsigned long long>()(obj.mValueType);
            return hash;
        }
        case Value::DataType::TYPE_CHAR: {
            hash ^= std::hash<char>()(*obj.mData->c->mData);
            hash ^= std::hash<unsigned long long>()(Value::DataType::TYPE_STRING);
            return hash;
        }
        case Value::DataType::TYPE_BOOL:
        case Value::DataType::TYPE_INT: {
            hash ^= std::hash<int>()(*obj.mData->i->mData);
            hash ^= std::hash<unsigned long long>()(obj.mValueType);
            return hash;
        }
        case Value::DataType::TYPE_FLOAT: {
            hash ^= std::hash<double>()(*obj.mData->f->mData);
            hash ^= std::hash<unsigned long long>()(obj.mValueType);
            return hash;
        }
        case Value::DataType::TYPE_NONE: {
            hash ^= std::hash<unsigned long long>()(obj.mValueType);
            return hash;
        }
        default: {
            throw std::runtime_error(std::string(StringValue("unhashable type: {}").format({obj.type()})));
        }
    }
}

bool ValueHash::operator()(const Value &a, const Value &b) const {
    return a == b;
}

void DictValue::dictValue_ini() {
    this->mData = new _DICTTYPE;
    this->mDataCount = new int(1);
}
void DictValue::dictValue_ini(const DictValue &aOther){
    this->mData = aOther.mData;
    this->mDataCount = aOther.mDataCount;
    (*this->mDataCount)++;
}

DictValue::DictValue() {
    this->dictValue_ini();

}
DictValue::DictValue(const DictValue &aOther){
    this->dictValue_ini(aOther);
}

DictValue::~DictValue() {
    if (this->mDataCount != nullptr) {
        if(*this->mDataCount == 1){
            delete this->mData;
            this->mData = nullptr;
            delete this->mDataCount;
            this->mDataCount = nullptr;
        }else{
            (*this->mDataCount)--;
            this->mData = nullptr;
            this->mDataCount = nullptr;
        }
    }

}

bool DictValue::setDefault(const Value &key, const Value &value) {
    if (this->mData->find(key) == this->mData->end()) {
        this->mData->insert(std::make_pair(key, value));
        return true;
    }
    return false;
}

void DictValue::changeOrSetDefault(const Value &key, const Value &value) {
    (*this->mData)[key] = value;
}

Value DictValue::get(const Value &key) {
    if (this->mData->find(key) == this->mData->end()) {
        return nullptr;
    }
    return this->mData->at(key);
}

Value DictValue::pop(const Value &key) {
    if (this->mData->find(key) == this->mData->end()) {
        throw std::runtime_error(std::string(StringValue("KeyError {}").format({key})));
    }
    Value result = this->mData->at(key);
    this->mData->extract(key);
    return result;
}
Value & DictValue::operator[](const Value &key){
    return this->mData->at(key);
}
bool DictValue::operator==(const Value &aOther) const {
    switch (aOther.mValueType) {
        case Value::TYPE_NONE:
        case Value::TYPE_BOOL:
        case Value::TYPE_INT:
        case Value::TYPE_FLOAT:
        case Value::TYPE_CHAR:
        case Value::TYPE_STRING:
        case Value::TYPE_LIST:
            return false;
        case Value::TYPE_DICT: {
            return *this->mData == *aOther.mData->d->mData;
        }
    }
    throw std::runtime_error(std::string(StringValue("not have {} type").format({aOther.type()})));

}

bool DictValue::operator>(const Value &aOther) const {
    throw std::runtime_error(std::string(StringValue("dict types cannot be compared with {} types").format({aOther.type()})));
}


bool DictValue::operator<(const Value &aOther) const {
    throw std::runtime_error(std::string(StringValue("dict types cannot be compared with {} types").format({aOther.type()})));
}