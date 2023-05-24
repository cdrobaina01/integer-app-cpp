#include "Integer.h"
#include <assert.h>

Integer (*Integer::multiply)(const Integer&, const Integer&) = &Integer::NormalMultiply;

/* Friend Operators */

Integer operator*(const Integer& first, const Integer& second)
{
    return first.multiply(first, second);
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
            sum += left.array[i];
        }
        if (i < right.size) {
            sum += right.array[i];
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

    Integer sum;
    sum.array = resultPtr;
    sum.size = maxSize;

    return sum;
}

Integer operator-(const Integer &left, const Integer &right)
{
    return right.size >= left.size && abs(right.array[right.size - 1]) >= abs(left.array[left.size - 1])
            ? Integer::restar(right, left).Get() * -1 : Integer::restar(left, right).Get();
}

Integer Integer::restar(const Integer &left, const Integer &right)
{
    int maxSize;
    left.size >= right.size ? maxSize = left.size : maxSize = right.size;
    int* resultPtr = new int[maxSize];
    ;
    int borrow = 0;

    for (int i = 0; i < maxSize; i++) {
        int rest = borrow;
        if (i < left.size) {
            rest += left.array[i];
        }
        if (i < right.size) {
            rest -= right.array[i];
        }
        if (rest < 0 && (left.array[i] >= 0 && right.array[i] >= 0)) {
            borrow = -1;
            rest += 10;
        }
        else {
            borrow = 0;
        }
        resultPtr[i] = rest;
    }

    //Eliminamos los ceros a la izquierda del resultado en caso de ser necesario
    int pos = maxSize - 1;
    while (pos > 0 && resultPtr[pos] == 0) {
        pos--;
    }

    Integer diff;
    diff.size = maxSize;
    diff.array = resultPtr;

    return diff;
}

/* Builders, Getters & Setters */

Integer::Integer() : array(new int[1]), size(1)
{
    array[0] = 0;
}

Integer::Integer(int number)
{
    Set(number);
}

Integer::~Integer()
{
    delete []array;
}

int Integer::Get() const
{
    int result = 0;
    int pow = 1;
    for (int i = 0; i < size; i++)
    {
        result += array[i] * pow;
        pow *= 10;
    }
    return result;
}

void Integer::Set(const int number)
{
    int digits = this->calculateDigits(number);
    int copy = number;
    array = new int[digits];
    size = digits;
    for (int i = 0; i < size; i++)
    {
        array[i] = copy % 10;
        copy /= 10;
    }
}


/* Multiply Methods */

void Integer::SetMultiplyMethod(bool karatsuba)
{
    Integer::multiply = karatsuba ? &Integer::KaratsubaMultiply : &Integer::NormalMultiply;
}

Integer Integer::NormalMultiply(const Integer& first, const Integer& second)
{
    int size = first.size + second.size;
    int* result = new int[size]();
    for (int i = 0; i < first.size; i++)
    {
        for (int j = 0; j < second.size; j++)
        {
            result[i + j] += first.array[i] * second.array[j];
        }
    }
    for (int i = 0; i < size - 1; i++)
    {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }
    while (size > 1 && result[size - 1] == 0)
    {
        size--;
    }
    Integer final;
    final.array = result;
    final.size = size;
    return final;
}

Integer Integer::KaratsubaMultiply(const Integer& first, const Integer& second)
{
    if (first.size != second.size)
    {
        return Integer::NormalMultiply(first, second);
    }
    if (first.size == 1)
    {
        return Integer(first.array[0] * second.array[0]);
    }
    int n = first.size;
    int m = n / 2;

    Integer x1(first.Get() / pow(10, m));
    Integer y1(second.Get() / pow(10, m));
    Integer x2(first.Get() % (int) pow(10, m));
    Integer y2(second.Get() % (int) pow(10, m));

    Integer z0 = Integer::KaratsubaMultiply(x2, y2);
    Integer z2 = Integer::KaratsubaMultiply(x1, y1);
    Integer sum1 = x1 + x2;
    Integer sum2 = y1 + y2;
    Integer z1a = Integer::KaratsubaMultiply(sum1, sum2);
    Integer z1b = z1a - z2;
    Integer z1 = z1b - z0;

    Integer r2 = z2.Get() * pow(10, m * 2);
    Integer r1 = z1.Get() * pow(10, m);
    Integer r0 = r2 + r1;

    Integer result = r0 + z0;

    return Integer(result.Get());
}


/* Auxiliar Methods */

Integer Integer::multiplyBy10n(int n) const
{
    Integer result(*this);
    result.array = new int[size + n];
    for (int i = 0; i < size; i++) {
        result.array[i + n] = array[i];
    }
    for (int i = 0; i < n; i++) {
        result.array[i] = 0;
    }
    result.size += n;
    return result;
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
