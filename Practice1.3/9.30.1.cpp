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
        if (idx == 0) {
            nd->nxt = head;
            head = nd;
        } else {
            Node* p = head;
            for (int i = 0; i < idx - 1; ++i) p = p->nxt;
            nd->nxt = p->nxt;
            p->nxt = nd;
        }
        sz++;
    }

    int remove(int v) {
        if (!head) return -1;
        if (head->v == v) {
            Node* t = head;
            head = head->nxt;
            sz--;
            return 1;
        }
        Node* p = head;
        while (p->nxt && p->nxt->v != v) p = p->nxt;
        if (p->nxt) {
            Node* t = p->nxt;
            p->nxt = t->nxt;
            sz--;
            return 1;
        }
        return -1;
    }

    void reverse() {
        Node *prev = nullptr, *cur = head, *nxt = nullptr;
        while (cur) {
            nxt = cur->nxt;
            cur->nxt = prev;
            prev = cur;
            cur = nxt;
        }
        head = prev;
    }

    int search(int v) {
        Node* p = head;
        int idx = 0;
        while (p) {
            if (p->v == v) return idx;
            p = p->nxt;
            idx++;
        }
        return -1;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    List lst;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        lst.insert(lst.sz, x);
    }
    
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int idx, val;
            cin >> idx >> val;
            lst.insert(idx, val);
        } else if (op == 2) {
            int val;
            cin >> val;
            if (lst.remove(val) == -1) cout << "-1\n";
        } else if (op == 3) {
            lst.reverse();
        } else if (op == 4) {
            int val;
            cin >> val;
            cout << lst.search(val) << "\n";
        } else if (op == 5) {
            cout << lst.xor_sum() << "\n";
        }
    }
    return 0;
}