#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> in(n);
    vector<vector<int>> G(m);
    for (int i = 0; i < m; i++) {
        int a, b; // a points to b
        cin >> a >> b; // [0, n-1]
        G[a].push_back(b);
        in[b]++;
    }
    queue<int> q; // in-deg = 0 的點
    for (int i = 0; i < n; i++)
        if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int uu: G[u]) {
            in[uu]--;
            if(!in[uu]) q.push(uu);
        }
    }
    return 0;
}
