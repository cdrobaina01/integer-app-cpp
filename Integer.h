#ifndef INTEGER_H
#define INTEGER_H

#include <math.h>

class Integer
{
    friend Integer operator+(const Integer&, const Integer&);
    friend Integer operator-(const Integer&, const Integer&);
    friend Integer operator*(const Integer&, const Integer&);

public:
    Integer();
    Integer(const int);
    ~Integer();
    int Get() const;
    void Set(const int);
    static void SetMultiplyMethod(bool = false);
    static Integer restar(const Integer&, const Integer&);

protected:
    int* array;
    int size;
    int calculateDigits(int);
    Integer multiplyBy10n(int) const;
    static Integer (*multiply)(const Integer&, const Integer&);
    static Integer NormalMultiply(const Integer&, const Integer&);
    static Integer KaratsubaMultiply(const Integer&, const Integer&);
};

#endif // INTEGER_H
