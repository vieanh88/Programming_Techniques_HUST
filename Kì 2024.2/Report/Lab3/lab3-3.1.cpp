#include<stdio.h>
#include<iostream>
using namespace std;

int lucas(int n) {
    if(n == 0) return 2;
    if(n == 1) return 1;
    return lucas(n-1) + lucas(n-2);
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main(){
	int n_07;
	scanf ("%d", &n_07);
	printf ("Ho va ten: Nguyen Viet Anh\n");
	printf ("MSSV:20215307\n");
    printf ("%d", lucas(n_07));
}
