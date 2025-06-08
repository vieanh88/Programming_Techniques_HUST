#include <stdio.h>
using namespace std;
//Ham get_value
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int get_value(int x, int a=2, int b=1, int c=0){
    int S_07 = a*x*x + b*x + c;
    return S_07;
}

//Ham main
int main(){
    int x;
    scanf("%d", &x);
    int a = 2; //# giá tri mac dinh cua a
    int b = 1; //# giá tri mac dinh cua b
    int c = 0; //# giá tri mac dinh cua c
	//# Nhap 3 so nguyen a, b, b tu ban phim
    scanf("%d%d%d", &a,&b,&c);
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    return 0;
}
// Bài 2.3 - Nguyen Viet Anh - 5307
