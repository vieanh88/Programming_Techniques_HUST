#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
// Hàm đếm số lượng xâu con có số lượng '0' và '1' bằng nhau
int dem_xau_con(const string& s) {
    int n = s.length();
    unordered_map<int, int> dem_chenhlech;
    dem_chenhlech[0] = 1; // Khởi tạo cho trường hợp chênh lệch bằng 0

    int chenhlech = 0; // Chênh lệch giữa số lượng '0' và '1'
    int result = 0; // Kết quả: số lượng xâu con hợp lệ

    // Duyệt qua từng ký tự trong xâu nhị phân
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            chenhlech--; // Gặp '0', giảm chênh lệch
        } else {
            chenhlech++; // Gặp '1', tăng chênh lệch
        }

        // Kiểm tra xem giá trị chênh lệch đã xuất hiện trước đó bao nhiêu lần
        if (dem_chenhlech.find(chenhlech) != dem_chenhlech.end()) {
            result += dem_chenhlech[chenhlech]; // Cộng số lần xuất hiện vào kết quả
        }

        dem_chenhlech[chenhlech]++; // Cập nhật số lần xuất hiện của giá trị chênh lệch hiện tại
    }

    return result; // Trả về kết quả
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    string s;
    cin >> s; // Nhập xâu nhị phân từ người dùng

    cout << dem_xau_con(s) << endl; // In ra số lượng xâu con hợp lệ

    return 0;
}