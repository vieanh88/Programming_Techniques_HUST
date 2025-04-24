#include<stdio.h>
using namespace std;
double* maximum(double* a, int size){
    double *max;
    max = a;
    //Họ và tên: Nguyễn Việt Anh
    //MSSV:20215307
    if (a==NULL) return NULL;
    for(int i=1; i<size; i++){
        if(a[i] > *max) max = &a[i];
    }
   return max;
}
