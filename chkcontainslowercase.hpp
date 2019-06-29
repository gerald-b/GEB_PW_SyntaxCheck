#ifndef CHKCONTAINSLOWERCASE_HPP
#define CHKCONTAINSLOWERCASE_HPP

#include <QRegExp>
#include "icheck.hpp"

class ChkContainsLowerCase : public iCheck
{
public:
    ChkContainsLowerCase();
    ~ChkContainsLowerCase() override;
    bool check(QString s) override;
private:
    QRegExp *re;
};

#endif // CHKCONTAINSLOWERCASE_HPP
