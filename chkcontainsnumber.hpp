#ifndef CHKCONTAINSNUMBER_HPP
#define CHKCONTAINSNUMBER_HPP

#include <QRegExp>
#include "icheck.hpp"

class ChkContainsNumber : public iCheck
{
public:
    ChkContainsNumber();
    ~ChkContainsNumber() override;
    bool check(QString s) override;
private:
    QRegExp *re;
};

#endif // CHKCONTAINSNUMBER_HPP
