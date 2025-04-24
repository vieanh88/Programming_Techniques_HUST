#include <stdio.h>
using namespace std;
void rotate(int &x, int &y, int &z) {
    int tmp = x;
    x = y;
    y = z;
    z = tmp;
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main() {
	printf("Ho va ten: Nguyen Viet Anh\n");
	printf("MSSV:20215307\n");
    int x, y, z;
    scanf("%d%d%d",&x,&y,&z);
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);
    return 0;
}

