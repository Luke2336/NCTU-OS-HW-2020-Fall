void SelectionSort (vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int p = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[p]) p = j;
        }
        Swap(a[i], a[p]);
    }
}
