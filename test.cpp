#include<bits/stdc++.h>
using namespace std;
struct heap {
    vector<int> h;
    heap() { h.resize(1);}
    int size() { return h.size() - 1;}
    int top() { return size() ? h[1] : -1;}
    void push(int);
    void pop();
  private:
    int leftId(int i) { return i << 1;}
    int rightId(int i) { return (i << 1) | 1;}
    int parId(int i) { return i >> 1;}
};
void heap::push(int key) {
    h.push_back(key);
    int id = size();
    while (id > 1) { // has parent
        int p = parId(id);
        if (h[p] > key) { // swap(h[p], h[id])
            h[id] = h[p];
            h[p] = key;
            id = p;
        } else break;
    }
}
void heap::pop() {
    h[1] = h.back();
    h.pop_back();
    int id = 1;
    while (1) {
        int lid = leftId(id), rid = rightId(id);
        if ((lid > size() || h[lid] > h[id]) &&
            (rid > size() || h[rid] > h[id])) {
            break;
        } else if (rid > size() || h[lid] < h[rid]){
            int tmp = h[lid];
            h[lid] = h[id];
            h[id] = tmp;
            id = lid;
        } else {
            int tmp = h[rid];
            h[rid] = h[id];
            h[id] = tmp;
            id = rid;
        }
    }
}
int main() {
    heap h;
    h.push(1);
    cout << h.top() << endl;
    h.push(2);
    cout << h.top() << endl;
    h.push(-1);
    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;
    return 0;
}
