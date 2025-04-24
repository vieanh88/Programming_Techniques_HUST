#include <stdio.h>
int *a;
int n, tmp;
int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    //#Allocate memory
    a = new int[n];
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    //#Sort array
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++){
            if(*(a+i) > *(a+j)){
                int tmp;
                tmp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tmp;
            }
        }
//Họ và tên: Nguyễn Việt Anh
//MSSV:20215307
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    delete [] a;
    return 0;
}