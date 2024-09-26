#include "complex.h"
#include "cmath"

TComplex::TComplex() {
}

TComplex::TComplex(const int& r) {
    // TODO: podumat'
    this->re = r;
    this->im = 0;
}

TComplex::TComplex(const double& r, const double& i) {
    this->re = r;
    this->im = i;
}

// void TComplex::setReal(double r) {
//     this->re = r;
// }
// void TComplex::setImage(double i) {
//     this->im = i;
// }

bool TComplex::operator ==(TComplex c) {
    return (this->re == c.re) && (this->im == c.im);
}
ostream& operator<<(ostream& os, TComplex c) {
    if (c.im < 0) os << c.re << c.im << "i";
    else os << c.re << "+" << c.im << "i";

    return os;
}


// istream& operator>>(istream& is, TComplex& c) {
//     is >> c.re >> c.im;
//     return is;
// }

istream& operator>>(istream& is, TComplex& c) {
    double real, imag;
    if (is >> real >> imag) { // Проверяем успешность ввода
        c.re = real;
        c.im = imag;
        // c.setReal(real);
        // c.setImage(imag);
    }
    return is;
}

TComplex pow(TComplex base, int exponent) {
    TComplex result(1); // Начальное значение (1 + 0i)

    if (exponent == 0) {
        return result;
    }

    for (int i = 1; i <= abs(exponent); i++) {
        result = result * base; // Умножаем результат на базу
    }

    if (exponent < 0) {
        // Если степень отрицательная, возвращаем обратное значение
        return TComplex(result.re / (result.re * result.re + result.im * result.im),
                        -result.im / (result.re * result.re + result.im * result.im));
    }

    return result;
}

TComplex TComplex::operator*(TComplex c) {
    TComplex rc; // результирующее комплексное число
    rc.re = this->re*c.re - this->im*c.im;
    rc.im = this->re*c.im + this->im*c.re;

    return rc;
}

TComplex TComplex::operator/(TComplex c) {
    TComplex rc; // результирующее комплексное число

    // Вычисляем действительную и мнимую части
    rc.re = (this->re * c.re + this->im * c.im) / (c.re * c.re + c.im * c.im); // (a*c + b*d) / (c^2 + d^2)
    rc.im = (this->im * c.re - this->re * c.im) / (c.re * c.re + c.im * c.im); // (b*c - a*d) / (c^2 + d^2)

    return rc;
}

TComplex TComplex::operator+(TComplex c) {
    TComplex rc; // результирующее комплексное число
    rc.re = this->re+c.re;
    rc.im = this->im+c.im;

    return rc;
}

TComplex& TComplex::operator+=(TComplex c) {
    this->re = this->re+c.re;
    this->im = this->im+c.im;

    return *this;
}

// Унарный минус
TComplex& TComplex::operator-() {
    this->re = -this->re;
    this->im = -this->im;
    return *this;
}

// Бинарный минус
TComplex TComplex::operator-(TComplex c) {
    TComplex rc; // результирующее комплексное число
    rc.re = this->re-c.re;
    rc.im = this->im-c.im;

    return TComplex(this->re - c.re, this->im - c.im);
}

bool TComplex::operator<(TComplex c) {
//    // Вычисляем радиусы
//    double thisRadius = sqrt(this->re * this->re + this->im * this->im);
//    double otherRadius = sqrt(c.re * c.re + c.im * c.im);

//    // Если радиусы разные, сравниваем их
//    if (thisRadius != otherRadius) {
//        return thisRadius < otherRadius;
//    }

//    // Если радиусы равны, сравниваем углы
//    double thisAngle = atan2(this->im, this->re);
//    double otherAngle = atan2(c.im, c.re);

//    return thisAngle < otherAngle; // Сравниваем углы
    return this->re*this->re + this->im*this->im < c.re*c.re + c.im*c.im; // TODO: odobrit' na CR
}

bool TComplex::operator>(TComplex c) {
//    return !this->operator<(c); // ЖОСКО ПРОВЕРИТЬЬЬЬЬ
    return this->re*this->re + this->im*this->im > c.re*c.re + c.im*c.im; // TODO: odobrit' na CR x2

}

TComplex sqrt(TComplex num) {
    if (num.re == 0 && num.im == 0) {
        return TComplex(0, 0); // Квадратный корень из нуля
    }

    double r = sqrt(num.re * num.re + num.im * num.im); // Модуль
    double sqrtReal = sqrt((r + num.re) / 2);
    double sqrtImag = (num.im >= 0 ? 1 : -1) * sqrt((r - num.re) / 2); // Сигнум для мнимой части

    return TComplex(sqrtReal, sqrtImag);
}
