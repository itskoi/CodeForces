#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> pii;

struct Node {
    long long data, lazy;
    int idx;
    Node* left;
    Node* right;
    Node() {
        left = right = nullptr;
        data = 1e9;
        lazy = idx = 0;
    }
    bool operator < (const Node* b) {
        if (this == nullptr) return false;
        if (b == nullptr) return true;
        if (this->data < b->data) return true;
        if (this->data == b->data && this->idx < b->idx) return true;
        return false;
    }
};

class IT {
private:
    Node* root = nullptr;
    vector<long long> _Time;
    vector<long long> _Result;
    int n;
    long long p;
public:
    IT();
    ~IT();
    void build(Node*, int, int);
    void updateIdx(Node*, int, int, int, long long);
    void updateLazy(Node*, int, int, int, int, long long);
    void setLazy(Node*, int, int);
    void process();
    Node* getMin(Node*, int, int, int, int);
};

int main() {
    IT* it = new IT();
    it->process();
    delete it;
    return 0;
}

// Definitions
IT::IT() {
    root = new Node();
    cin >> n >> p;
    _Time.assign(n + 1, 0);
    _Result.assign(n + 1, 0);
    for (int i = 0 ; i < n; i++) {
        cin >> _Time[i + 1];
    }
    // Build IT 
    build(this->root, 1, n);
}

IT::~IT() {
    delete root;
}

void IT::build(Node* root, int start, int end) {
    if (start > end) return;
    if (start == end) {
        root->data = _Time[start];
        root->idx = start;
        return;
    }
    int mid = (start + end) >> 1;
    if (root->left == nullptr) root->left = new Node();
    if (root->right == nullptr) root->right = new Node();
    build(root->left, start, mid);
    build(root->right, mid + 1, end);
    if (root->left < root->right) {
        root->data = root->left->data;
        root->idx = root->left->idx;
    } else {
        root->data = root->right->data;
        root->idx = root->right->idx;
    }
}

void IT::updateIdx(Node* root, int start, int end, int idx, long long val = 1e9) {
    if (start > end) return;
    setLazy(root, start, end);
    if (start == end) {
        _Time[start] = val;
        root->data = val;
        return;
    }
    int mid = (start + end) >> 1;
    if (idx <= mid) updateIdx(root->left, start, mid, idx);
    else updateIdx(root->right, mid + 1, end, idx);
    if (root->left < root->right) {
        root->data = root->left->data;
        root->idx = root->left->idx;
    } else {
        root->data = root->right->data;
        root->idx = root->right->idx;
    }
}

void IT::setLazy(Node* root, int start, int end) {
    if (root->lazy == 0) return;
    int val = root->lazy;
    root->data = val;
    if (start != end) {
        if (root->left->data < val) root->left->lazy = val;
        if (root->right->data < val) root->right->lazy = val;
    }
    root->lazy = 0;
}

void IT::updateLazy(Node* root, int start, int end, int left, int right, long long key) {
    setLazy(root, start, end);
    if (start > end || start > right || end < left) return;
    if (start >= left && end <= right && root->data < key) {
        root->data = key;
        if (start != end) {
            if (root->left->data < key) root->left->lazy = key;
            if (root->right->data < key) root->right->lazy = key;
        }
        return;
    }
    int mid = (start + end) >> 1;
    updateLazy(root->left, start, mid, left, right, key);
    updateLazy(root->right, mid + 1, end, left, right, key);
    if (root->left < root->right) {
        root->data = root->left->data;
        root->idx = root->left->idx;
    } else {
        root->data = root->right->data;
        root->idx = root->right->idx;
    }
}   

Node* IT::getMin(Node* root, int start, int end, int left, int right) {
    setLazy(root, start, end);
    if (start > end || start > right || end < left) return nullptr;
    if (start >= left && end <= right) {
        return root;
    }
    int mid = (start + end) >> 1;
    Node* l = getMin(root->left, start, mid, left, right);
    Node* r = getMin(root->right, mid + 1, end, left, right);
    if (l < r) return l;
    return r;
}

void IT::process() {
    for (int i = 1; i <= n; i++) {
        Node* ptr = getMin(this->root, 1, n, 1, n);
        _Result[ptr->idx] = ptr->data + this->p;
        cout << _Result[ptr->idx] << endl;
        this->updateIdx(this->root, 1, n, ptr->idx);
        this->updateLazy(this->root, 1, n, 1, n, _Result[ptr->idx]);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << _Result[i] << " ";
    // }
}