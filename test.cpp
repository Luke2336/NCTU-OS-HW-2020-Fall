void Swap (int &a, int &b) {
    int tmp = a; a = b; b = tmp;
}
void SelectionSort (vector<int> &a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > a[j + 1]) Swap(a[j], a[j + 1]);
            else break;
        }
    }
}
