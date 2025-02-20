#include <stdio.h>

void allocate_mem(int ***mt, int m, int n){
    //Cấp bộ nhớ cho ma trận
    *mt = new int *[m];
    for(int i=0; i<m; i++){
        (*mt)[i] = new int[n];
    }
}
void input(int **mt, int m, int n){
    //Nhập phần tử ma trận
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            printf("mt[%d][%d] = ",i,j);
            scanf("%d",&mt[i][j]);
        }
}
void output(int **mt, int m, int n){
    //In các phần tử của ma trận
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            printf("%d ",mt[i][j]);
        printf("\n");
    }
}
int process(int **mt, int m, int n){
    int tong = 0;
    //Tính tổng các phần tử ma trận
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            if(mt[i][j]%2==0)
                tong += mt[i][j];
        }
    return tong;
}
//Họ và tên: Nguyễn Việt Anh
//MSSV:20215307
void free_mem(int **mt, int m, int n){
    //Giải phóng bộ nhớ
    for(int i=0; i<m; i++)
        delete []mt[i];
    delete []mt;
}
int main(){
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}