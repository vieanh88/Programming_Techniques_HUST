#include<bits/stdc++.h>
using namespace std;

int n_07;
const int MAX = 100;
int N_07[MAX], H_07[MAX];
int x[20];
int L_07;
// Kiem tra xem co the gan gia tri i tai vi tri a khong
bool check(int a, int i, int N_k, int H_k){
    if(i == 1){
        if(L_07 + 1 > H_k) return false;
        else return true;
    }
    else{
        if(N_k - a + L_07 < H_k) return false;
        else return true;
    }
}

// In ra cau hinh hop le
void solution(int N_k){
    for(int i = 1; i <= N_k; i++)
        cout << x[i];
    cout << endl;
}

// Quay lui thu cac cach chon bit thoa man dieu kien
void TRY(int a, int N_k, int H_k){
    for(int i = 0; i <= 1; i++){
        if(check(a, i, N_k, H_k)){
            x[a] = i;
            int pre = L_07;
            if(i == 1) L_07 += 1;
            if(a == N_k) solution(N_k);
            else{
                TRY(a + 1, N_k, H_k);
            }
            L_07 = pre; // Khoi phuc lai gia tri L sau moi nhanh
        }
    }
}

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main(){
    cout << "Ho va ten:Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    cin >> n_07;
    for(int i = 0; i < n_07; i++){
        cin >> N_07[i] >> H_07[i]; // Nhap N va H cho tung truong hop
    }
    cout << endl;
    for(int i = 0; i < n_07; i++){
        TRY(1, N_07[i], H_07[i]); // Goi ham quay lui cho moi bo du lieu
        cout << endl;
    }
}
