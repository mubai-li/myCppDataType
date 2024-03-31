//
// Created by 32509 on 2023/12/11.
//

#include "tool.h"

int Tool::_StringToInt(const Tool::_stringType &aData) {

    bool beNegative = false;
    if(char(*aData.at(0)) == '-'){
        beNegative = true;
    }
    // NOLINTNEXTLINE
    _stringType::const_iterator dataEnd = aData.begin() - 1;
    if(beNegative){
        dataEnd++;
    }
    int result = 0;
    int tenPowerNumber = 0;
    // NOLINTNEXTLINE
    for (_stringType::const_iterator dataIndex = aData.end() - 1; dataIndex != dataEnd; dataIndex--) {
        switch (char(**dataIndex)) {
            case '0':
            case '1':
                result += int(std::pow(10, tenPowerNumber) )* 1;
                break;
            case '2':
                result += int(std::pow(10, tenPowerNumber) ) * 2;
                break;
            case '3':
                result += int(std::pow(10, tenPowerNumber) ) * 3;
                break;
            case '4':
                result += int(std::pow(10, tenPowerNumber) ) * 4;
                break;

            case '5':
                result += int(std::pow(10, tenPowerNumber) ) * 5;
                break;

            case '6':
                result += int(std::pow(10, tenPowerNumber) ) * 6;

                break;
            case '7':
                result += int(std::pow(10, tenPowerNumber) ) * 7;

                break;
            case '8':
                result += int(std::pow(10, tenPowerNumber) ) * 8;

                break;
            case '9':
                result += int(std::pow(10, tenPowerNumber) ) * 9;
                break;
            default:
                throw std::runtime_error("invalid literal for int() with base 10: " );
        }
        tenPowerNumber++;
    }
    if(beNegative){
        result = -result;
    }
    return result;

}
double Tool::_StringToDouble(const _stringType &aData) {
    bool beNegative = false;

    if(char(*aData.at(0))=='-'){
        beNegative = true;
    }
    // NOLINTNEXTLINE
    _stringType::const_iterator dataEnd = aData.begin() - 1;
    if(beNegative){
        dataEnd++;
    }
    int result = 0;
    int tenPowerNumber = 0;
    bool havePoint = false;
    int divisionSign = 1;
    // NOLINTNEXTLINE
    for (_stringType::const_iterator dataIndex = aData.end() - 1; dataIndex != dataEnd; dataIndex--) {
        switch (char(**dataIndex)) {
            case '.': {

                if (havePoint) {
                    throw std::runtime_error("invalid literal for int() with base 10: ");
                }
                havePoint = true;
                divisionSign =int(std::pow(10, tenPowerNumber));
                break;
            }
            case '0':
            case '1':
                result += int(std::pow(10, tenPowerNumber) )* 1;
                break;
            case '2':
                result += int(std::pow(10, tenPowerNumber) ) * 2;
                break;
            case '3':
                result += int(std::pow(10, tenPowerNumber) ) * 3;
                break;
            case '4':
                result += int(std::pow(10, tenPowerNumber) ) * 4;
                break;

            case '5':
                result += int(std::pow(10, tenPowerNumber) ) * 5;
                break;

            case '6':
                result += int(std::pow(10, tenPowerNumber) ) * 6;

                break;
            case '7':
                result += int(std::pow(10, tenPowerNumber) ) * 7;

                break;
            case '8':
                result += int(std::pow(10, tenPowerNumber) ) * 8;

                break;
            case '9':
                result += int(std::pow(10, tenPowerNumber) ) * 9;
                break;
            default:
                throw std::runtime_error("invalid literal for float() with base 10: ");
        }
        tenPowerNumber++;
    }
    double doubleResult = double(result)/ divisionSign;
    if(beNegative){
        doubleResult = -doubleResult;
    }
    return doubleResult;
}
bool Tool::_StringIsDigit(const _stringType &aData, bool aIsInt) {
    bool havePoint;
    if (aIsInt) {
        havePoint = true;
    } else {
        havePoint = false;
    }
    // NOLINTNEXTLINE
    for (const Value * charData: aData) {
        switch (char(**charData)) {
            case '.': {

                if (havePoint) {
                    return false;
                }
                havePoint = true;
                continue;
            }
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                continue;
            default:
                return false;
        }
    }
    return true;
}


Tool::_stringType Tool::_StringCenterCN(const _stringType &aData, const int &aFillInNumber, const _stringType &aFillChar, int direction) {
    if (Tool::_StringLength(aFillChar) != 1) {
        throw std::runtime_error("Fill in data must is a char");
    }
    int dataLength = Tool::_StringLength(aData);
    if (aFillInNumber <= dataLength) {
        return aData;
    }
    int leftCharNumber;
    int rigthCharNumber;
    switch (direction) {

        case -1: {
            rigthCharNumber = 0;
            leftCharNumber = aFillInNumber - dataLength;
        }
            break;
        case 0: {
            leftCharNumber = (aFillInNumber - dataLength) / 2;
            if ((aFillInNumber - dataLength) % 2 == 0) {
                rigthCharNumber = leftCharNumber;
            } else {
                rigthCharNumber = leftCharNumber + 1;
            }
        }
            break;
        case 1: {
            leftCharNumber = 0;
            rigthCharNumber = aFillInNumber - dataLength;
        }
            break;
        default:
            throw std::runtime_error("not this direction");

    }
    _stringType newData;
    newData.resize(aData.size() + aFillChar.size() * (leftCharNumber + rigthCharNumber));
    // NOLINTNEXTLINE
    _stringType::iterator newDataIndex = newData.begin();

    if (leftCharNumber > 0) {
        for (int leftChangeIndex = 0; leftChangeIndex != leftCharNumber; leftChangeIndex++) {
            for (Value * fillCharIndex: aFillChar) {
                *newDataIndex = fillCharIndex;
                newDataIndex++;

            }
        }
    }
    // NOLINTNEXTLINE
    for (const Value * dataChar: aData) {
        **newDataIndex = *dataChar;
        newDataIndex++;
    }
    if (rigthCharNumber > 0) {
        for (int rightChangeIndex = 0; rightChangeIndex != rigthCharNumber; rightChangeIndex++) {
            for (Value * fillCharIndex: aFillChar) {
                **newDataIndex = *fillCharIndex;
                newDataIndex++;

            }
        }
    }
    return newData;
}

int Tool::_StringLength(const _stringType &aData) {
    int dataLength = 0;
    int charNumber = 255;
    int dataCharNumber;
    // NOLINTNEXTLINE
    for (_stringType::const_iterator dataIteratorIndex = aData.begin(); dataIteratorIndex != aData.end(); dataIteratorIndex++) {
        dataCharNumber = int(char(**dataIteratorIndex) & charNumber);
        if (dataCharNumber >= 228 and dataCharNumber <= 233) {
            dataIteratorIndex++;
            dataCharNumber = dataCharNumber * 1000000 + int(char(**dataIteratorIndex) & charNumber) * 1000 + int(char(**++dataIteratorIndex) & charNumber);
            if (dataCharNumber < 228184128 or dataCharNumber > 233188128) {
                dataLength += 2;
            }
        }
        dataLength++;
    }
    return dataLength;
}

Tool::_stringType Tool::_StringCenter(const _stringType &aData, const int &aFillInNumber, const char &aFillChar, int direction) {  // 不支持中文

    int dataLength = int(aData.size());
//    if (fillCharLength == 3) {
//        int resultNumber = int(aFillChar[0] & 255) * 1000000 + int(aFillChar[1] & 255) * 1000 + int(aFillChar[2] & 255);
//        if (resultNumber < 228184128 or resultNumber > 233188128) {
//            throw std::runtime_error("Fill in data must is a char");
//        }
//    }


    if (aFillInNumber <= dataLength) {
        return aData;
    }

    _stringType newData;
    newData.resize(aFillInNumber);
    // NOLINTNEXTLINE
    _stringType::iterator newDataIndex = newData.begin();
    int leftCharNumber;
    int rigthCharNumber;
    switch (direction) {

        case -1: {
            rigthCharNumber = 0;
            leftCharNumber = aFillInNumber - dataLength;
        }
            break;
        case 0: {
            leftCharNumber = (aFillInNumber - dataLength) / 2;
            if ((aFillInNumber - dataLength) % 2 == 0) {
                rigthCharNumber = leftCharNumber;
            } else {
                rigthCharNumber = leftCharNumber + 1;
            }
        }
            break;
        case 1: {
            leftCharNumber = 0;
            rigthCharNumber = aFillInNumber - dataLength;
        }
            break;
        default:
            throw std::runtime_error("not this direction");

    }
    if (leftCharNumber > 0) {
        for (int leftChangeIndex = 0; leftChangeIndex != leftCharNumber; leftChangeIndex++) {
            **newDataIndex = aFillChar;
            newDataIndex++;
        }
    }
    // NOLINTNEXTLINE
    for (const Value * dataChar: aData) {
        **newDataIndex = *dataChar;
        newDataIndex++;
    }
    if (rigthCharNumber > 0) {
        for (int rightChangeIndex = 0; rightChangeIndex != rigthCharNumber; rightChangeIndex++) {
            **newDataIndex = aFillChar;
            newDataIndex++;
        }
    }
    return newData;
}

bool Tool::_StringStartWithString(const _stringType &aData, const _stringType &aCompareString, bool reverse) {
    _stringType::const_iterator aDataBegin;
    _stringType::const_iterator aDataEnd;
    _stringType::const_iterator aCompareStringIndex;
    _stringType::const_iterator aCompareStringEnd;

    if (reverse) {
        aDataBegin = aData.end() - 1;
        aDataEnd = aData.begin() - 1;
        aCompareStringIndex = aCompareString.end() - 1;
        aCompareStringEnd = aCompareString.begin() - 1;
    } else {
        aDataBegin = aCompareString.begin();
        aDataEnd = aCompareString.end();
        aCompareStringIndex = aCompareString.begin();
        aCompareStringEnd = aCompareString.end();
    }
    // NOLINTNEXTLINE
    for (_stringType::const_iterator aDataIndex = aDataBegin; aDataIndex != aDataEnd;) {
        if (*aDataIndex == *aCompareStringIndex) {
//        if ((char)*aDataIndex == (char)*aCompareStringIndex) {
            if (reverse) {
                aCompareStringIndex--;
            } else {
                aCompareStringIndex++;
            }
        } else {
            return false;
        }
        if (aCompareStringIndex == aCompareStringEnd) {
            return true;
        }
        if (reverse) {
            aDataIndex--;
        } else {
            aDataIndex++;
        }
    }
    return false;
}

int Tool::__StringFindStripEndIndex(const _stringType &aData, const _stringType &aStripString, bool reverse) {
    _stringType::const_iterator aDataBegin;
    _stringType::const_iterator aDataEnd;
    if (reverse) {
        aDataBegin = aData.end() - 1;
        aDataEnd = aData.begin() - 1;
    } else {
        aDataBegin = aData.begin();
        aDataEnd = aData.end();
    }
    // NOLINTNEXTLINE
    _stringType::const_iterator aStripStringBegin = aStripString.begin();
    // NOLINTNEXTLINE
    _stringType::const_iterator aStripStringEnd = aStripString.end();
    int stripIndex;
    if (reverse) {
        stripIndex = int(aData.size());
    } else {
        stripIndex = 0;
    }
    bool FindEnd;
    // NOLINTNEXTLINE
    for (_stringType::const_iterator aDataIteratorIndex = aDataBegin; aDataIteratorIndex != aDataEnd;) {
        char charData = **aDataIteratorIndex;
        FindEnd = false;
        // NOLINTNEXTLINE
        for (_stringType::const_iterator aStriptStringIteratorIndex = aStripStringBegin;
             aStriptStringIteratorIndex != aStripStringEnd; aStriptStringIteratorIndex++) {
            if (charData == char(**aStriptStringIteratorIndex)) {
                if (reverse) {
                    stripIndex--;
                } else {
                    stripIndex++;
                }
                FindEnd = true;
                break;
            }

        }
        if (!FindEnd) {
            break;
        }
        if (reverse) {
            aDataIteratorIndex--;
        } else {
            aDataIteratorIndex++;
        }
    }
    return stripIndex;
}


Tool::_stringType Tool::_StringStrip(const _stringType &aData, const _stringType &aStripString, int StriptType) {
    int aDataBeginIndex = 0;
    int aDataEndIndex = int(aData.size());
    if (StriptType != 1) {
        aDataBeginIndex = __StringFindStripEndIndex(aData, aStripString);
    }
    if (StriptType != -1) {
        aDataEndIndex = __StringFindStripEndIndex(aData, aStripString, true);

    }
    return Tool::_StringIndexOf(aData, aDataBeginIndex, aDataEndIndex);
}
Tool::_stringType Tool::_StringIndexOf(const _stringType &aData, const unsigned int &aPos) {

    return Tool::_StringIndexOf(aData,aPos,int(aData.size()));
}
Tool::_stringType Tool::_StringIndexOf(const _stringType &aData, const unsigned int &aPos, const int &aEnd) {
    int aDataLength = int(aData.size());
    int aDataEnd = aDataLength;
    if (aEnd < 0) {
        aDataEnd = aDataEnd + aEnd;
    } else {
        aDataEnd = aEnd;
    }
    if (aPos > aDataLength) {
        throw std::runtime_error("index range out");
    }
    if (aDataEnd > aDataLength) {
        aDataEnd = aDataLength;
    }
    if (aDataEnd <= aPos) {
        return {};
    }
    _stringType resultString;
    resultString.resize(aDataEnd - aPos);
    // NOLINTNEXTLINE
    _stringType::iterator resultStringBegin = resultString.begin();
    // NOLINTNEXTLINE
    for (_stringType::const_iterator aDataBegin = aData.begin() + aPos;
         aDataBegin != aData.begin() + aDataEnd; aDataBegin++) {
        *resultStringBegin = *aDataBegin;
        resultStringBegin++;
    }
    return resultString;
}
int Tool::_StringFindFirst(const _stringType &aData, const _stringType &aFindString,  const unsigned int &aPos,const bool &aReverse){
    int end = int(aData.size())-1;

    return Tool::_StringFindFirst(aData,aFindString,aPos,end,aReverse);
}
int Tool::_StringFindFirst(const _stringType &aData, const _stringType &aFindString, const unsigned int &aPos, const int &aEnd, const bool &aReverse) {
    // NOLINTNEXTLINE
    _stringType::const_iterator aDataBegin = aData.begin();
    _stringType::const_iterator aDataIndex;
    _stringType::const_iterator aDataEnd;
    _stringType::const_iterator aFindStringBegin;
    _stringType::const_iterator aFindStringEnd;
    _stringType::const_iterator aFindStringIndex;
    int aFindStringLength = int(aFindString.size());
    int aDataLength = int(aData.size());
    int aDataEndNumber = 0;


    if(aEnd <0){
        aDataEndNumber = aDataLength + aEnd;
    }else if(aEnd > aDataLength){
        throw std::runtime_error("please selected a sucess index");
    }else{
        aDataEndNumber = aEnd;
    }
    if(aPos > aDataLength){
        throw std::runtime_error("please selected a sucess index");
    }
    if(aDataEndNumber - aPos <=0){
        throw std::runtime_error("please selected a sucess index");
    }
    if (aReverse) {
        aDataIndex =  aData.begin() + aDataEndNumber-1;
        aDataEnd = aData.begin() - 1 + aPos;

        aFindStringBegin = aFindString.end() - 1;
        aFindStringEnd = aFindString.begin();
        aFindStringIndex = aFindStringBegin;
    } else {
        aDataIndex = aData.begin() + aPos;
        aDataEnd = aData.begin() + aDataEndNumber+1;

        aFindStringBegin = aFindString.begin();
        aFindStringEnd = aFindString.end() - 1;
        aFindStringIndex = aFindStringBegin;
    }
    for (; aDataIndex != aDataEnd;) {
        if (**aDataIndex == **aFindStringIndex) {
            if (aFindStringIndex == aFindStringEnd) {
                if (aReverse) {
                    return int(aDataIndex - aDataBegin);
                } else {
                    return int(aDataIndex - aDataBegin) - aFindStringLength + 1;
                }
            }
            if (aReverse) {
                aFindStringIndex--;
            } else {
                aFindStringIndex++;
            }
        } else {
            aFindStringIndex = aFindStringBegin;

        }
        if (aReverse) {
            aDataIndex--;
        } else {
            aDataIndex++;
        }
    }
    return -1;
}

std::vector<int> Tool::_StringFind(const _stringType &aData, const _stringType &aFindString, const int &aMaxNumber, const bool &aReverse) {
    std::vector<int> findIndexList;
    int findStringLength = int(aData.size());
    int number = 0;
    int findIndex=0;
    if(aReverse){
        findIndex = findStringLength;
    }
    do {
        if (aReverse) {
            findIndex = int(Tool::_StringFindFirst(aData,aFindString,0,findIndex, true));
        } else {
            findIndex = int(Tool::_StringFindFirst(aData,aFindString,findIndex));

        }

        if (findIndex == -1) {
            break;
        }
        findIndexList.push_back(findIndex);
        if(!aReverse){
            findIndex+=findStringLength;
        }
        number++;
    } while (number != aMaxNumber);
    findIndexList.resize(findIndexList.size());

    return findIndexList;
}


Tool::_stringType Tool::_StringReplace(const _stringType &aChangeData, const _stringType &aData, const _stringType &aReplaceData, const int &aMaxNumber, const bool &aReverse) {
    _stringType resultString;
    int dataLength = int(aData.size());
    int replaceDataLenth = int(aReplaceData.size());
    std::vector<int> findDataIndexList = Tool::_StringFind(aChangeData, aData, aMaxNumber, aReverse);


    int findCount = int(findDataIndexList.size());
    int resultStringLength = int(aChangeData.size()) + (replaceDataLenth - dataLength) * findCount;
    if (resultStringLength <= 0) {
        return {};
    }

    resultString.resize(resultStringLength);
    int thisStringIndex = 0;
    // NOLINTNEXTLINE
    _stringType::iterator resultStringIterator = resultString.begin();
    // NOLINTNEXTLINE
    std::vector<int>::const_iterator findDataIndexListIterator ;
    std::vector<int>::const_iterator findDataIndexListIteratorEnd ;
    if (aReverse) {
        findDataIndexListIterator = findDataIndexList.end()-1;
        findDataIndexListIteratorEnd = findDataIndexList.begin()-1;
    }else{
        findDataIndexListIterator = findDataIndexList.begin();
        findDataIndexListIteratorEnd = findDataIndexList.end();
    }
    // NOLINTNEXTLINE
    for (_stringType::const_iterator thisStringIterator = aChangeData.begin();
         thisStringIterator != aChangeData.end(); thisStringIterator++) {
        if (findDataIndexListIterator != findDataIndexListIteratorEnd and
            thisStringIndex == (*findDataIndexListIterator)) {
            if (aReverse){
                findDataIndexListIterator--;
            }else{
                findDataIndexListIterator++;

            }
            // NOLINTNEXTLINE
            for (_stringType::const_iterator replaceDataIterator = aReplaceData.begin();
                 replaceDataIterator != aReplaceData.end(); replaceDataIterator++) {
                *resultStringIterator = *replaceDataIterator;
                resultStringIterator++;
            }
            thisStringIterator += (dataLength - 1);
            thisStringIndex += dataLength;

        } else {
            *resultStringIterator = *thisStringIterator;
            resultStringIterator++;
            thisStringIndex++;
        }

    }
    return resultString;

}

