# include <stdio.h>
int main(){
    int x, y, z;
    int* ptr;
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("\nThe three integers are:\n");
    ptr = &x;
    printf("x = %d\n", *ptr);
    /*Ho va ten : Nguyen Viet Anh
    MSSV : 20215307 */
    ptr = &y;
    printf("y = %d\n", *ptr);
    ptr = &z;
    printf("z = %d", *ptr);
    return 0;
}