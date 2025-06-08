#include <bits/stdc++.h>
using namespace std;

// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307

// Ham tinh dien tich lon nhat cua hinh chu nhat trong histogram
int dienTichLonNhatTrongHistogram(vector<int> histogram) {
    stack<int> s;
    int dienTichLonNhat_07 = 0;
    int dienTich_07 = 0;
    int i = 0;
    int size = histogram.size();

    // Duyet tung phan tu de tinh can trai va phai
    while (i < size) {
        if (s.empty() || histogram[s.top()] <= histogram[i]) {
            // Them can trai cua phan tu tiep theo
            s.push(i);
            // Tang chi so de xet phan tu tiep theo
            i++;
        } else {
            // Tim can phai cua phan tu thu i-1 trong stack
            int top = s.top();
            s.pop();
            // Tinh so o theo 2 can trai va phai
            dienTich_07 = histogram[top] * (s.empty() ? i : (i - s.top() - 1));
            // Cap nhat dien tich lon nhat neu tim duoc gia tri tot hon
            if (dienTich_07 > dienTichLonNhat_07) {
                dienTichLonNhat_07 = dienTich_07;
            }
        }
    }

    // Xu ly cac phan tu con lai trong stack
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        dienTich_07 = histogram[top] * (s.empty() ? i : (i - s.top() - 1));
        if (dienTich_07 > dienTichLonNhat_07) {
            dienTichLonNhat_07 = dienTich_07;
        }
    }
    
    // Tra ve dien tich lon nhat
    return dienTichLonNhat_07;
}

// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307
int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV:20215307\n";
    int n, in;
    cin >> n;
    vector<int> chieuCao;
    
    // Nhap danh sach chieu cao cua cac cot trong histogram
    for (int i = 0; i < n; ++i) {
        cin >> in;
        chieuCao.push_back(in);
    }
    
    // In ra dien tich lon nhat cua hinh chu nhat trong histogram
    cout << dienTichLonNhatTrongHistogram(chieuCao) << endl;
    return 0;
}
