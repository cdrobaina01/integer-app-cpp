#include "Integer.h"
#include <assert.h>

int operator*(const Integer first, const Integer second)
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

    Integer sum;
    sum.number = resultPtr;
    sum.size = maxSize;

    return sum;
}

Integer operator-(const Integer &left, const Integer &right)
{
    int maxSize;
    left.size >= right.size ? maxSize = left.size : maxSize = right.size;
    int* resultPtr = new int[maxSize];
    ;
    int borrow = 0;

    for (int i = 0; i < maxSize; i++) {
        int rest = borrow;
        if (i < left.size) {
            rest += left.number[i];
        }
        if (i < right.size) {
            rest -= right.number[i];
        }
        if (rest < 0) {
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
    diff.number = resultPtr;

    return diff;
}


Integer::Integer() : number(new int[1]), size(1)
{
    number[0] = 0;
    SetMultiplyMethod();
}

Integer::Integer(int integer)
{
    Set(integer);
    SetMultiplyMethod();
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

int Integer::NormalMultiply(const Integer first, const Integer second)
{
    int size = first.size + second.size;
    int* result = new int[size]();
    for (int i = 0; i < first.size; i++)
    {
        for (int j = 0; j < second.size; j++)
        {
            result[i + j] += first.number[i] * second.number[j];
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
    final.number = result;
    final.size = size;
    return final.Get();
}

int Integer::KaratsubaMultiply(const Integer first, const Integer second)
{
    int n = first.size;
    if (n == 1) {
        return first.number[0] * second.number[0];
    }
    int mid = n / 2;
    Integer al, ar, bl, br;
    al.number = first.number;
    al.size = mid;
    ar.number = first.number + mid;
    ar.size = n - mid;
    bl.number = second.number;
    bl.size = mid;
    br.number = second.number + mid;
    br.size = n - mid;

    Integer p1 = Integer::KaratsubaMultiply(al, bl);
    Integer p2 = Integer::KaratsubaMultiply(ar, br);
    Integer aplusb = al + ar;
    Integer cplusd = bl + br;
    Integer p3 = Integer::KaratsubaMultiply(aplusb, cplusd);
    p3 = p3 - p1 - p2;

    Integer result = p1.multiplyBy10n(n) + p3.multiplyBy10n(mid) + p2;
    return result.Get();
}

Integer Integer::multiplyBy10n(int n) const
{
    Integer result(*this);
    result.number = new int[size + n];
    for (int i = 0; i < size; i++) {
        result.number[i + n] = number[i];
    }
    for (int i = 0; i < n; i++) {
        result.number[i] = 0;
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
