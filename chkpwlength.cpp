#include "chkpwlength.hpp"

ChkPWLength::ChkPWLength(int minLength, int maxLength)
{
    this->setLMin(minLength);
    this->setLMax(maxLength);
}

bool ChkPWLength::check(QString s)
{
    if (s.length() >= this->getLMin() &&
        s.length() <= this->getLMax())
    {
        return true;
    }
    return false;
}

void ChkPWLength::setLMax(int maxLength)
{
    this->lMax = maxLength;
}

int ChkPWLength::getLMax()
{
    return this->lMax;
}

void ChkPWLength::setLMin(int minLength)
{
    this->lMin = minLength;
}

int ChkPWLength::getLMin()
{
    return  this->lMin;
}
