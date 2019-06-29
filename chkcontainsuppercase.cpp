#include "chkcontainsuppercase.hpp"

ChkContainsUpperCase::ChkContainsUpperCase()
{
    this->re = new QRegExp("[A-Z]{1}");
}

ChkContainsUpperCase::~ChkContainsUpperCase()
{
    delete(this->re);
}

bool ChkContainsUpperCase::check(QString s)
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
