#include <bits/stdc++.h>
using namespace std;

void bfs(vector<list<int>> adj) {
    queue<int> Q; 
    vector<bool> visited(adj.size());
    Q.push(1);  // Bat dau tu dinh so 1

// Ho va ten: Nguyen Viet Anh
// MSSV: 20215307
    while (!Q.empty()) {
        int u_07 = Q.front();  // Lay dinh dau hang doi
        if (!visited[u_07]) {
            visited[u_07] = true;  // Danh dau dinh u_07 da duoc tham
            cout << u_07 << endl;
        }
        if (!adj[u_07].empty()) {
            int v = adj[u_07].front();  // Lay dinh ke dau tien cua u_07
            adj[u_07].pop_front();  // Xoa dinh ke do khoi danh sach cua u_07
            if (!visited[v]) {
                Q.push(v);  // Neu dinh v chua duoc tham thi dua vao hang doi
            }
        } else {
            Q.pop();  // Neu tat ca dinh ke cua u_07 da duoc tham thi loai bo u_07 khoi hang doi
        }
    }
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n"; 
    cout << "MSSV: 20215307\n";
    return 0;
}

