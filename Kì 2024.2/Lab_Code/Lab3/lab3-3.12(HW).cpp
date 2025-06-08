#include<bits/stdc++.h>
using namespace std;

const int SO_DINH_TOI_DA = 100;
int so_dinh_07, so_dinh_can_chon_07;
int so_canh_07;
vector<vector<int>> danh_sach_ke_07;
int da_chon_07[SO_DINH_TOI_DA];
bool da_tham_07[SO_DINH_TOI_DA];
int dem_cach_chon_07;

//Ho va ten: Nguyen Viet An
//MSSV: 20215307
// Nhap thong tin do thi va khoi tao bien
void nhap_du_lieu(){
    cin >> so_dinh_07 >> so_dinh_can_chon_07;
    cin >> so_canh_07;
    danh_sach_ke_07.resize(so_dinh_07);
    for(int i = 0; i < so_canh_07; i++){
        int dinh1, dinh2;
        cin >> dinh1 >> dinh2;
        danh_sach_ke_07[dinh1 - 1].push_back(dinh2 - 1);
        danh_sach_ke_07[dinh2 - 1].push_back(dinh1 - 1);
    }
    for(int i = 0; i < so_dinh_07; i++){
        da_tham_07[i] = false;
    }
    dem_cach_chon_07 = 0;
}

// Kiem tra xem co the chon dinh i tai buoc a khong
bool hop_le(int a, int i){
    if(a == 0) return true;
    if(da_tham_07[i]) return false;

    int index = 0;
    for(int j = 0; j < danh_sach_ke_07[da_chon_07[a-1]].size(); j++){
        if(i == danh_sach_ke_07[da_chon_07[a-1]][j]) index++;
    }
    if(index == 0) return false;

    return true;
}

// Tang bien dem khi tim duoc 1 cach chon hop le
void ghi_nhan_cach_chon(){
    dem_cach_chon_07++;
}

// Quay lui thu cac cach chon
void THU(int a){
    for(int i = 0; i < so_dinh_07; i++){
        if(hop_le(a, i)){
            da_tham_07[i] = true;
            da_chon_07[a] = i;

            if(a == so_dinh_can_chon_07) ghi_nhan_cach_chon();
            else THU(a + 1);

            da_tham_07[i] = false;
        }
    }
}

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main(){
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    nhap_du_lieu();
    THU(0);
    cout << dem_cach_chon_07 / 2;
}
