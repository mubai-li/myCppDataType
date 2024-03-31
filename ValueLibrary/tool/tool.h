//
// Created by 32509 on 2023/12/11.
//

#ifndef UNTITLED2_TOOL_H
#define UNTITLED2_TOOL_H

#include "iostream"
#include <map>
#include <typeinfo>
#include <utility>
#include <vector>
class Tool;
#include "../Value.h"

class Tool {
private:
    friend Value;
    friend IntValue;
    friend FloatValue;
    friend StringValue;
    friend ListValue;
    friend std::ostream &operator<<(std::ostream &c, const StringValue &aStringValue);
    typedef std::vector<Value*> _stringType;
    Tool() = delete;

    Tool(Tool &tool) = delete;

public:

    static int _StringToInt(const _stringType & aData);
    static double _StringToDouble(const _stringType & aData);
    static bool _StringIsDigit(const _stringType & aData,bool aIsInt= false);
    static _stringType _StringCenterCN(const _stringType &aData,const int &aFillInNumber,const _stringType &aFillChar,int direction=0);
    static int _StringLength(const _stringType &aData);
    static _stringType _StringCenter(const _stringType &aData,const int &aFillInNumber,const char &aFillChar,int direction=0);
    static bool _StringStartWithString(const _stringType &aData, const _stringType &aWithString, bool reverse = false);

    static int __StringFindStripEndIndex(const _stringType &aData, const _stringType &aStripString, bool reverse = false);


    static _stringType _StringStrip(const _stringType &aData, const _stringType &aStripString = {new Value(' '),new Value('\n')}, int StriptType = 0);

    static _stringType _StringIndexOf(const _stringType &aData, const unsigned int &pos);
    static _stringType _StringIndexOf(const _stringType &aData, const unsigned int &pos, const int &end);

    static int _StringFindFirst(const _stringType &aData, const _stringType &aFindString, const unsigned int &aPos, const bool &aReverse = false);
    static int _StringFindFirst(const _stringType &aData, const _stringType &aFindString, const unsigned int & aPos , const int &aEnd, const bool &aReverse = false);

    static std::vector<int> _StringFind(const _stringType &aData, const _stringType &aFindString, const int &aMaxNumber = 0, const bool &aReverse = false);

    static _stringType
    _StringReplace(const _stringType &aChangeData, const _stringType &aData, const _stringType &aReplaceData, const int &aMaxNumber = 0, const bool &aReverse = false);

};



#endif //UNTITLED2_TOOL_H
