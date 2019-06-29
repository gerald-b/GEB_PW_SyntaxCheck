#include "chkcontainsnumber.hpp"

ChkContainsNumber::ChkContainsNumber()
{
    this->re = new QRegExp("[0-9]{1}");
}

ChkContainsNumber::~ChkContainsNumber()
{
    delete re;
}

bool ChkContainsNumber::check(QString s)
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
