#include <iostream>
#include <queue>
#include <climits>
using namespace std;

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307
vector<int> dijkstra(const vector<vector<pair<int, int>>>& adj) {
    // Hàm tính đường đi ngắn nhất từ đỉnh 0 đến các đỉnh khác trong đồ thị bằng thuật toán Dijkstra
    priority_queue<pair<int, int>> S;  // Khởi tạo hàng đợi ưu tiên để lưu các đỉnh cần duyệt
    vector<int> d(adj.size(), INT_MAX);  // Khởi tạo vector khoảng cách, ban đầu đặt tất cả khoảng cách là vô cùng
    d[0] = 0;  // Khoảng cách từ đỉnh 0 đến chính nó là 0
    S.push({0, 0});  // Đẩy đỉnh 0 vào hàng đợi với khoảng cách 0

    while (!S.empty()) {
        int du = -S.top().first;  // Lấy khoảng cách âm để chuyển thành khoảng cách dương
        int u = S.top().second;  // Lấy đỉnh đầu hàng đợi
        S.pop();  // Loại bỏ đỉnh đầu hàng đợi

        if (du != d[u]) continue;  // Bỏ qua nếu khoảng cách hiện tại không còn tối ưu

        for (auto e : adj[u]) {  // Duyệt tất cả các đỉnh kề của u
            int v = e.first;  // Đỉnh kề
            int c = e.second;  // Trọng số cạnh
            if (d[v] > d[u] + c) {  // Nếu tìm được đường đi ngắn hơn
                d[v] = d[u] + c;  // Cập nhật khoảng cách
                S.push({-d[v], v});  // Đẩy đỉnh v vào hàng đợi với khoảng cách mới
            }
        }
    }
    return d;  // Trả về vector khoảng cách từ đỉnh 0 đến các đỉnh khác
}

int main() {
    printf("Ho Va Ten: Nguyen Viet Anh\n");
    printf("MSSV: 20215307\n");
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}