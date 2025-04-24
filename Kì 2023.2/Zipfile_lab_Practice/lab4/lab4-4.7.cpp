#include <iostream>
#include <set>
using namespace std;

template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    // Hàm tính hợp của hai tập hợp a và b
    set<T> union_set;  // Tập hợp kết quả
    for (T tmp : a) {
        union_set.insert(tmp);  // Thêm các phần tử của tập hợp a vào tập hợp kết quả
    }
    for (T tmp : b) {
        union_set.insert(tmp);  // Thêm các phần tử của tập hợp b vào tập hợp kết quả
    }
    return union_set;  // Trả về tập hợp kết quả
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    // Hàm tính giao của hai tập hợp a và b
    set<T> c;  // Tập hợp kết quả
    for (T v : a) {
        int index = 0;
        for (T u : b) {
            if (v == u) {
                index++;  // Nếu phần tử v có trong cả hai tập hợp, tăng biến đếm
                break;
            }
        }
        if (index != 0) c.insert(v);  // Nếu phần tử v có trong cả hai tập hợp, thêm vào tập hợp kết quả
    }
    return c;
}

template<class T>
void print_set(const std::set<T> &a) {
    for (const T &x : a) {
        std::cout << x << ' '; 
    }
    std::cout << std::endl;
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV:20215307\n";
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b); 
    std::cout << "Union: "; 
    print_set(c);
    std::cout << "Intersection: "; 
    print_set(d);
    return 0;
}