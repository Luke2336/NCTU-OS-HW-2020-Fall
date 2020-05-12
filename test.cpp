int G[5][5] = {
    {0, 1 ,0, 1, 1},
    {0, 1, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0}
};
bool visit[5] = {0};
void dfs(int u) {
    if (visit[u]) return;
    cout << u << " ";
    visit[u] = true;
    for (int i = 0; i < 5; i++) dfs(i);
}
int main() {
    dfs(0);
    return 0;
}
