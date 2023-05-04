#include "Integer.h"

int operator*(const Integer first, const Integer second)
{
    return first.multiply(first, second);
}


Integer::Integer() : number(new int[1]), size(1)
{
    number[0] = 0;
}

Integer::Integer(int integer)
{
    int digits = this->calculateDigits(integer);
    number = new int[digits];
    size = digits;
    for (int i = 0; i < size; i++)
    {
        number[i] = integer % 10;
        integer /= 10;
    }
}

Integer::Integer(const Integer& integer)
{
    size = integer.size;
    number = new int[size];
    for (int i = 0; i < size; i++)
    {
        number[i] = integer.number[i];
    }
}

Integer::Integer(const Integer* integer)
{
    size = integer->size;
    number = new int[size];
    for (int i = 0; i < size; i++)
    {
        number[i] = integer->number[i];
    }
}

Integer::~Integer()
{
    delete number;
}

int Integer::Get() const
{
    int result = 0;
    int pow = 1;
    for (int i = 0; i < size; i++)
    {
        result += number[i] * pow;
        pow *= 10;
    }
    return result;
}

void Integer::Set(const int integer)
{

}

void Integer::SetMultiplyMethod(int (*method)(const Integer, const Integer))
{
    this->multiply = method;
}

int Integer::calculateDigits(int number)
{
    int digits = 0;
    while(number != 0)
    {
        number /= 10;
        digits++;
    }
    return digits;
}
