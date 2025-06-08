#include <iostream>
using namespace std;

//# viet hàm arr_sum
template <typename T>
//Ho va ten Nguyen Viet Anh
//MSSV: 20215307
T arr_sum(T a[], int n, T b[], int m){
    T sum_07 = 0;
    for(int i=0; i<n; i++)
        sum_07 += a[i];
    for(int i=0; i<m; i++)
        sum_07 += b[i];
    return sum_07;
}

int main() {
    int val;
    cin >> val;

    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
// Bài 2.7 - Nguyen Viet Anh - 5307
