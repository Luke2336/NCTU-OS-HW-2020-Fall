#include<bits/stdc++.h>
using namespace std;
#define maxn 8
int a[maxn] = {22, 8, 10, 21, 18, 17, 29, 1};
int tmp[maxn];
void MergeSort(int L, int R) {
    if(R - L <= 1) return;
    int mid = L + (R - L) / 2;
    MergeSort(L, mid);
    MergeSort(mid, R);
    int p1 = L, p2 = mid;
    for(int i = L; i < R; i++) {
        if (p1 >= mid)
            tmp[i] = a[p2++];
        else if (p2 >= R)
            tmp[i] = a[p1++];
        else if (a[p1] < a[p2])
            tmp[i] = a[p1++];
        else
            tmp[i] = a[p2++];
    }
    for(int i = L; i < R; i++)
        a[i] = tmp[i];
}
int main() {
    MergeSort(0, 8);
    for (int i = 0; i < 8; i++)
        cout << a[i] << " ";
    return 0;
}
