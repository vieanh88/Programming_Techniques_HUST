#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
    // Ham tinh thanh phan cua hai vector a va b
    double x_07, y_07, z_07;
    z_07 = get<0>(a) * get<1>(b) - get<0>(b) * get<1>(a);
    x_07 = get<1>(a) * get<2>(b) - get<1>(b) * get<2>(a);
    y_07 = get<2>(a) * get<0>(b) - get<2>(b) * get<0>(a);
    return Vector(x_07, y_07, z_07);  // Tra ve vecto khoang cach
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307

int main() {
    cout << setprecision(2) << fixed;
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
    return 0;
}
