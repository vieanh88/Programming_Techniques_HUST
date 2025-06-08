#include <bits/stdc++.h> 
using namespace std; 

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307

int main(){ 
    int n; 
    cin >> n; 
    int ans = 0, sum = 0; 
    while(n--){ 
        int k, t; 
        cin >> k >> t; 
        if(t==1){ 
        	while(k--){ 
            int a; 
            cin >> a; 
            sum += a; 
            ans = max(ans, -sum); 
        	} 
        }
        else if(t==-1){ 
        	while(k--){ 
            int a; 
            cin >> a; 
            sum -= a; 
            ans = max(ans, -sum); 
            }
        }
    }
    cout << ans;
}
