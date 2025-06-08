#include <iostream>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& adj) {
    // Ham tinh duong di ngan nhat tu dinh 0 den cac dinh khac trong do thi bang thuat toan Dijkstra
    priority_queue<pair<int, int>> S;  // Khoi tao hang doi uu tien de luu cac dinh can duyet
    vector<int> d(adj.size(), INT_MAX);  // Khoi tao vector khoang cach, ban dau dat tat ca la vo cung
    d[0] = 0;  // Khoang cach tu dinh 0 den chinh no la 0
    S.push({0, 0});  // Day dinh 0 vao hang doi voi khoang cach 0

    while (!S.empty()) {
        int du = -S.top().first;  // Lay khoang cach am de chuyen thanh duong (do uu tien nho nhat)
        int u = S.top().second;  // Lay dinh o dau hang doi
        S.pop();  // Loai bo dinh o dau hang doi

        if (du != d[u]) continue;  // Bo qua neu khoang cach hien tai khong con toi uu

        for (auto e : adj[u]) {  // Duyet tat ca cac dinh ke cua u
            int v = e.first;  // Dinh ke
            int c = e.second;  // Trong so canh
            if (d[v] > d[u] + c) {  // Neu tim duoc duong di ngan hon
                d[v] = d[u] + c;  // Cap nhat khoang cach
                S.push({-d[v], v});  // Day dinh v vao hang doi voi khoang cach moi
            }
        }
    }
    return d;  // Tra ve vector khoang cach tu dinh 0 den cac dinh khac
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307

int main() {
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
