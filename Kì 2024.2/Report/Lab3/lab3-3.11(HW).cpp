#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
int n, r;
int price[MAX][MAX];
int x[MAX];
bool visited[MAX];
vector<int> vt;
int best_07;
int sum_price;
int start, des, numOfPoint;

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
void input() { //nhap ma tran
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> price[i][j];
        }
    }
}

bool check(int a, int i) {
    if (visited[vt[i]]) return false; //neu visited thi tra ve false
    if (price[x[a - 1]][vt[i]] == 0) return false; //neu price = 0 tra ve false
    return true;
}

void solution() {
    if (price[x[numOfPoint - 2]][des] == 0) return;
    best_07 = min(best_07, sum_price + price[x[numOfPoint - 2]][des]);
}

void TRY(int k) {
    for (int i = 1; i < numOfPoint - 1; i++) {
        if (check(k, i)) { //kiem tra kha nang
            visited[vt[i]] = true; //set visited
            sum_price += price[x[k - 1]][vt[i]]; //cap nhat price

            x[k] = vt[i];
            if (k == numOfPoint - 2) 
                solution();
            else 
                TRY(k + 1); //chuyen sang des ke tiep

            visited[vt[i]] = false; //tra lai gia tri cu
            sum_price -= price[x[k - 1]][vt[i]];
        }
    }
}

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main() {
	
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    
    input();
    cin.ignore(); // Ð? b? qua ký t? newline còn l?i sau khi nh?p n và r

    while (r > 0) {
        best_07 = INT_MAX;
        sum_price = 0;
        string str;
        getline(cin, str);

        stringstream ss(str);
        int tmp;
        while (ss >> tmp) {
            vt.push_back(tmp - 1);
        }

        // Khoi tao cac du lieu can thiet truoc khi quay lui
        start = vt[0]; // Diem bat dau
        des = vt[vt.size() - 1]; // Diem dich
        numOfPoint = vt.size(); // So diem phai di qua
        x[0] = start;
        x[numOfPoint - 1] = des;
        for (int i = 0; i < n; i++)
            visited[i] = false;

        TRY(1);

        // In ket qua
        if (best_07 == INT_MAX)
            cout << "0" << endl;
        else
            cout << best_07 << endl;

        // Xoa vector va chuyen sang khach tiep theo
        vt.clear();
        r--;
    }

    return 0;
}
