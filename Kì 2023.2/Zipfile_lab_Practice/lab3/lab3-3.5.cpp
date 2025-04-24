#include <iostream>
using namespace std;
int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}
int bio[1000][1000] = {0};
int binom2(int n, int k){
	
	//#khu de quy
    if (k > n){
        return bio[n][k];
    } 
    if (k == 0){
        return bio[n][k];
    }
    bio[n][k] = bio[n-1][k] + bio[n-1][k-1];
    return bio[n][k];
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main() {
	printf("Ho va ten: Nguyen Viet Anh\n");
	printf("MSSV:20215307\n");
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for(int i = 1; i <= m; i++){
        bio[i][0] = 1;
        bio[0][i] = 1;
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
