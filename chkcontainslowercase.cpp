#include "chkcontainslowercase.hpp"

ChkContainsLowerCase::ChkContainsLowerCase()
{
    this->re = new QRegExp("[a-z]{1}");
}

ChkContainsLowerCase::~ChkContainsLowerCase()
{
    delete this->re;
}

bool ChkContainsLowerCase::check(QString s)
{
    for(int i=0; i <= s.length(); ++i)
    {
        if (this->re->exactMatch(QString(s[i])))
        {
            return true;
        }
    }
    return false;
}
