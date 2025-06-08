#include <iostream>
#include <set>

using namespace std;

template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    // Ham tinh hop cua hai tap hop a va b
    set<T> union_07;  // Tap hop ket qua
    for (T tmp : a) {
        union_07.insert(tmp);  // Them cac phan tu cua tap hop a vao tap hop ket qua
    }
    for (T tmp : b) {
        union_07.insert(tmp);  // Them cac phan tu cua tap hop b vao tap hop ket qua
    }
    return union_07;  // Tra ve tap hop ket qua
}

// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    // Ham tinh giao cua hai tap hop a va b
    set<T> c;  // Tap hop ket qua
    for (T v : a) {
        int index = 0;
        for (T u : b) {
            if (v == u) {
                index++;  // Neu phan tu v co trong ca hai tap hop, tang bien dem
                break;
            }
        }
        if (index != 0) c.insert(v);  // Neu phan tu v co trong ca hai tap hop, them vao tap hop ket qua
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
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);
    
    std::cout << "Union: "; print_set(c);
    std::cout << "Intersection: "; print_set(d);
    
    return 0;
}
