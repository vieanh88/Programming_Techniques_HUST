#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# Luu vi tri c�c buoc di chuyen cua qu�n ma
int mark[100][100]; //# ��nh dau vi tri c�c � m� qu�n m� d� di chuyen qua

//# Mang hx, hy m� ta 8 vi tri qu�n m� c� the di chuyen tu vi tri hien tai
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra day c�c buoc di chuyen tim dc
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}
bool ifpossible(int x, int y){
    if(x < 1 || x > n) return false;
    if(y < 1 || y > n) return false;
    if(mark[x][y] == 1) return false;
    return true;
}
//# Thuat to�n quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        if(ifpossible(xx,yy)){
            mark[xx][yy] = 1;
            X[k] = xx;
            Y[k] = yy;
            if(k == n*n){
                print_sol();
            }
            TRY(k+1);
            mark[xx][yy] = 0;
        }
    }
}
//Ho va ten: Nguyen Viet Anh
//MSSV: Nguyen Viet Anh
int main(){
    printf ("Ho va ten: Nguyen Viet Anh\n");
    printf ("MSSV 20215307\n");
	cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
