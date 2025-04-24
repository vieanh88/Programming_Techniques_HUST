#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
//Ho va ten : Nguyen Viet Anh
//MSSV : 20215307
    float z_07 = sqrt(x*x + y*y);
    return z_07;
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y);
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);
    return 0;
}
