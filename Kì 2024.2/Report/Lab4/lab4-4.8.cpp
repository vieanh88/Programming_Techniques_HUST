#include <iostream>
#include <map>
using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    // Ham tinh hop cua hai tap a va b
    map<T, double> c = a;  // Khoi tao tap hop ket qua bang tap hop a
    for (const auto &e : b) {
        if (c.count(e.first)) {
            c[e.first] = max(e.second, c[e.first]);  // Neu phan tu e co trong ca hai tap hop, lay gia tri lon hon
        } else {
            c.insert(e);  // Neu phan tu e chi co trong b, them no vao tap hop ket qua
        }
    }
    return c;
}
// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    // Ham tinh giao cua hai tap a va b
    map<T, double> c;  // Khoi tao tap hop ket qua
    for (const auto &x : a) {
        const auto it = b.find(x.first);  // Tim phan tu x trong b
        if (it != b.end()) {
            c[x.first] = min(x.second, it->second);  // Neu phan tu x co trong ca hai tap hop, lay gia tri nho hon
        }
    }
    return c;  // Tra ve tap hop ket qua
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";  // In từng phần tử của tập mờ a
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}}; 
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
    return 0;
}
