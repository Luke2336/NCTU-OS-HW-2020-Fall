#include<bits/stdc++.h>
using namespace std;
int main() {
    int G[5][5] = {
        {0, 1 ,0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
    };
    bool visit[5] = {0};
    queue<int> q;
    q.push(0);
    visit[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 5; i++) {
            if (G[u][i] && !visit[i]) {
                q.push(i);
                visit[i] = true;
            }
        }
    }
    return 0;
}
