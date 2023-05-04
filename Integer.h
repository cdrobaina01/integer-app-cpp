#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
    friend int operator+(const Integer, const Integer);
    friend int operator-(const Integer, const Integer);
    friend int operator*(const Integer, const Integer);

public:
    Integer();
    Integer(int);
    Integer(const Integer&);
    Integer(const Integer*);
    ~Integer();

    int Get() const;
    void Set(const int);

    void SetMultiplyMethod(int (*)(const Integer, const Integer));

    static int NormalMultiply(const Integer, const Integer);
    static int KaratsubaMultiply(const Integer, const Integer);

protected:
    int* number;
    int size;

    int (*multiply)(const Integer, const Integer);

    int calculateDigits(int);
};

#endif // INTEGER_H
