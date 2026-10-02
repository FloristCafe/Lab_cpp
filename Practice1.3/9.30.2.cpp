#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v;
    Node* nxt;
    Node(int _v) : v(_v), nxt(nullptr) {}
};

struct Iter {
    Node* p;
    Iter(Node* _p) : p(_p) {}
    bool operator!=(const Iter& o) const { return p != o.p; }
    void operator++() { p = p->nxt; }
    int operator*() const { return p->v; }
};

struct List {
    Node* head;
    int sz;
    
    List() : head(nullptr), sz(0) {}
    
    Iter begin() { return Iter(head); }
    Iter end() { return Iter(nullptr); }

    void insert(int idx, int v) {
        Node* nd = new Node(v);
        if (idx == 0) { nd->nxt = head; head = nd; }
        else {
            Node* p = head;
            for (int i = 0; i < idx - 1; ++i) p = p->nxt;
            nd->nxt = p->nxt; p->nxt = nd;
        }
        sz++;
    }

    int xor_sum() {
        int sum = 0, idx = 0;
        for (Iter it = begin(); it != end(); ++it) {
            sum += (idx ^ (*it));
            idx++;
        }
        return sum;
    }
};

// 合并两个有序链表
List merge(List& a, List& b) {
    List res;
    Node dummy(0), *tail = &dummy;
    Node *p1 = a.head, *p2 = b.head;
    
    while (p1 && p2) {
        if (p1->v <= p2->v) { tail->nxt = new Node(p1->v); p1 = p1->nxt; }
        else { tail->nxt = new Node(p2->v); p2 = p2->nxt; }
        tail = tail->nxt;
        res.sz++;
    }
    while (p1) { tail->nxt = new Node(p1->v); p1 = p1->nxt; tail = tail->nxt; res.sz++; }
    while (p2) { tail->nxt = new Node(p2->v); p2 = p2->nxt; tail = tail->nxt; res.sz++; }
    
    res.head = dummy.nxt;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    List la, lb;
    for (int x : a) la.insert(la.sz, x);
    for (int x : b) lb.insert(lb.sz, x);
    
    List lc = merge(la, lb);
    
    cout << la.xor_sum() << "\n";
    cout << lb.xor_sum() << "\n";
    cout << lc.xor_sum() << "\n";
    
    return 0;
}