#ifndef CHKPWLENGTH_HPP
#define CHKPWLENGTH_HPP

#include "icheck.hpp"

class chkPWLength : public iCheck
{
public:
    chkPWLength(int minLength, int maxLength);
private:
    int lMax;
    int lMin;
    void setLMax(int maxLength);
    int getLMax();
    void setLMin(int minLength);
    int getLMin();
};

#endif // CHKPWLENGTH_HPP
