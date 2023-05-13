#ifndef INTEGER_H
#define INTEGER_H

#include <math.h>

class Integer
{
    friend int operator+(const Integer&, const Integer&);
    friend int operator-(const Integer&, const Integer&);
    friend int operator*(const Integer&, const Integer&);

public:
    Integer();
    Integer(const int);
    ~Integer();
    int Get() const;
    void Set(const int);
    static void SetMultiplyMethod(bool = false);

protected:
    int* array;
    int size;
    int calculateDigits(int);
    Integer multiplyBy10n(int) const;
    static int (*multiply)(const Integer, const Integer);
    static int NormalMultiply(const Integer, const Integer);
    static int KaratsubaMultiply(const Integer, const Integer);
};

#endif // INTEGER_H
