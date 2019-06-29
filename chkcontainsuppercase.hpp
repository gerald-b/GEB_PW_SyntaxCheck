#ifndef CHKCONTAINSUPPERCASE_HPP
#define CHKCONTAINSUPPERCASE_HPP

#include <QRegExp>
#include "icheck.hpp"

class ChkContainsUpperCase : public iCheck
{
public:
    ChkContainsUpperCase();
    bool check(QString s) override;
};

#endif // CHKCONTAINSUPPERCASE_HPP

