#include <stdio.h>

void print(int n) {
    printf("n=%d\n", n);
}

int mul3plus1(int n) {
    return n * 3 + 1;
}

int div2(int n) {
    return n / 2;
}

// khai báo các tham so cho các con tro hàm odd, even và output
void simulate(int n, int (*odd)(int), int (*even)(int), void (*output)(int))  {
    (*output)(n);
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main() {
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;
    odd = mul3plus1;
    even = div2;
    int n;
    scanf("%d", &n);
    simulate(n, odd, even, print);

    return 0;
}
// Bài 2.6 - Nguyen Viet Anh - 5307
