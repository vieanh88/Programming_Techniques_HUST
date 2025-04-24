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
    Complex tmpC;
    tmpC.real = a.real + b.real;
    tmpC.imag = a.imag + b.imag;
    return tmpC;
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
Complex operator - (Complex a, Complex b) {
    Complex tmpC;
    tmpC.real = a.real - b.real;
    tmpC.imag = a.imag - b.imag;
    return tmpC;
}

Complex operator * (Complex a, Complex b) {
    Complex tmpC;
    tmpC.real = a.real * b.real - a.imag * b.imag;
    tmpC.imag = a.real * b.imag + a.imag * b.real;
    return tmpC;
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
Complex operator / (Complex a, Complex b) {
    Complex tmpC;
    Complex inverse;
    inverse.real = b.real;
    inverse.imag = -b.imag;
    tmpC = a * inverse;
    tmpC.real = tmpC.real / (b.real * b.real + b.imag * b.imag);
    tmpC.imag = tmpC.imag / (b.real * b.real + b.imag * b.imag);
    return tmpC;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    printf("Ho Va Ten: Nguyen Viet Anh\n");
    printf("MSSV:20215307\n");
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
