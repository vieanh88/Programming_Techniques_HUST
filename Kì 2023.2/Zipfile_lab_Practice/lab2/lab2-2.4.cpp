#include <stdio.h>
int cube(int x) {
//# tra ve lap phuong cua x
    return x*x*x;
}
//# viet ham tinh lap phuong cua 1 so kieu double
double cube(double x){
    return x*x*x;
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main() {
    printf("Ho Va Ten: Nguyen Viet Anh\n");
    printf("MSSV: 20215307\n");
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    return 0;
}

