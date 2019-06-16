#include "chkpwlength.hpp"

chkPWLength::chkPWLength(int minLength, int maxLength)
{
    this->setLMin(minLength);
    this->setLMax(maxLength);
}

void chkPWLength::setLMax(int maxLength)
{
    this->lMax = maxLength;
}

int chkPWLength::getLMax()
{
    return this->lMax;
}

void chkPWLength::setLMin(int minLength)
{
    this->lMin = minLength;
}

int chkPWLength::getLMin()
{
    return  this->lMin;
}
