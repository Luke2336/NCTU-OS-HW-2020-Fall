void CountingSort(vector<int> &a) {
    // 假設序列中的數字範圍為0-99
    int cnt[100] = {0};
    for (int i = 0; i < a.size(); i++)
        cnt[a[i]]++;
    a.clear();
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < cnt[i]; j++)
            a.push_back(i);
}
