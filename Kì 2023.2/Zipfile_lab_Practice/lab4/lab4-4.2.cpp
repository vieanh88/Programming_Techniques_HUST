#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double distance(Point a, Point b) {
    // Hàm tính khoảng cách giữa hai điểm a và b
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double area(Point a, Point b, Point c) {
    // Hàm tính diện tích tam giác được tạo bởi ba điểm a, b, c
    double ab = distance(a, b);  // Tính độ dài cạnh AB
    double bc = distance(b, c);  // Tính độ dài cạnh BC
    double ca = distance(c, a);  // Tính độ dài cạnh CA
    double p = (ab + bc + ca) / 2;  // Tính nửa chu vi tam giác
    double area = sqrt(p * (p - ab) * (p - bc) * (p - ca));  // Sử dụng công thức Heron
    return area;
}

// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
