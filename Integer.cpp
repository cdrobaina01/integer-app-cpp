#include "Integer.h"
#include <assert.h>

int (*Integer::multiply)(const Integer, const Integer) = &Integer::NormalMultiply;

/* Friend Operators */

int operator*(const Integer& first, const Integer& second)
{
    return first.multiply(first, second);
}

int operator+(const Integer &left, const Integer &right)
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

    return sum.Get();
}

int operator-(const Integer &left, const Integer &right)
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

int Integer::NormalMultiply(const Integer first, const Integer second)
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
    return final.Get();
}

int Integer::KaratsubaMultiply(const Integer first, const Integer second)
{
    if (first.size == 1 && second.size == 1)
    {
        return first.array[0] * second.array[0];
    }

    int half = (first.size > second.size ? first.size : second.size) / 2;

    Integer high1, low1, high2, low2;

    if (first.size >= half)
    {
        low1.size = half;
        high1.size = first.size - half;

        low1.array = first.array;
        high1.array = first.array + half;
    }
    else
    {
        low1 = first;
        high1.size = 0;
    }

    if (second.size >= half)
    {
        low2.size = half;
        high2.size = second.size - half;

        low2.array = second.array;
        high2.array = second.array + half;
    }
    else
    {
        low2 = second;
        high2.size = 0;
    }

    int z0 = KaratsubaMultiply(low1, low2);
    int z1 = KaratsubaMultiply(low1 + high1, low2 + high2);
    int z2 = KaratsubaMultiply(high1, high2);

    return z2 * pow(10, 2 * half) + (z1 - z2 - z0) * pow(10, half) + z0;
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
