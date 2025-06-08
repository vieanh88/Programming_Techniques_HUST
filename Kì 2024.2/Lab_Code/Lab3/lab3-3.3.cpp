#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n, c[MAX][MAX]; //# s? th�nh ph? v� ma tr?n chi ph�
int cmin = INT_MAX; //# chi ph� di l?i nh? nh?t gi?a hai th�nh ph? kh�c nhau
int best = INT_MAX; //# t?ng chi ph� nh? nh?t c?n t�m, ban d?u d?t b?ng gi� tr? v� c�ng l?n INT_MAX = 2^31-1
int curr; //# t?ng chi ph� t?i th?i di?m hi?n t?i
int mark[MAX]; //# d�nh d?u nh?ng th�nh ph? d� di
int x[MAX]; //# luu gi? c�c th�nh ph? d� di

//# �oc du lieu v�o
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
    for(int i=0; i<MAX; i++)
        mark[i] = 0;
    curr = 0;
}

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
bool check_07(int k, int i){
    if(mark[i] == 1) return false;
    return true;
}

void solution_07(){
    best = min(best,curr);
}

//# Thuat to�n quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){

        if(check_07(k,i)){
            mark[i] = 1;
            curr += c[x[k-1]][i];

            x[k] = i;

            if(k == n) {
                curr += c[x[n]][1];
                solution_07();
                curr -= c[x[n]][1];
            }
            else TRY(k+1);

            mark[i] = 0;
            curr -= c[x[k-1]][i];
        }
    }
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main() {
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
