#include <stdio.h>

int x[100], mark[100], n;

void print(){
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    printf("\n"); //sửa từ print("\n") thành printf("\n")
}
//Họ và tên: Nguyễn Việt Anh
//MSSV: 20215307
void process(int i) {
    if (i > n){
        print(); //sửa từ printf() thành print() để gọi hàm in mảng
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (!mark[j]){
            mark[j] = 1;
            x[i] = j;
            process(i+1);
            mark[j] = 0;
        }
}

int main() {
    n = 5;
    process(1);
    return 0;
}
