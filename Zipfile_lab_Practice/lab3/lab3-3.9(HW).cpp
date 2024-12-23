#include<bits/stdc++.h>
using namespace std;
int n, k1 ,k2;
int x[1000];
int L;

bool check(int a,int i){
    if(a == 1) return true;
    else{
        if(i == 0){
            if(x[a-1] == 0) return false;
            else if(L<k1) return false;
        }
        else{
            if(x[a-1] == 0){
                if(n-a+1 < k1) return false;
            }
            else{
                if(L+1>k2) return false;
            }
            return true;
        }
    }
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
void solution(){
    for(int i=1; i<=n; i++)
        cout << x[i];
    cout << endl;
}

void TRY(int a){
    for (int i = 0; i <= 1; i++){
        if(check(a,i)){
            x[a] = i;
            int preL = L;
            if(i == 1){
                if(x[a-1] == 1){
                    L += 1;
                }
                else L = 1;
            }
            else L = 0;

            if(a == n) solution();
            else TRY(a+1);

            L = preL;
        }
    }
    
}

int main(){
	cout << "Ho va ten:Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    cin >> n >> k1 >> k2;
    TRY(1);
}

