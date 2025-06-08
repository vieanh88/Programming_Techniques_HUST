#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Dinh nghia cau truc luu tru thong tin cua mot tuong
struct wall {
    int ai; // So luong dich
    int ki; // Kha nang tieu diet cua tuong

    wall(int ai, int ki) {
        this->ai = ai;
        this->ki = ki;
    }
};

// Cau truc so sanh de sap xep tuong trong hang doi
struct compare {
    bool operator() (wall a, wall b) {
        int ra, rb;

        // Tinh gia tri uu tien cua tuong a
        if (a.ai <= a.ki) ra = a.ai;
        else ra = a.ki;

        // Tinh gia tri uu tien cua tuong b
        if (b.ai <= b.ki) rb = b.ai;
        else rb = b.ki;

        return ra < rb; // So sanh gia tri uu tien de sap xep
    }
};

// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307
int n_07, s_07;
priority_queue<wall, vector<wall>, compare> now; // Hang doi uu tien chua cac tuong
int tong_dich = 0, dich_da_giet = 0; // Tong so dich va so dich da bi tieu diet

// Ham thuc hien thuat toan xu ly tuong
void algo() {
    while (!now.empty() && s_07 > 0) {
        wall a = now.top(); // Lay tuong co do uu tien cao nhat
        now.pop(); // Loai bo tuong nay khoi hang doi uu tien
        if (a.ai <= a.ki) {
            // Neu so luong dich nho hon hoac bang kha nang tieu diet cua tuong
            dich_da_giet += a.ai; // Tieu diet toan bo dich
        } else {
            // Neu so luong dich lon hon kha nang tieu diet cua tuong
            int now_enemy = a.ai - a.ki; // So dich con lai sau khi tieu diet
            now.push(wall(now_enemy, a.ki)); // Day lai so dich con lai vao hang doi voi tuong co cung kha nang
            dich_da_giet += a.ki; // Cap nhat so dich da tieu diet
        }
        s_07 -= 1; // Giam so luot tan cong con lai
    }
}

// Ham nhap du lieu
void input() {
    cin >> n_07 >> s_07; // Nhap so luong tuong va so luot tan cong
    int i = 0;
    while (i < n_07) {
        int ai, ki;
        cin >> ai >> ki; // Nhap so dich va kha nang tieu diet cua tuong
        now.push(wall(ai, ki)); // Day tuong vao hang doi uu tien
        tong_dich += ai; // Cap nhat tong so dich
        i++;
    }
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input(); // Nhap du lieu
    algo(); // Thuc hien thuat toan
    cout << tong_dich - dich_da_giet; // In ra so dich con lai chua bi tieu diet
}
