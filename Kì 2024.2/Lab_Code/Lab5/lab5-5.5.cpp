#include <bits/stdc++.h> 

using namespace std; 

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307

int main(){ 
    int n; 
    cin >> n; 
    bool found = false; 

    while(n--){ 
        int a; 
        cin >> a; 
        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0)){ 
        	found = true; 
        	cout << "Yes"; 
return 0;  
} 
            found = true; 
    } 
    cout << "No"; 
} 
