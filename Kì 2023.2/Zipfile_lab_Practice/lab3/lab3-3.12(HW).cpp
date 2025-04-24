#include<bits/stdc++.h>
using namespace std;

const int SO_DINH_TOI_DA = 100; // Số đỉnh tối đa
int so_dinh, so_dinh_can_chon; // Số đỉnh và số đỉnh tối đa cần chọn
int so_canh; // Số cạnh
vector<vector<int>> danh_sach_ke; // Danh sách kề
int da_chon[SO_DINH_TOI_DA]; // Lưu trữ đỉnh đã chọn
bool da_tham[SO_DINH_TOI_DA]; // Đánh dấu đỉnh đã thăm
int dem_cach_chon; // Đếm số cách chọn
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
void nhap_du_lieu(){
    cin >> so_dinh >> so_dinh_can_chon; // Nhập số đỉnh và số đỉnh tối đa cần chọn
    cin >> so_canh; // Nhập số cạnh
    danh_sach_ke.resize(so_dinh); // Khởi tạo danh sách kề
    for(int i = 0; i < so_canh; i++){
        int dinh1, dinh2;
        cin >> dinh1 >> dinh2;

        danh_sach_ke[dinh1 - 1].push_back(dinh2 - 1); // Thêm đỉnh dinh2 vào danh sách kề của dinh1
        danh_sach_ke[dinh2 - 1].push_back(dinh1 - 1); // Thêm đỉnh dinh1 vào danh sách kề của dinh2
    }

    for(int i = 0; i < so_dinh; i++){
        da_tham[i] = false; // Khởi tạo các đỉnh chưa thăm
    }
    dem_cach_chon = 0; // Khởi tạo số cách chọn
}

bool hop_le(int a, int i){
    if(a == 0) return true; // Nếu a = 0, luôn hợp lệ
    if(da_tham[i]) return false; // Nếu đỉnh đã thăm, không hợp lệ

    int index = 0;
    for(int j = 0; j < danh_sach_ke[da_chon[a-1]].size(); j++){
        if(i == danh_sach_ke[da_chon[a-1]][j]) index++;
    }
    if(index == 0) return false; // Nếu không kề với đỉnh trước đó, không hợp lệ

    return true; // Nếu đủ điều kiện, hợp lệ
}

void ghi_nhan_cach_chon(){
    dem_cach_chon++; // Tăng số cách chọn
}

void THU(int a){
    for(int i = 0; i < so_dinh; i++){
        if(hop_le(a, i)){
            da_tham[i] = true; // Đánh dấu đỉnh đã thăm
            da_chon[a] = i; // Lưu lại đỉnh đã chọn

            if(a == so_dinh_can_chon) ghi_nhan_cach_chon(); // Nếu đã chọn đủ số đỉnh cần thiết, thực hiện ghi_nhan_cach_chon
            else THU(a + 1); // Thử tiếp tục chọn đỉnh tiếp theo

            da_tham[i] = false; // Trả lại trạng thái ban đầu
        }
    }
}

int main(){
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    nhap_du_lieu(); // Nhập dữ liệu
    THU(0); // Bắt đầu thử các cách chọn
    cout << dem_cach_chon / 2; // In ra kết quả, chia 2 vì mỗi cách chọn được đếm hai lần
}
