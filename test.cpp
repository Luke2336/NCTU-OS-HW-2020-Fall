for (int i = 0; i < n - 1; i++) {
    bool flag = false;
    for (int j = 0; j < n - i - 1; j++) {
        if (a[j] > a[j + 1]) {
            // Swap(a[j], a[j + 1]);
            int tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
            flag = true;
        }
    }
    if (!flag) break; // Sorted already
}
