#ifndef CHKCONTAINSUPPERCASE_HPP
#define CHKCONTAINSUPPERCASE_HPP

#include <QRegExp>
#include "icheck.hpp"

class ChkContainsUpperCase : public iCheck
{
public:
    ChkContainsUpperCase();
    ~ChkContainsUpperCase() override;
    bool check(QString s) override;
private:
    QRegExp *re;
};

#endif // CHKCONTAINSUPPERCASE_HPP
