#include <bits/stdc++.h>
using namespace std;
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
// Hàm tính diện tích lớn nhất của hình chữ nhật trong histogram
int dienTichLonNhatTrongHistogram(vector<int> histogram) {
    stack<int> s;
    int dienTichLonNhat = 0;
    int dienTich = 0;
    int i = 0;
    int size = histogram.size();

    // Duyệt từng phần tử để tính cận trái và phải
    while (i < size) {
        if (s.empty() || histogram[s.top()] <= histogram[i]) {
            // Thêm cận trái của phần tử tiếp theo
            s.push(i);
            // Tăng chỉ số để xét phần tử tiếp theo
            i++;
        } else {
            // Tìm cận phải của phần tử thứ i-1 trong stack
            int top = s.top();
            s.pop();
            // Tính số ô theo 2 cận trái và phải
            dienTich = histogram[top] * (s.empty() ? i : (i - s.top() - 1));
            // Cập nhật diện tích lớn nhất nếu tìm được giá trị tốt hơn
            if (dienTich > dienTichLonNhat) {
                dienTichLonNhat = dienTich;
            }
        }
    }

    // Xử lý các phần tử còn lại trong stack
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        dienTich = histogram[top] * (s.empty() ? i : (i - s.top() - 1));
        if (dienTich > dienTichLonNhat) {
            dienTichLonNhat = dienTich;
        }
    }
    
    // Trả về diện tích lớn nhất
    return dienTichLonNhat;
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV:20215307\n";
    int n, in;
    cin >> n;
    vector<int> chieuCao;
    
    // Nhập danh sách chiều cao của các cột trong histogram
    for (int i = 0; i < n; ++i) {
        cin >> in;
        chieuCao.push_back(in);
    }
    
    // In ra diện tích lớn nhất của hình chữ nhật trong histogram
    cout << dienTichLonNhatTrongHistogram(chieuCao) << endl;
    return 0;
}
