
#include "tool/tool.h"

//#include "IntValue.h"
//#include "FloatValue.h"
//#include "StringValue.h"
//#include "ListValue.h"
//#include "DictValue.h"


std::ostream &operator<<(std::ostream &c, const Value &aValue) {
    switch (aValue.mValueType) {
        case Value::TYPE_NONE:
            c << "None";
            break;
        case Value::TYPE_BOOL:
            c << (aValue.mData->i ? "True" : "False");
            break;
        case Value::TYPE_INT:
            c << *aValue.mData->i;
            break;
        case Value::TYPE_FLOAT:
            c << *aValue.mData->f;
            break;
        case Value::TYPE_STRING:
            c << *aValue.mData->s;
            break;
        case Value::TYPE_LIST:
            c << *aValue.mData->l;
            break;
        case Value::TYPE_CHAR:
            c << *aValue.mData->c;
            break;
        case Value::TYPE_DICT:
            c << *aValue.mData->d;
            break;
    }
    return c;
}

bool Value::noneComSymbo(const Value &aOther, const CompairType &aCom) {
    switch (aOther.mValueType) {
        case DataType::TYPE_NONE: {
            switch (aCom) {
                case ET:
                    return true;
                case GT:
                case LT:
                    throw std::runtime_error("None can't compair None");
            }
        }
        case DataType::TYPE_BOOL:
        case DataType::TYPE_CHAR:
        case DataType::TYPE_INT:
        case DataType::TYPE_FLOAT:
        case DataType::TYPE_STRING:
        case DataType::TYPE_LIST:
        case DataType::TYPE_DICT:
            switch (aCom) {
                case ET:
                    return false;
                case GT:
                case LT:
                    throw std::runtime_error("None can't compair None");
            }
    }
    throw std::runtime_error("other error");
}

template<class T>
bool Value::comSymbo(const T &aOther, const Value &aNext, const CompairType &aCom) {
    switch (aCom) {
        case ET:
            return aOther == aNext;
        case GT:
            return aOther > aNext;
        case LT:
            return aOther < aNext;
    }
    throw std::runtime_error("not have this compairType");
}

bool Value::compair(const Value &aOther, const Value &aNext, const CompairType &aCom) {
    switch (aOther.mValueType) {
        case TYPE_NONE:
            return noneComSymbo(aNext, aCom);
        case TYPE_BOOL:
        case TYPE_INT:
            return Value::comSymbo(*aOther.mData->i, aNext, aCom);
        case TYPE_CHAR:
            return Value::comSymbo(*aOther.mData->c, aNext, aCom);
        case TYPE_FLOAT:
            return Value::comSymbo(*aOther.mData->f, aNext, aCom);
        case TYPE_STRING:
            return Value::comSymbo(*aOther.mData->s, aNext, aCom);
        case TYPE_LIST:
            return Value::comSymbo(*aOther.mData->l, aNext, aCom);
        case TYPE_DICT:
            return Value::comSymbo(*aOther.mData->d, aNext, aCom);
    }
    throw std::runtime_error("not this type");
}

void Value::boolValue_ini(const bool &aValue) {
    this->mData = new Data;
    this->mData->i = new IntValue(aValue);
    this->mValueType = DataType::TYPE_BOOL;
}

void Value::intValue_ini(const int &aValue) {
    this->mData = new Data;
    this->mData->i = new IntValue(aValue);
    this->mValueType = DataType::TYPE_INT;
}

void Value::charValue_ini(const char &aValue) {
    this->mData = new Data;
    this->mData->c = new CharValue(aValue);
    this->mValueType = DataType::TYPE_CHAR;

}

void Value::charValue_ini(const Value &aOther) {
    this->mData = new Data;
    this->mData->c = new CharValue(*aOther.mData->c);
    this->mValueType = DataType::TYPE_CHAR;

}

void Value::floatValue_ini(const float &aValue) {
    this->mData = new Data;
    this->mData->f = new FloatValue(aValue);
    this->mValueType = DataType::TYPE_FLOAT;

}


void Value::doubleValue_ini(const double &aValue) {
    this->mData = new Data;
    this->mData->f = new FloatValue(aValue);
    this->mValueType = DataType::TYPE_FLOAT;

}

void Value::stringValue_ini(const std::string &aValue) {
    this->mData = new Data;
    this->mData->s = new StringValue(aValue);
    this->mValueType = DataType::TYPE_STRING;

}

void Value::stringValue_ini(const char *aValue) {
    this->mData = new Data;
    this->mData->s = new StringValue(aValue);
    this->mValueType = DataType::TYPE_STRING;

}

void Value::stringValue_ini(const char &aValue) {
    this->mData = new Data;
    this->mData->s = new StringValue(aValue);
    this->mValueType = DataType::TYPE_STRING;

}

void Value::stringValue_ini(const StringValue &aValue) {
    this->mData = new Data;
    this->mData->s = new StringValue(aValue);
    this->mValueType = DataType::TYPE_STRING;
}

void Value::dictValue_ini(const DictValue &aOther) {
    this->mData = new Data;
    this->mData->d = new DictValue(aOther);
    this->mValueType = DataType::TYPE_DICT;
}

void Value::listValue_ini(const ListValue &aValue) {
    this->mData = new Data;
    this->mData->l = new ListValue(aValue);
    this->mValueType = DataType::TYPE_LIST;
}

void Value::listValue_ini(const std::initializer_list<Value> &aDatas) {
    this->mData = new Data;
    this->mData->l = new ListValue(aDatas);
    this->mValueType = DataType::TYPE_LIST;

}

void Value::value_ini(const IntValue &aOther) {
    this->mData = new Data;
    this->mData->i = new IntValue(aOther);
    this->mValueType = DataType::TYPE_INT;
}

void Value::value_ini(const FloatValue &aOther) {
    this->mData = new Data;
    this->mData->f = new FloatValue(aOther);
    this->mValueType = DataType::TYPE_FLOAT;
}

void Value::value_ini(const StringValue &aOther) {
    this->mData = new Data;
    this->mData->s = new StringValue(aOther);
    this->mValueType = DataType::TYPE_STRING;
}

void Value::value_ini(const ListValue &aOther) {
    this->mData = new Data;
    this->mData->l = new ListValue(aOther);
    this->mValueType = DataType::TYPE_LIST;
}

void Value::value_ini(const CharValue &aOther) {
    this->mData = new Data;
    this->mData->c = new CharValue(aOther);
    this->mValueType = DataType::TYPE_CHAR;
}

void Value::value_ini(const DictValue &aOther) {
    this->mData = new Data;
    this->mData->d = new DictValue(aOther);
    this->mValueType = DataType::TYPE_DICT;
}

void Value::value_ini(const Value &aOther) {
    switch (aOther.mValueType) {
        case DataType::TYPE_NONE:
            this->mValueType = aOther.mValueType;
            break;
        case DataType::TYPE_BOOL:
        case DataType::TYPE_INT:
            this->value_ini(*aOther.mData->i);
            this->mValueType = aOther.mValueType;
            break;
        case DataType::TYPE_FLOAT:
            this->value_ini(*aOther.mData->f);
            break;
        case DataType::TYPE_STRING:
            this->value_ini(*aOther.mData->s);
            break;
        case DataType::TYPE_LIST:
            this->value_ini(*aOther.mData->l);
            break;
        case DataType::TYPE_CHAR:
            this->stringValue_ini(aOther.mData->c->operator char());
            break;
        case DataType::TYPE_DICT:
            this->dictValue_ini(*aOther.mData->d);
            break;
    }

}

Value::Value() {
    this->mValueType = DataType::TYPE_NONE;
}
//Value::Value(const char &aValue,int){
//    this->charValue_ini(aValue);
//}

Value::Value(std::nullptr_t) {
    this->mValueType = DataType::TYPE_NONE;
}

Value::Value(const bool &aValue) {
    this->boolValue_ini(aValue);
}

Value::Value(const int &aValue) {
    this->intValue_ini(aValue);
}

Value::Value(const float &aValue) {
    this->floatValue_ini(aValue);
}

Value::Value(const double &aValue) {
    this->doubleValue_ini(aValue);
}

Value::Value(const std::string &aValue) {
    this->stringValue_ini(aValue);
}

Value::Value(const char *aValue) {
    this->stringValue_ini(aValue);
}

Value::Value(const char &aOther) {
    this->stringValue_ini(aOther);
}

Value::Value(const std::initializer_list<Value> &aDatas) {
    this->listValue_ini(aDatas);
}

Value::Value(const IntValue &aOther) {
    this->value_ini(aOther);
}

Value::Value(const FloatValue &aOther) {
    this->value_ini(aOther);
}

Value::Value(const StringValue &aOther) {
    this->value_ini(aOther);
}

Value::Value(const ListValue &aOther) {
    this->value_ini(aOther);
}

Value::Value(const CharValue &aOther) {
    this->value_ini(aOther);
}

Value::Value(const DictValue &aOther) {
    this->value_ini(aOther);
}

Value::Value(const Value &aOther) {
    this->value_ini(aOther);
}

Value::~Value() {
    switch (this->mValueType) {
        case DataType::TYPE_NONE:
            break;
        case DataType::TYPE_BOOL:
        case DataType::TYPE_INT:
            delete this->mData->i;
            break;
        case DataType::TYPE_FLOAT:
            delete this->mData->f;
            break;
        case DataType::TYPE_STRING:
            delete this->mData->s;
            break;
        case DataType::TYPE_LIST:
            delete this->mData->l;
            break;
        case DataType::TYPE_CHAR:
            delete this->mData->c;
            break;
        case DataType::TYPE_DICT:
            delete this->mData->d;
            break;
    }
    if (this->mData != nullptr) {
        delete this->mData;
        this->mData = nullptr;
    }
    this->mValueType = TYPE_NONE;
}

int Value::length() const {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->length();
        case DataType::TYPE_LIST:
            return this->mData->l->length();
        default:
            break;

    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'length'").format({this->type()})));
}

void Value::append(const Value &aValue) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            this->mData->l->append(aValue);
            return;
        default:
            break;

    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'append'").format({this->type()})));

}

void Value::insert(int aPos, const Value &aValue) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            this->mData->l->insert(aPos, aValue);
            return;
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'insert'").format({this->type()})));

}

void Value::extend(const ListValue &aOther) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            this->mData->l->extend(aOther);
            return;
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'extend'").format({this->type()})));

}

void Value::remove(const Value &aOther) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            this->mData->l->remove(aOther);
            return;
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'remove'").format({this->type()})));

}

void Value::clear() {

    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            this->mData->l->clear();
            return;
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'clear'").format({this->type()})));

}

void Value::reverse() {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            this->mData->l->reverse();
            return;
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'reverse'").format({this->type()})));

}

int Value::index(const Value &aOther, const int &aPos, const int &aEnd) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:

            return this->mData->l->index(aOther, aPos, aEnd);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'index'").format({this->type()})));

}

int Value::count(const Value &aOther, const int &aPos, const int &aEnd) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->count(aOther.getStringValue(), aPos, aEnd);
        case DataType::TYPE_LIST:
            return this->mData->l->count(aOther, aPos, aEnd);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'count'").format({this->type()})));

}

Value Value::indexOf(int aPos) const {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->indexOf(aPos);
        case DataType::TYPE_LIST:

            return this->mData->l->indexOf(aPos);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'indexOf'").format({this->type()})));

}

Value Value::indexOf(int aPos, int aEnd) const {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->indexOf(aPos, aEnd);
        case DataType::TYPE_LIST:

            return this->mData->l->indexOf(aPos, aEnd);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'indexOf'").format({this->type()})));
}

Value Value::pop(const Value &aValue) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            return this->mData->l->pop(aValue);
        case DataType::TYPE_DICT:
            return this->mData->d->pop(aValue);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'pop'").format({this->type()})));
}

Value Value::pop(const int &aValue) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            return this->mData->l->pop(aValue);
        case DataType::TYPE_DICT:
            return this->mData->d->pop(aValue);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'pop'").format({this->type()})));

}

Value Value::pop(const float &aValue) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            throw std::runtime_error(std::string(StringValue("{} pop canr't use [{}]").format({this->type(), aValue})));

        case DataType::TYPE_DICT:
            return this->mData->d->pop(aValue);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'pop'").format({this->type()})));

}

Value Value::pop(const double &aValue) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            throw std::runtime_error(std::string(StringValue("{} pop canr't use [{}]").format({this->type(), aValue})));

        case DataType::TYPE_DICT:
            return this->mData->d->pop(aValue);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'pop'").format({this->type()})));

}

Value Value::pop(const char &aValue) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            throw std::runtime_error(std::string(StringValue("{} pop canr't use [\"{}\"]").format({this->type(), aValue})));

        case DataType::TYPE_DICT:
            return this->mData->d->pop(aValue);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'pop'").format({this->type()})));

}

Value Value::pop(const char *aValue) {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            throw std::runtime_error(std::string(StringValue("{} pop canr't use [\"{}\"]").format({this->type(), aValue})));

        case DataType::TYPE_DICT:
            return this->mData->d->pop(aValue);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'pop'").format({this->type()})));

}

Value Value::copy() {
    switch (this->mValueType) {
        case DataType::TYPE_LIST:
            return this->mData->l->copy();
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'copy'").format({this->type()})));
}

Value Value::format(const ListValue &aDatas) const {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->format(aDatas);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'format'").format({this->type()})));

}

Value Value::center(const int &aFillInNumber, const Value &aOther) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->center(aFillInNumber, aOther.getStringValue());
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'center'").format({this->type()})));

}

Value Value::ljust(const int &aFillInNumber, const Value &aOther) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->ljust(aFillInNumber, aOther.getStringValue());
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'ljust'").format({this->type()})));

}

Value Value::rjust(const int &aFillInNumber, const Value &aOther) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->rjust(aFillInNumber, aOther.getStringValue());
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'rjust'").format({this->type()})));
}

bool Value::startWith(const Value &aOther) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->startWith(aOther.getStringValue());
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'startWith'").format({this->type()})));
}

bool Value::endWith(const Value &aOther) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->endWith(aOther.getStringValue());
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'endWith'").format({this->type()})));

}

Value Value::strip(const Value &aOther) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->strip(aOther.getStringValue());
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'strip'").format({this->type()})));
}

Value Value::lstrip(const Value &aOther) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->lstrip(aOther.getStringValue());
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'lstrip'").format({this->type()})));

}

Value Value::rstrip(const Value &aOther) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->rstrip(aOther.getStringValue());
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'rstrip'").format({this->type()})));

}

int Value::find(const Value &aOther, int aPos) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->find(aOther.getStringValue(), aPos);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'find'").format({this->type()})));
}

int Value::find(const Value &aOther, int aPos, int aEnd) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->find(aOther.getStringValue(), aPos, aEnd);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'find'").format({this->type()})));
}

int Value::rfind(const Value &aOther, int aPos) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->rfind(aOther.getStringValue(), aPos);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'rfind'").format({this->type()})));
}

int Value::rfind(const Value &aOther, int aPos, int aEnd) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->rfind(aOther.getStringValue(), aPos, aEnd);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'rfind'").format({this->type()})));
}

Value Value::replace(const Value &aOther, const Value &aReplaceOther, const int &aMaxNumber) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->replace(aOther.getStringValue(), aReplaceOther.getStringValue(), aMaxNumber);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'replace'").format({this->type()})));

}

Value Value::rreplace(const Value &aOther, const Value &aReplaceOther, const int &aMaxNumber) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->rreplace(aOther.getStringValue(), aReplaceOther.getStringValue(), aMaxNumber);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'rreplace'").format({this->type()})));

}

bool Value::isDigit() {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->isDigit();
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'isDigit'").format({this->type()})));

}

bool Value::isInt() {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->isInt();
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'isInt'").format({this->type()})));

}

Value Value::get(const Value &key) {
    switch (this->mValueType) {
        case DataType::TYPE_DICT:
            return this->mData->d->get(key);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'get'").format({this->type()})));
}


void Value::changeOrSetDefault(const Value &key, const Value &value) {
    switch (this->mValueType) {
        case DataType::TYPE_DICT:
            return this->mData->d->changeOrSetDefault(key, value);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'changeOrSetDefault'").format({this->type()})));
}

bool Value::setDefault(const Value &key, const Value &value) {
    switch (this->mValueType) {
        case DataType::TYPE_DICT:
            return this->mData->d->setDefault(key, value);
        default:
            break;
    }
    throw std::runtime_error(std::string(StringValue("'{}' object has no attribute 'setDefault'").format({this->type()})));
}

Value Value::type() const {
    switch (this->mValueType) {
        case DataType::TYPE_NONE:
            return "NoneType";
        case DataType::TYPE_BOOL:
            return "bool";
        case DataType::TYPE_INT:
            return "int";
        case DataType::TYPE_FLOAT:
            return "float";
        case DataType::TYPE_CHAR:
        case DataType::TYPE_STRING:
            return "str";
        case DataType::TYPE_LIST:
            return "list";
        case DataType::TYPE_DICT:
            return "dict";
    }
    throw std::runtime_error("type error");
}


bool Value::comparerType(const DataType &aDataType) {
    return this->mValueType == aDataType;
}

template<class transfromType>
transfromType Value::_transfromType(const std::string &aErrorType) const {
    switch (this->mValueType) {
        case DataType::TYPE_NONE:
            throw std::runtime_error("'NoneType' can't  be a " + aErrorType + "()");
        case DataType::TYPE_BOOL:
        case DataType::TYPE_INT:
            return transfromType(*this->mData->i);
        case DataType::TYPE_FLOAT:
            return transfromType(*this->mData->f);
        case DataType::TYPE_CHAR:
            return transfromType(*this->mData->c);
        case DataType::TYPE_STRING:
            return transfromType(*this->mData->s);
        case DataType::TYPE_LIST:
            return transfromType(*this->mData->l);
        case DataType::TYPE_DICT:
            throw std::runtime_error("'dict' can't be a" + aErrorType + "()");

    }
    throw std::runtime_error("_transfromType type error");
}


StringValue &Value::getStringValue() const {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return *this->mData->s;
        default:
            throw std::runtime_error("it must is str type");
    }
}

Value::operator bool() const {
    switch (this->mValueType) {
        case DataType::TYPE_NONE:
            return false;
        default:
            return this->_transfromType<bool>();
    }
}

Value::operator int() const {
    return this->_transfromType<int>("int");
}


Value::operator double() const {
    return this->_transfromType<double>("double");
}

Value::operator float() const {
    return this->_transfromType<float>("float");
}

Value::operator char *() const {
    return this->_transfromType<char *>("char *");
}

Value::operator std::string() const {
    return this->_transfromType<std::string>("std::string");
}

Value::operator char() const {
    return this->_transfromType<char>("char");
}

Value::operator IntValue() const {
    switch (this->mValueType) {
        case TYPE_BOOL:
        case TYPE_INT:
            return *this->mData->i;
        case TYPE_FLOAT:
            return *this->mData->f;
        default: {
            throw std::runtime_error("can't change");
        }
    }
}

Value::operator FloatValue() const {
    switch (this->mValueType) {
        case TYPE_BOOL:
        case TYPE_INT:
            return *this->mData->i;
        case TYPE_FLOAT:
            return *this->mData->f;
        default: {
            throw std::runtime_error("can't change");
        }
    }
}

Value::operator StringValue() const {
    switch (this->mValueType) {
        case TYPE_NONE:
            return "None";
        case TYPE_BOOL:
            return *this->mData->i ? "True" : "False";
        case TYPE_INT:
            return *this->mData->i;
        case TYPE_FLOAT:
            return *this->mData->f;
        case TYPE_CHAR:
            return *this->mData->c;
        case TYPE_STRING:
            return *this->mData->s;
        case TYPE_LIST:
            return *this->mData->l;
        default: {
            throw std::runtime_error("can't change");
        }
    }
}

Value::operator ListValue() const {
    std::cout << "数据" << std::endl;
    std::cout << *this << std::endl;
    switch (this->mValueType) {
        case TYPE_LIST:
            return *this->mData->l;
        default: {
            throw std::runtime_error("can't change");
        }
    }
}

Value::operator CharValue &() const {
    switch (this->mValueType) {
        case DataType::TYPE_CHAR:
            return *this->mData->c;
        default: {
            throw std::runtime_error("is not char type");
        }

    }
}

Value &Value::operator[](const Value &aIndex) {

    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->operator[](aIndex);
        case DataType::TYPE_LIST:
            return this->mData->l->operator[](aIndex);
        case DataType::TYPE_DICT:
            return this->mData->d->operator[](aIndex);
        default: {
            break;
        }

    }
    throw std::runtime_error(std::string(this->type() += " canr't use []"));
}

Value &Value::operator[](const int &aIndex) {
    switch (this->mValueType) {
        case DataType::TYPE_STRING:
            return this->mData->s->operator[](aIndex);
        case DataType::TYPE_LIST:
            return this->mData->l->operator[](aIndex);
        case DataType::TYPE_DICT:
            return this->mData->d->operator[](aIndex);
        default: {
            break;
        }

    }
    throw std::runtime_error(std::string(StringValue("{} canr't use [{}]").format({this->mValueType, aIndex})));

}

Value &Value::operator[](const float &aIndex) {
    switch (this->mValueType) {
        case DataType::TYPE_DICT:
            return this->mData->d->operator[](aIndex);
        default: {
            break;
        }

    }
    throw std::runtime_error(std::string(StringValue("{} canr't use [{}]").format({this->mValueType, aIndex})));
}

Value &Value::operator[](const double &aIndex) {
    switch (this->mValueType) {
        case DataType::TYPE_DICT:
            return this->mData->d->operator[](aIndex);
        default: {
            break;
        }

    }
    throw std::runtime_error(std::string(StringValue("{} canr't use [{}]").format({this->mValueType, aIndex})));

}

Value &Value::operator[](const char &aIndex) {
    switch (this->mValueType) {
        case DataType::TYPE_DICT:
            return this->mData->d->operator[](aIndex);
        default: {
            break;
        }

    }
    throw std::runtime_error(std::string(StringValue("{} canr't use [{}]").format({this->mValueType, aIndex})));
}

Value &Value::operator[](const char *aIndex) {
    switch (this->mValueType) {
        case DataType::TYPE_DICT:
            return this->mData->d->operator[](aIndex);
        default: {
            break;
        }
    }
    throw std::runtime_error(std::string(StringValue("{} canr't use [{}]").format({this->mValueType, aIndex})));
}

Value &Value::operator=(const Value &aOther) {
    if (this == &aOther) {
        return *this;
    }
    this->~Value();
    switch (aOther.mValueType) {
        case DataType::TYPE_NONE:
            break;
        case DataType::TYPE_BOOL:
            this->boolValue_ini(*aOther.mData->i);
            break;
        case DataType::TYPE_INT:
            this->intValue_ini(*aOther.mData->i);
            break;
        case DataType::TYPE_FLOAT:
            this->doubleValue_ini(*aOther.mData->f);
            break;
        case DataType::TYPE_STRING:
            this->stringValue_ini(*aOther.mData->s);
            break;
        case DataType::TYPE_LIST:
            this->listValue_ini(*aOther.mData->l);
            break;
        case DataType::TYPE_CHAR:
            throw std::runtime_error("char can't change");
        case DataType::TYPE_DICT:
            this->dictValue_ini(*aOther.mData->d);
            break;
    }
    return *this;
}

Value &Value::operator=(const DictValue &aOther) {
    this->~Value();
    this->dictValue_ini(aOther);
    return *this;
}

bool Value::operator==(std::nullptr_t) const {
    if (this->mValueType == DataType::TYPE_NONE) { return true; }
    return false;
}


Value Value::operator+(const Value &aOther) const {
    switch (this->mValueType) {
        case TYPE_BOOL:
        case TYPE_INT:
            return *this->mData->i + aOther;
        case TYPE_FLOAT:
            return *this->mData->f + aOther;
        case TYPE_CHAR:
            return StringValue(*this->mData->c) + aOther;
        case TYPE_STRING:
            return *this->mData->s + aOther;
        case TYPE_LIST:
            return *this->mData->l + aOther;
        case TYPE_NONE:
        case TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +: {} and {}").format({this->type(), aOther.type()})));
}

Value Value::operator-(const Value &aOther) const {
    switch (this->mValueType) {

        case TYPE_BOOL:
        case TYPE_INT:
            return *this->mData->i - aOther;
        case TYPE_FLOAT:
            return *this->mData->f - aOther;
        case TYPE_CHAR:
        case TYPE_STRING:
        case TYPE_LIST:
        case TYPE_NONE:
        case TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for -: {} and {}").format({this->type(), aOther.type()})));

}

Value Value::operator*(const Value &aOther) const {
    switch (this->mValueType) {
        case TYPE_BOOL:
        case TYPE_INT:
            return *this->mData->i * aOther;
        case TYPE_FLOAT:
            return *this->mData->f * aOther;
        case TYPE_CHAR:
        case TYPE_STRING:
        case TYPE_LIST:
        case TYPE_NONE:
        case TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for *: {} and {}").format({this->type(), aOther.type()})));


}

Value Value::operator/(const Value &aOther) const {
    switch (this->mValueType) {
        case TYPE_BOOL:
        case TYPE_INT:
            return *this->mData->i / aOther;
        case TYPE_FLOAT:
            return *this->mData->f / aOther;
        case TYPE_CHAR:
        case TYPE_STRING:
        case TYPE_LIST:
        case TYPE_NONE:
        case TYPE_DICT:
            break;
    }
    throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for /: {} and {}").format({this->type(), aOther.type()})));

}

Value &Value::operator+=(const Value &aOther) {
    switch (this->mValueType) {
        case TYPE_BOOL:
        case TYPE_INT:
            *this->mData->i += aOther;
            break;
        case TYPE_FLOAT:
            *this->mData->f += aOther;
            break;
        case TYPE_STRING:
            *this->mData->s += aOther;
            break;
        case TYPE_LIST:
            *this->mData->l += aOther;
            break;
        case TYPE_CHAR: {
            throw std::runtime_error("\"str\" object does not support item assignment");
        }
        default: {
            throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for +=: {} and {}").format({this->type(), aOther.type()})));

        }
    }
    return *this;
}

Value &Value::operator-=(const Value &aOther) {
    switch (this->mValueType) {
        case TYPE_BOOL:
        case TYPE_INT:
            *this->mData->i -= aOther;
            break;
        case TYPE_FLOAT:
            *this->mData->f -= aOther;
            break;
        default: {
            throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for -=: {} and {}").format({this->type(), aOther.type()})));

        }
    }
    return *this;


}

Value &Value::operator*=(const Value &aOther) {
    switch (this->mValueType) {
        case TYPE_BOOL:
        case TYPE_INT:
            *this->mData->i *= aOther;
            break;
        case TYPE_FLOAT:
            *this->mData->f *= aOther;
            break;
        default: {
            throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for *=: {} and {}").format({this->type(), aOther.type()})));
        }
    }
    return *this;


}

Value &Value::operator/=(const Value &aOther) {
    switch (this->mValueType) {
        case TYPE_BOOL:
        case TYPE_INT:
            *this->mData->i /= aOther;
            break;
        case TYPE_FLOAT:
            *this->mData->f /= aOther;
            break;
        default: {
            throw std::runtime_error(std::string(StringValue("unsupported operand type(s) for /=: {} and {}").format({this->type(), aOther.type()})));

        }
    }
    return *this;
}

bool Value::operator==(const Value &aOther) const {
    return Value::compair(*this, aOther, Value::CompairType::ET);
}

bool Value::operator!=(const Value &aOther) const {
    return !Value::compair(*this, aOther, Value::CompairType::ET);
}

bool Value::operator>(const Value &aOther) const {
    return Value::compair(*this, aOther, Value::CompairType::GT);
}

bool Value::operator<(const Value &aOther) const {
    return Value::compair(*this, aOther, Value::CompairType::LT);
}

bool Value::operator>=(const Value &aOther) const {
    return !Value::compair(*this, aOther, Value::CompairType::LT);
}

bool Value::operator<=(const Value &aOther) const {
    return !Value::compair(*this, aOther, Value::CompairType::GT);
}
