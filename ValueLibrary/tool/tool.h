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

    typedef std::vector<Value *> _stringType;

    // NOLINTNEXTLINE
    Tool() = delete;

    // NOLINTNEXTLINE
    Tool(Tool &tool) = delete;

public:
    // NOLINTNEXTLINE
    static int _StringToInt(const _stringType &aData);

    // NOLINTNEXTLINE
    static double _StringToDouble(const _stringType &aData);

    // NOLINTNEXTLINE
    static bool _StringIsDigit(const _stringType &aData, bool aIsInt = false);

    // NOLINTNEXTLINE
    static _stringType _StringCenterCN(const _stringType &aData, const int &aFillInNumber, const _stringType &aFillChar,
                                       int direction = 0);

    // NOLINTNEXTLINE
    static int _StringLength(const _stringType &aData);

    // NOLINTNEXTLINE
    static _stringType
    // NOLINTNEXTLINE
    _StringCenter(const _stringType &aData, const int &aFillInNumber, const char &aFillChar, int direction = 0);

    // NOLINTNEXTLINE
    static bool _StringStartWithString(const _stringType &aData, const _stringType &aWithString, bool reverse = false);

    // NOLINTNEXTLINE
    static int
    // NOLINTNEXTLINE
    __StringFindStripEndIndex(const _stringType &aData, const _stringType &aStripString, bool reverse = false);

    // NOLINTNEXTLINE
    static _stringType
    // NOLINTNEXTLINE
    _StringStrip(const _stringType &aData, const _stringType &aStripString = {new Value(' '), new Value('\n')},
                 int StriptType = 0);

    // NOLINTNEXTLINE
    static _stringType _StringIndexOf(const _stringType &aData, const unsigned int &pos);

    // NOLINTNEXTLINE
    static _stringType _StringIndexOf(const _stringType &aData, const unsigned int &pos, const int &end);

    // NOLINTNEXTLINE
    static int _StringFindFirst(const _stringType &aData, const _stringType &aFindString, const unsigned int &aPos,
                                const bool &aReverse = false);

    // NOLINTNEXTLINE
    static int _StringFindFirst(const _stringType &aData, const _stringType &aFindString, const unsigned int &aPos,
                                const int &aEnd, const bool &aReverse = false);

    // NOLINTNEXTLINE
    static std::vector<int>
    // NOLINTNEXTLINE
    _StringFind(const _stringType &aData, const _stringType &aFindString, const int &aMaxNumber = 0,
                const bool &aReverse = false);

    // NOLINTNEXTLINE
    static _stringType
    // NOLINTNEXTLINE
    _StringReplace(const _stringType &aChangeData, const _stringType &aData, const _stringType &aReplaceData,
                   const int &aMaxNumber = 0, const bool &aReverse = false);

};


#endif //UNTITLED2_TOOL_H
