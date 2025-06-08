#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Định nghĩa cấu trúc lưu trữ thông tin của một wall
struct wall {
    int ai; // Số lượng địch
    int ki; // Khả năng tiêu diệt của tường

    wall(int ai, int ki) {
        this->ai = ai;
        this->ki = ki;
    }
};

// Cấu trúc so sánh để sắp xếp tường trong hàng đợi
struct compare {
    bool operator() (wall a, wall b) {
        int ra, rb;

        // Tính giá trị ưu tiên của tường a
        if (a.ai <= a.ki) ra = a.ai;
        else ra = a.ki;

        // Tính giá trị ưu tiên của tường b
        if (b.ai <= b.ki) rb = b.ai;
        else rb = b.ki;

        return ra < rb; // So sánh giá trị ưu tiên để sắp xếp
    }
};

// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307
int n, s;
priority_queue<wall, vector<wall>, compare> now; // Hàng đợi ưu tiên chứa các tường
int tong_dich = 0, dich_da_giet = 0; // Tổng số địch và số địch đã bị tiêu diệt

// Hàm thực hiện thuật toán xử lý tường
void algo() {
    while (!now.empty() && s > 0) {
        wall a = now.top(); // Lấy tường có độ ưu tiên cao nhất
        now.pop(); // Loại bỏ tường này khỏi hàng đợi ưu tiên
        if (a.ai <= a.ki) {
            // Nếu số lượng địch ít hơn hoặc bằng khả năng tiêu diệt của tường
            dich_da_giet += a.ai; // Toàn bộ địch bị tiêu diệt
        } else {
            // Nếu số lượng địch lớn hơn khả năng tiêu diệt của tường
            int now_enemy = a.ai - a.ki; // Số địch còn lại sau khi tiêu diệt
            now.push(wall(now_enemy, a.ki)); // Đẩy lại số địch còn lại vào hàng đợi với tường có cùng khả năng tiêu diệt
            dich_da_giet += a.ki; // Cập nhật số địch bị tiêu diệt
        }
        s -= 1; // Giảm số lượng lượt tấn công còn lại
    }
}

// Hàm nhập dữ liệu
void input() {
    cin >> n >> s; // Nhập số lượng tường và số lượt tấn công
    int i = 0;
    while (i < n) {
        int ai, ki;
        cin >> ai >> ki; // Nhập số địch và khả năng tiêu diệt của từng tường
        now.push(wall(ai, ki)); // Đẩy tường vào hàng đợi ưu tiên
        tong_dich += ai; // Cập nhật tổng số địch
        i++;
    }
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input(); // Nhập dữ liệu
    algo(); // Thực hiện thuật toán
    cout << tong_dich - dich_da_giet; // In ra số địch còn lại chưa bị tiêu diệt
}