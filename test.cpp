#include<bits/stdc++.h>
using namespace std;
#define maxn 500
#define INF 2000000000
int main() {
  int n;
  cin >> n;
  int r[maxn], c[maxn];
  for (int i = 0; i < n; ++i)
    cin >> r[i] >> c[i];
  int dp[maxn][maxn];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = (i == j) ? 0 : INF;
  for (int i = 1; i < n; i++)
    for (int l = 0; r = i; r < n; l++, r++)
      for (int p = l; p < r; p++)
        dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][r]);
  cout << dp[0][n - 1] << endl;
  return 0;
}
