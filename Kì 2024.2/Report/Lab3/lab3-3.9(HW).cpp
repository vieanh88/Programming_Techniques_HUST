#include<bits/stdc++.h>
using namespace std;

// Bi?n toàn c?c
int n_07, k1_07, k2_07; // S? lu?ng ph?n t?, gi?i h?n du?i và trên c?a dãy bit 1 liên ti?p
int x[1000]; // M?ng luu dãy nh? phân
int L_07; // Bi?n d?m s? lu?ng bit 1 liên ti?p t?i th?i di?m hi?n t?i

// Hàm ki?m tra xem có th? d?t giá tr? i t?i v? trí a hay không
bool check(int a,int i){
    if(a == 1) return true; // ? v? trí d?u tiên thì luôn h?p l?
    else{
        if(i == 0){ // N?u gán 0 t?i v? trí a
            if(x[a-1] == 0) return false; // Hai s? 0 liên ti?p là không h?p l?
            else if(L_07 < k1_07) return false; // S? lu?ng bit 1 tru?c dó chua d? t?i thi?u
        }
        else{ // N?u gán 1 t?i v? trí a
            if(x[a-1] == 0){
                if(n_07 - a + 1 < k1_07) return false; // Không còn d? v? trí d? d?t t?i thi?u k1 bit 1
            }
            else{
                if(L_07 + 1 > k2_07) return false; // Vu?t quá s? lu?ng bit 1 liên ti?p cho phép
            }
            return true;
        }
    }
}

// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307

// Hàm in ra m?t c?u hình h?p l?
void solution(){
    for(int i=1; i<=n_07; i++)
        cout << x[i];
    cout << endl;
}

// Hàm quay lui
void TRY(int a){
    for (int i = 0; i <= 1; i++){
        if(check(a,i)){
            x[a] = i;
            int preL = L_07; // Luu lai giá tri L truoc dó d? backtrack
            if(i == 1){
                if(x[a-1] == 1){
                    L_07 += 1;
                }
                else L_07 = 1;
            }
            else L_07 = 0;

            if(a == n_07) solution(); // N?u dã d? d? dài thì in ra
            else TRY(a+1); // G?i d? quy cho v? trí ti?p theo

            L_07 = preL; // Quay lui giá tr? L
        }
    }
    
}

int main(){
	cout << "Ho va ten:Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    cin >> n_07 >> k1_07 >> k2_07; // Nh?p d?u vào
    TRY(1); // B?t d?u quay lui t? v? trí d?u tiên
}
