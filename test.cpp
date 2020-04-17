#include<bits/stdc++.h>
using namespace std;
#define maxn 100
int QuickSelect(int *A, int n, int k) {
  if (n == 1) return A[0];
  int p = A[rand() % n]; // random pivot
  int sz_L = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] <= p) { //swap A[i] to the back of L
      int tmp = A[i];
      A[i] = A[sz_L];
      A[sz_L] = tmp;
      sz_L++;
    }
  }
  if (sz_L >= k)
    return QuickSelect(A, sz_L, k);
  else
    return QuickSelect(A + sz_L, n - sz_L, k - sz_L);
}
int main() {
  srand(time(0)); // initialize random seed
  int n, k;
  int A[maxn];
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> A[i];
  cout << QuickSelect(A, n, k) << "\n";
  return 0;
}
