#include<bits/stdc++.h>
using namespace std;
int n;
const int MAX = 100;
int N[MAX],H[MAX];
int x[20];
int L;

bool check(int a, int i,int N_k, int H_k){
    if(i == 1){
        if(L + 1 > H_k) return false;
        else return true;
    }
    else{
        if(N_k - a + L < H_k) return false;
        else return true;
    }

}
void solution(int N_k){
    for(int i=1; i<=N_k; i++)
        cout << x[i];
    cout << endl;
}
//Ho va ten: Nguyen Viet Anh
//MSSV:20215307
void TRY(int a, int N_k, int H_k){
    for(int i = 0;i<=1;i++){
        if(check(a,i,N_k,H_k)){
            x[a] = i;
            int pre = L;
            if(i == 1) L+=1;
            if(a == N_k) solution(N_k);
            else{
                TRY(a+1,N_k,H_k);
            }
            L = pre;
        }
    }
}
int main(){
	cout << "Ho va ten:Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> N[i] >> H[i];
    }
    cout << endl;
    for(int i = 0;i<n;i++){
        TRY(1,N[i],H[i]);
        cout << endl;
    }
}

