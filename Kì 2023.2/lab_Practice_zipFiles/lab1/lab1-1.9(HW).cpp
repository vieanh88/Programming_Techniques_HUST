#include<iostream>
using namespace std;

int main(){
    int m;
    cin >> m;
    int d[m];
    for (int a=0; a<m; a++)
    cin >> d[a];

    for (int a = 0; a<m; a++)
    for (int b = a; b<m; b++){
    for (int c = a; c<=b; c++)
    cout<<d[c]<<" ";
    cout<<"\n";
    }
    return 0;
}

