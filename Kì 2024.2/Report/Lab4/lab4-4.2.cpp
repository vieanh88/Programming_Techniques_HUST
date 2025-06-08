#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double distance(Point a, Point b) {
    // Hàm tính khoang cách a và b
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double area(Point a, Point b, Point c) {
    // Hàm tinh khoang cach tam giac
    double ab = distance(a, b);  // Tinh do dai canh AB
    double bc = distance(b, c);  // Tinh do dai canh BC
    double ca = distance(c, a);  // Tinh do dai canh CA
    double p = (ab + bc + ca) / 2;  // Tinh nua chu vi tam giac
    double area_07 = sqrt(p * (p - ab) * (p - bc) * (p - ca));  // su dung cong thuc Heron
    return area_07;
}
// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307

int main() {
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
