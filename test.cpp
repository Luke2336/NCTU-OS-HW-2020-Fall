// a ^ x % m
int pow(int a, int x, int m) {
    int tmp = a % m;
    int ans = 1;
    while (x > 0) {
        if (x & 1)
            ans = ans * tmp % m;
        tmp = tmp * tmp % m;
        x >>= 1; // x /= 2;
    }
    return ans;
}
