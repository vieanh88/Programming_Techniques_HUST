#include<stdio.h>
using namespace std;
//Họ và tên: Nguyễn Việt Anh
//MSSV: 20215307
int counteven(int* arr, int size){
    int count = 0;
    for(int i=0; i<size; i++){
        if(arr[i]%2==0) count++;
    }
    return count;
}
