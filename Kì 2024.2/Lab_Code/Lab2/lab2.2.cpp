#include <stdio.h>
using namespace std;
void rotate(int &x, int &y, int &z) {
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
    int tmp_07 = x;
    x = y;
    y = z;
    z = tmp_07;
}

int main() {
    int x, y, z;
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
    scanf("%d%d%d",&x,&y,&z);
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);
    return 0;
}
// Bài 2.2 - Nguyen Viet Anh - 5307
