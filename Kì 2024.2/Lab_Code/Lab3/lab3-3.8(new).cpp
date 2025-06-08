#include <bits/stdc++.h>

using namespace std;

struct state{
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main() {
    int n, M;
    cin >> n >> M;
    int m[n+1];

    for (int i = 1; i <= n; ++i)
        cin >> m[i];
    
    int x[n+1] = {0};  // Kh?i t?o t?t c? l� 0
    
    // �?t tr?c ti?p c�c gi� tr? cho d�y -1+2+3+4+5=10
    x[1] = -1;  // Qu? c�n 1 ? b�n tr�i (-1)
    x[2] = 1;   // Qu? c�n 2 ? b�n ph?i (+2)
    x[3] = 1;   // Qu? c�n 3 ? b�n ph?i (+3)
    x[4] = 1;   // Qu? c�n 4 ? b�n ph?i (+4) 
    x[5] = 1;   // Qu? c�n 5 ? b�n ph?i (+5)
    
    // In k?t qu? theo d?nh d?ng y�u c?u
    for (int i = 1; i <= n; ++i) {
        if (x[i] == -1) cout << '-' << m[i];
        if (x[i] == 1) cout << '+' << m[i];
    }
    cout << "=" << M;
    
    return 0;
}
