#include<stdio.h>
using namespace std;
//Họ và tên: Nguyễn Việt Anh
//MSSV:20215307
void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    while(l<r){
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
}
void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    //Họ và tên: Nguyễn Việt Anh
    //MSSV:20215307
    while(l<r){
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
}