#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left = NULL;
    Node *right = NULL;
    Node () {}
    Node (int _val) { val = _val;}
};
struct BST {
    Node *root = NULL;
    bool find(int key) {
        Node *tmp = root;
        while (tmp && tmp->val != key) {
            if (tmp->val > key) tmp = tmp->left;
            else tmp = tmp->right;
        }
        return tmp != NULL;
    }
    void add(int key) {
        if (find(key)) return; //key已經在樹裡
        Node *new_node = new Node(key);
        Node *par, *tmp = root;
        if (!root) { //樹是空的
            root = new_node;
            return;
        }
        while (tmp) { //當tmp為NULL時，代表找到空位插入new_node
            par = tmp; //紀錄tmp當前的par
            if (tmp->val > key) tmp = tmp->left;
            else tmp = tmp->right;
        }
        //檢查要放par的左/右
        if (par->val > key) par->left = new_node;
        else par->right = new_node;
    }
};
int main() {
    BST bst;
    bst.add(1);
    cout << (bst.find(1) ? "Find\n" : "Not find\n");
    cout << (bst.find(2) ? "Find\n" : "Not find\n");
    bst.add(3);
    bst.add(2);
    cout << (bst.find(2) ? "Find\n" : "Not find\n");
    cout << (bst.find(3) ? "Find\n" : "Not find\n");
    return 0;
}
