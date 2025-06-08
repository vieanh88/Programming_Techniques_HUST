#include<bits/stdc++.h>
using namespace std;

// Bi?n to�n c?c
int n_07, k1_07, k2_07; // S? lu?ng ph?n t?, gi?i h?n du?i v� tr�n c?a d�y bit 1 li�n ti?p
int x[1000]; // M?ng luu d�y nh? ph�n
int L_07; // Bi?n d?m s? lu?ng bit 1 li�n ti?p t?i th?i di?m hi?n t?i

// H�m ki?m tra xem c� th? d?t gi� tr? i t?i v? tr� a hay kh�ng
bool check(int a,int i){
    if(a == 1) return true; // ? v? tr� d?u ti�n th� lu�n h?p l?
    else{
        if(i == 0){ // N?u g�n 0 t?i v? tr� a
            if(x[a-1] == 0) return false; // Hai s? 0 li�n ti?p l� kh�ng h?p l?
            else if(L_07 < k1_07) return false; // S? lu?ng bit 1 tru?c d� chua d? t?i thi?u
        }
        else{ // N?u g�n 1 t?i v? tr� a
            if(x[a-1] == 0){
                if(n_07 - a + 1 < k1_07) return false; // Kh�ng c�n d? v? tr� d? d?t t?i thi?u k1 bit 1
            }
            else{
                if(L_07 + 1 > k2_07) return false; // Vu?t qu� s? lu?ng bit 1 li�n ti?p cho ph�p
            }
            return true;
        }
    }
}

// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307

// H�m in ra m?t c?u h�nh h?p l?
void solution(){
    for(int i=1; i<=n_07; i++)
        cout << x[i];
    cout << endl;
}

// H�m quay lui
void TRY(int a){
    for (int i = 0; i <= 1; i++){
        if(check(a,i)){
            x[a] = i;
            int preL = L_07; // Luu lai gi� tri L truoc d� d? backtrack
            if(i == 1){
                if(x[a-1] == 1){
                    L_07 += 1;
                }
                else L_07 = 1;
            }
            else L_07 = 0;

            if(a == n_07) solution(); // N?u d� d? d? d�i th� in ra
            else TRY(a+1); // G?i d? quy cho v? tr� ti?p theo

            L_07 = preL; // Quay lui gi� tr? L
        }
    }
    
}

int main(){
	cout << "Ho va ten:Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    cin >> n_07 >> k1_07 >> k2_07; // Nh?p d?u v�o
    TRY(1); // B?t d?u quay lui t? v? tr� d?u ti�n
}
