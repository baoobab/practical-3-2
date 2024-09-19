#include "complex.h"


TComplex::TComplex() {
}

TComplex::TComplex(const int& r) {
    // TODO: podumat'
    this->re = r;
    this->im = 0;
}

bool TComplex::operator ==(TComplex c) {
    return (this->re == c.re) && (this->im == c.im);
}
ostream& operator<<(ostream& os, TComplex c) {
    os << c.re << "+" << c.im << "i";
    return os;
}


istream& operator>>(istream& is, TComplex& c) {
    is >> c.re >> c.im;
    return is;
}

TComplex TComplex::operator*(TComplex c) {
    TComplex rc; // результирующее комплексное число
    rc.re = this->re*c.re - this->im*c.im;
    rc.im = this->re*c.im + this->im*c.re;

    return rc;
}

TComplex TComplex::operator+(TComplex c) {
    TComplex rc; // результирующее комплексное число
    rc.re = this->re+c.re;
    rc.im = this->im+c.im;

    return rc;
}
