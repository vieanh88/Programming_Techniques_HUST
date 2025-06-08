#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    // Hàm xóa các phần tử chẵn khỏi vector a
    a.erase(remove_if(a.begin(), a.end(), [](int a) {
        return (a % 2 == 0);  // Kiểm tra phần tử có phải là số chẵn không
    }), a.end());  // Xóa các phần tử chẵn
}

void sort_decrease(vector<int> &a) {
    // Hàm sắp xếp vector a giảm dần
    sort(a.rbegin(), a.rend());
}

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    // Hàm hợp nhất hai vector a và b, sau đó sắp xếp theo thứ tự giảm dần
    vector<int> sum;  // Vector kết quả
    for(int v : a) {
        sum.push_back(v);  // Thêm các phần tử của a vào sum
    }
    for(int v : b) {
        sum.push_back(v);  // Thêm các phần tử của b vào sum
    }
    sort(sum.rbegin(), sum.rend());  // Sắp xếp vector sum theo thứ tự giảm dần
    return sum;
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
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