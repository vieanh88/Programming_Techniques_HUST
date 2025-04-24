#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, k;
int m;
vector<vector<int> > vt; // chuyen tu luu tru cac canh sang luu tru danh sach ke
int x[MAX];//luu tru dinh da di qua
bool visited[MAX];//danh dau dinh da di qua
int cnt;//dem so

void input(){
    cin >> n >> k;
    cin >> m;
    vt.resize(n+1);
    for(int i = 0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vt[tmp1-1].push_back(tmp2-1); // dinh tmp2 ke voi dinh tmp1


        vt[tmp2-1].push_back(tmp1-1); // dinh tmp1 ke voi dinh tmp2
    }

    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    cnt = 0;
}

bool check(int a, int i){//check if possible
    if(a == 0) return true;//khong co dinh
    if(visited[i]) return false;// da di qua -> false

    int index = 0;
    for(int j = 0; j<vt[x[a-1]].size(); j++){
        if(i == vt[x[a-1]][j]) index++;
    }
    if(index == 0) return false;// khong co canh
    return true;
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
void solution(){
    cnt++;
}

void TRY(int a){
    for(int i=0; i<n; i++){
        if(check(a, i)){
            visited[i] = true;
            x[a] = i;

            if(a == k) solution();
            else TRY(a+1);

            visited[i] = false;
        }
    }
}

int main(){
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    
    input();
    TRY(0);
    cout << cnt / 2;
}

