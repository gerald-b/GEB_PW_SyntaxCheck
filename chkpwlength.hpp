#ifndef CHKPWLENGTH_HPP
#define CHKPWLENGTH_HPP

#include "icheck.hpp"

class ChkPWLength : public iCheck
{
public:
    ChkPWLength(int minLength, int maxLength);
    bool check(QString s) override;
private:
    int lMax;
    int lMin;
    void setLMax(int maxLength);
    int getLMax();
    void setLMin(int minLength);
    int getLMin();
};

#endif // CHKPWLENGTH_HPP
