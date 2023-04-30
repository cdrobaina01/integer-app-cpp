#include "Integer.h"

Integer::Integer()
{

}

void Integer::SetMultiplyMethod(int (*method)(const Integer, const Integer))
{
    this->multiply = method;
}

int operator*(const Integer first, const Integer second)
{
    return first.multiply(first, second);
}
