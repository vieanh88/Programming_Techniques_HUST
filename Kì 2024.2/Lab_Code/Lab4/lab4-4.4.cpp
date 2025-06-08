#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307

void delete_even(vector<int> &a) {
    // Ham xoa cac phan tu chan khỏi vector a
    a.erase(remove_if(a.begin(), a.end(), [](int a) {
        return (a % 2 == 0);  // kiem tra phan tu chan
    }), a.end());  // xoa cac phan tu chan
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307

void sort_decrease(vector<int> &a) {
    // Ham sap xep vector a giam dan
    sort(a.rbegin(), a.rend());
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    // Ham hop nhat hai vector a và b, sau do sap xep theo thu tu giam dan
    vector<int> sum;
    for(int v : a) {
        sum.push_back(v);
    }
    for(int v : b) {
        sum.push_back(v);
    }
    sort(sum.rbegin(), sum.rend());  // Sap xep theo thu tu giam dan
    return sum;
}

int main() {
    int m, n, u;
    vector<int> a, b;
    
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++) {
        cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
