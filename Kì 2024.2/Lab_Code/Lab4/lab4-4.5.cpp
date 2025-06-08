#include <bits/stdc++.h>
using namespace std;

void dfs(vector<list<int>> adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1);

    // Ho va ten: Nguyen Viet Anh
    // MSSV: 20215307
    while (!S.empty()) {
        int u_07 = S.top();  // Lay dinh dau ngan xep
        if (!visited[u_07]) {
            visited[u_07] = true;  // Danh dau dinh u_07 da duoc tham
            cout << u_07 << endl;  // In ra dinh u_07
        }
        if (!adj[u_07].empty()) {
            int v = adj[u_07].front();  // Lay dinh ke dau tien cua u_07
            adj[u_07].pop_front();  // Xoa dinh ke dau tien khoi danh sach ke cua u_07
            if (!visited[v]) {
                S.push(v);  // Neu dinh v chua duoc tham thi dua vao ngan xep
            }
        } else {
            S.pop();  // Neu tat ca cac dinh ke cua u_07 da duoc tham thi loai bo u_07 khoi ngan xep
        }
    }
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV:20215307\n";
    return 0;
}
