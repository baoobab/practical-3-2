#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include "cmath"
using namespace std;

class TComplex {
private:
    double re, im;

    void setReal(double);
    void setImage(double);
public:
    TComplex();
    TComplex(const int&); // TODO: mb double
    TComplex(const double&, const double&);
    bool operator==(TComplex);
    bool operator<(TComplex);
    bool operator>(TComplex); // TODO: proverit' ЖОООООООСКО
    TComplex operator*(TComplex);
    TComplex operator/(TComplex);
    TComplex operator+(TComplex);
    TComplex& operator-(); // унарный минус
    TComplex operator-(TComplex); // бинарный минус
    TComplex& operator +=(TComplex); // TODO: proverit'
    friend TComplex sqrt(TComplex);
    friend ostream& operator<<(ostream&, TComplex);
    friend istream& operator>>(istream&, TComplex&);
    friend TComplex pow(TComplex&, int);
};

#endif // COMPLEX_H
