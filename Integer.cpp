#include "Integer.h"

using namespace std;

int (*Integer::multiply)(const Integer, const Integer);

int operator*(const Integer first, const Integer second)
{
    return (Integer::multiply)(first, second);
}

Integer::Integer() : number(new int[1]), size(1)
{
    number[0] = 0;
    SetMultiplyMethod();
}

Integer::Integer(const int integer)
{
    this->Set(integer);
    SetMultiplyMethod();
}

Integer::~Integer()
{
    delete number;
}

int Integer::Get() const
{
    //checkMemory();
    int result = 0;
    int pow = 1;
    for (int i = 0; i < size; i++)
    {
        result += number[i] * pow;
        pow *= 10;
    }
    return result;
}

void Integer::Set(int integer)
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

void Integer::SetMultiplyMethod(int method)
{
    switch (method) {
    case 0:
        Integer::multiply = &Integer::NormalMultiply;
        break;
    case 1:
        Integer::multiply = &Integer::KaratsubaMultiply;
        break;
    default:
        break;
    }
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

int Integer::NormalMultiply(const Integer first, const Integer second)
{
    vector<int> result;
    for (int i = second.size - 1; i >= 0; i--)
    {
        int partialResult = 0;
        int extra = 0;
        for (int j = 0, k = 0; i < first.size; i++)
        {
            partialResult = first.number[j] * second.number[i] + extra;
            extra = partialResult / 10;
            result[]
        }
    }

    //Integer* result;
    return result->Get();
}

void Integer::checkMemory()
{
    int realSize = size;
    for (int i = size - 1; i >= 0; i--)
    {
        if (number[i] == 0)
        {
            realSize--;
        }
    }
    size = realSize;
}

int Integer::KaratsubaMultiply(const Integer, const Integer)
{
    return 0;
}
