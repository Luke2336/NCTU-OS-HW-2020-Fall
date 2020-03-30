#include<bits/stdc++.h>
using namespace std;
void BubbleSort (vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap(a[j], a[j + 1]);
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
int main() {
    vector<int> a = {6, 7, 4, 2, 1};
    BubbleSort(a);
    for (int x : a)
        cout << x << " ";
    return 0;
}
