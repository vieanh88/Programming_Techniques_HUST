#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
    // Hàm tính tích chéo của hai vector a và b
    double x, y, z;
    z = get<0>(a) * get<1>(b) - get<0>(b) * get<1>(a);  // Thành phần z của tích chéo
    x = get<1>(a) * get<2>(b) - get<1>(b) * get<2>(a);  // Thành phần x của tích chéo
    y = get<2>(a) * get<0>(b) - get<2>(b) * get<0>(a);  // Thành phần y của tích chéo
    return Vector(x, y, z);  // Trả về vector kết quả
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    cout << setprecision(2) << fixed;
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
    return 0;
}