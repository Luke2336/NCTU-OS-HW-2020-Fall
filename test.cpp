int main() {
    int G[5][5] = {
        {0, 1 ,0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0}
    };
    bool visit[5] = {0};
    stack<int> st;
    st.push(0), visit[0] = true;
    while (!st.empty()) {
        int u = st.pop();
        for (int i = 0; i < 5; i++)
            if (G[u][i] && !visit[i])
                st.push(i), visit[i] = true;
    }
    return 0;
}
