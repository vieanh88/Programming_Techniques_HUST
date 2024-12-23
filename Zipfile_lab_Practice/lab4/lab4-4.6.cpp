#include <bits/stdc++.h>
using namespace std;

void bfs(vector<list<int>> adj) {
    queue<int> Q; 
    vector<bool> visited(adj.size());
    Q.push(1);  // Bắt đầu từ đỉnh số 1
//Ho va ten:Nguyen Viet Anh
//MSSV: 20215307
    while (!Q.empty()) {
        int u = Q.front();  // Lấy đỉnh đầu hàng đợi
        if (!visited[u]) {
            visited[u] = true;  // Đánh dấu đỉnh u đã được thăm
            cout << u << endl;
        }
        if (!adj[u].empty()) {
            int v = adj[u].front();  // Lấy đỉnh kề đầu tiên của u
            adj[u].pop_front();  // Xóa đỉnh kề đầu tiên của u khỏi danh sách
            if (!visited[v]) {
                Q.push(v);  // Nếu đỉnh v chưa được thăm, thêm nó vào hàng đợi
            }
        } else {
            Q.pop();  // Nếu tất cả đỉnh kề của u đã được thăm, bỏ u khỏi hàng đợi
        }
    }
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n"; 
    cout << "MSSV: 20215307\n";
    // Chưa có mã cụ thể trong hàm main
    return 0;
}
