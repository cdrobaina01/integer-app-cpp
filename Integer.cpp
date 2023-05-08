#include "Integer.h"
#include <assert.h>

int operator*(const Integer first, const Integer second)
{
    return first.multiply(first, second);
}


Integer::Integer() : number(new int[1]), size(1)
{
    number[0] = 0;
}

/*Integer::Integer(int integer)
{
    int digits = this->calculateDigits(integer);
    number = new int[digits];
    size = digits;
    for (int i = 0; i < size; i++)
    {
        number[i] = integer % 10;
        integer /= 10;
    }
}*/

Integer::Integer(const int arraySize)
{
    size = arraySize;
    number = new int[size];
    assert(number != 0);

    for (int i = 0; i < size; i++)
        number[i] = 0;
}

/*Integer::Integer(const int array[])
{
    number = array[];
}*/

Integer::Integer(int array[],int sizeArray)
{
    size = sizeArray;
    number = new int[size];
    for (int i = 0; i < size; i++) {
        number[i] = array[i];
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
    delete []number;
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

Integer operator+(const Integer &left, const Integer &right)
{
    int maxSize;
    left.size >= right.size ? maxSize = left.size : maxSize = right.size;
    int *resultPtr = new int[maxSize];
    int carry = 0;

    for (int i = 0; i < maxSize; i++) {
        int sum = carry;
        if (i < left.size) {
            sum += left.number[i];
        }
        if (i < right.size) {
            sum += right.number[i];
        }
        resultPtr[i] = sum % 10;
        carry = sum / 10;
    }

    //Redimencionando el arreglo para agregar el último dígito si es necesario
    if (carry != 0) {
        int *newResultPtr = new int[maxSize + 1];
        for (int i = 0; i < maxSize; i++) {
            newResultPtr[i] = resultPtr[i];
        }
        newResultPtr[maxSize] = carry;
        delete[] resultPtr;
        resultPtr = newResultPtr;
        maxSize++;
    }

    Integer sum(maxSize);
    for (int i = 0; i < maxSize; i++) {
        sum.number[i] = resultPtr[i];
    }

    delete[] resultPtr;
    return sum;
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
