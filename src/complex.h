#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class TComplex {
private:
    double re, im;
public:
    TComplex();
    TComplex(const int&); // TODO: mb double
    bool operator==(TComplex);
    TComplex operator*(TComplex);
    TComplex operator+(TComplex);
    TComplex operator-(); // унарный минус
    TComplex operator-(TComplex); // бинарный минус
    friend TComplex sqrt(TComplex);
    friend ostream& operator<<(ostream&, TComplex);
    friend istream& operator>>(istream&, TComplex&);
};

#endif // COMPLEX_H
