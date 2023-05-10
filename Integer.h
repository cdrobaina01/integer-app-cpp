#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
    friend Integer operator+(const Integer&, const Integer&);
    friend Integer operator-(const Integer&, const Integer&);
    friend int operator*(const Integer, const Integer);

public:
    Integer();
    Integer(const int);
    ~Integer();
    int Get() const;
    void Set(int);
    void SetMultiplyMethod(int = 0);

protected:
    int* number;
    int size;
    int calculateDigits(int);
    Integer multiplyBy10n(int) const;
    int (*multiply)(const Integer, const Integer);
    static int NormalMultiply(const Integer, const Integer);
    static int KaratsubaMultiply(const Integer, const Integer);
};

#endif // INTEGER_H
