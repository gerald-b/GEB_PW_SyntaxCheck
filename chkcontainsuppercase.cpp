#include "chkcontainsuppercase.hpp"

ChkContainsUpperCase::ChkContainsUpperCase()
{

}

bool ChkContainsUpperCase::check(QString s)
{
    QRegExp re("[A-Z]{1}");
    for(int i=0; i <= s.length(); ++i)
    {
        if (re.exactMatch(QString(s[i])))
        {
            return true;
        }
    }
    return false;
}
