#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){
	//#Khu de quy
    if(a == 0||b == 0){
        return a + b;
    }
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
    while(a != b){
        if(a>b){
            a -=b;
        }
        else{
            b-=a;
        }
    }
    return a;
}

int main() {
	printf("Ho va ten: Nguyen Viet Anh\n");
	printf("MSSV:20215307\n");
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
