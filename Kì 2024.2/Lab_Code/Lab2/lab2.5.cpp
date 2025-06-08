#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    Complex tmpC_07;
    tmpC_07.real = a.real + b.real;
    tmpC_07.imag = a.imag + b.imag;
    return tmpC_07;
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
Complex operator - (Complex a, Complex b) {
    Complex tmpC_07;
    tmpC_07.real = a.real - b.real;
    tmpC_07.imag = a.imag - b.imag;
    return tmpC_07;
}

Complex operator * (Complex a, Complex b) {
    Complex tmpC_07;
    tmpC_07.real = a.real * b.real - a.imag * b.imag;
    tmpC_07.imag = a.real * b.imag + a.imag * b.real;
    return tmpC_07;
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
Complex operator / (Complex a, Complex b) {
    Complex tmpC_07;
    Complex inverse_07;
    inverse_07.real = b.real;
    inverse_07.imag = -b.imag;
    tmpC_07 = a * inverse_07;
    tmpC_07.real = tmpC_07.real / (b.real * b.real + b.imag * b.imag);
    tmpC_07.imag = tmpC_07.imag / (b.real * b.real + b.imag * b.imag);
    return tmpC_07;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;

    Complex a{real_a, img_a};
    Complex b{real_b, img_b};

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    return 0;
}
// Bài 2.5 - Ngyen Viet Anh - 5307
