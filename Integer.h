#ifndef INTEGER_H
#define INTEGER_H

#include <vector>

class Integer
{
    friend int operator+(const Integer, const Integer);
    friend int operator-(const Integer, const Integer);
    friend int operator*(const Integer, const Integer);

public:
    Integer();
    Integer(int);
    ~Integer();
    int Get() const;
    void Set(const int);
    void SetMultiplyMethod(int = 0);

    int size;
protected:
    int* number;

    static int (*multiply)(const Integer, const Integer);

    static int NormalMultiply(const Integer, const Integer);
    static int KaratsubaMultiply(const Integer, const Integer);
    int calculateDigits(int);
    void checkMemory();
};

#endif // INTEGER_H
