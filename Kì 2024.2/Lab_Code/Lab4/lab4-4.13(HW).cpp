#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307

// Ham dem so luong xau con co so luong '0' va '1' bang nhau
int dem_xau_con(const string& s) {
    int n_07 = s.length();
    unordered_map<int, int> dem_chenhlech;
    dem_chenhlech[0] = 1; // Khoi tao cho truong hop chenh lech bang 0

    int chenhlech = 0; // Chenh lech giua so luong '0' va '1'
    int result_07 = 0;    // Ket qua: so luong xau con hop le

    // Duyet qua tung ky tu trong xau nhi phan
    for (int i = 0; i < n_07; ++i) {
        if (s[i] == '0') {
            chenhlech--; // Gap '0', giam chenh lech
        } else {
            chenhlech++; // Gap '1', tang chenh lech
        }

        // Kiem tra xem gia tri chenh lech da xuat hien truoc do bao nhieu lan
        if (dem_chenhlech.find(chenhlech) != dem_chenhlech.end()) {
            result_07 += dem_chenhlech[chenhlech]; // Cong so lan xuat hien vao ket qua
        }

        dem_chenhlech[chenhlech]++; // Cap nhat so lan xuat hien cua gia tri chenh lech hien tai
    }

    return result_07; // Tra ve ket qua
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    string s;
    cin >> s; // Nhan xau nhi phan tu nguoi dung
    cout << dem_xau_con(s) << endl; // In ra so luong xau con hop le

    return 0;
}
