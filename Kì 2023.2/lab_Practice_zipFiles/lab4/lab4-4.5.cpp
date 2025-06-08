#include <bits/stdc++.h>
using namespace std;

void dfs(vector<list<int>> adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1);  // Bắt đầu từ đỉnh số 1
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
    while (!S.empty()) {
        int u = S.top();  // Lấy đỉnh đầu ngăn xếp
        if (!visited[u]) {
            visited[u] = true;  // Đánh dấu đỉnh u đã được thăm
            cout << u << endl;  // In đỉnh u
        }
        if (!adj[u].empty()) {
            int v = adj[u].front();  // Lấy đỉnh kề đầu tiên của u
            adj[u].pop_front();  // Xóa đỉnh kề đầu tiên của u khỏi danh sách
            if (!visited[v]) {
                S.push(v);  // Nếu đỉnh v chưa được thăm, thêm nó vào ngăn xếp
            }
        } else {
            S.pop();  // Nếu tất cả các đỉnh kề của u đã được thăm, loại bỏ u khỏi ngăn xếp
        }
    }
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV:20215307\n";
    // Chưa có mã cụ thể trong hàm main
    return 0;
}
