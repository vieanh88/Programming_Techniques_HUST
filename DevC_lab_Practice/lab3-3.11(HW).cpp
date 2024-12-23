#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int n, r;
int price[MAX][MAX];
int x[MAX];
bool visited[MAX];
vector<int> vt;
int best;
int sum_price;
int start, des, numOfPoint;

void input(){//nhap ma tran
    cin >> n >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> price[i][j];
        }
    }
}

bool check(int a, int i){
    if(visited[vt[i]]) return false; //neu visited thi tra ve false
    if(price[x[a-1]][vt[i]] == 0) return false;//neu price = 0 tra ve false
    return true;
}

void solution(){
    if(price[x[numOfPoint-2]][des] == 0) return;
    best = min(best, sum_price + price[x[numOfPoint-2]][des]);
}

void TRY(int k){
    for(int i=1; i<numOfPoint-1; i++){
        if(check(k, i)){//kiem tra kha nang
            visited[vt[i]] = true;//set vistied
            sum_price += price[x[k-1]][vt[i]];//cap nhat price

            x[k] = vt[i];
            if(k == numOfPoint-2) 
                solution();
            else 
                TRY(k+1);//chuyen sang des ke tiep

            visited[vt[i]] = false;//tra lai gia tri cu

            sum_price -= price[x[k-1]][vt[i]];
        }
    }
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
int main(){
	
	cout << "Ho va ten:Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    
    string str;
    input(); 
    getline(cin,str);

    while(r > 0){
        best = INT_MAX;
        sum_price = 0;
        //Su dung string nhap su lieu
        getline(cin, str);
        //Tach string thanh cac so va ghi vao vector
        while (!str.empty()){
            stringstream convert(str.substr(0, str.find(" ")));
            int tmp = 0;
            convert >> tmp;
            vt.push_back(tmp - 1);

            if (str.find(" ") > str.size()){
                break;
            } else {
                str.erase(0, str.find(" ") + 1); //Update string
            }
        }

        // Khoi tao cac du lieu can thiet truoc khi quay lui
        start = vt[0]; // Diem bat dau
        des = vt[vt.size()-1]; //Diem dich
        numOfPoint = vt.size(); //So diem phai di qua
        x[0] = start; x[numOfPoint-1] = des;
        for(int i=0; i<n; i++)
            visited[i] = false;

        TRY(1);

        // In ket qua
        if(best == INT_MAX) 
            cout << "0" << endl;
        else cout << best << endl;
        // Xoa vector va chuyen sang khach tiep theo
        vt.erase(vt.begin(), vt.end());
        r--;
    }
}
