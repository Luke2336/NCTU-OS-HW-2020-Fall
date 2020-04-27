#define SIZE 10000
int st[SIZE];
int sz = 0;
bool empty() {
    return sz <= 0;
}
void push(int x) {
    st[sz] = x;
    sz++;
}
void pop() {
    if (!empty()) sz--;
}
int top() {
    if (!empty()) return st[sz - 1];
    return -1;
}
