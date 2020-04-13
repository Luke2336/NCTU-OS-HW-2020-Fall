bool BinarySearch(int a[], int L, int R, int x) {
    if (L + 1 >= R) return false;
    int mid = L + (R - L) / 2;
    if (a[mid] == x) return true;
    if (a[mid] < x) return BinarySearch(a, L, mid, x);
    return BinarySearch(a, mid + 1, R, x);
}
int main() {
    int x = 7;
    int a[10] = {1, 7, 9, 10, 16, 17, 18, 20, 21, 25};
    if (BinarySearch(a, 0, 10, x)) printf("Find %d\n",x);
    else printf("Can't find %d\n",x);
    return 0;
}
