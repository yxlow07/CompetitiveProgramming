// Author: Yu Xuan
// Created On: 22 12 2024 - 23:14:24
// File: algorithms

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define nl '\n'

struct FenwickTree {
    int size; vector<int> tree;

    FenwickTree(int n) : size(n), tree(n + 2, 0) {}

    void update(int idx, int value = 1) {
        while (idx <= size) {
            tree[idx] += value;
            idx += idx & (-idx);
        }
    }

    int query(int idx) const {
        int res = 0;
        int i = idx;
        while (i > 0) {
            res += tree[i];
            i -= i & (-i);
        }
        return res;
    }

    int query_range(int idx) const {
        return query(size) - query(idx - 1);
    }
};

void solve() {}

signed main() {
    int tt = 1;
    #ifdef LOCAL
        auto start = chrono::high_resolution_clock::now();
        cerr<<"Test case "<<tt<<nl;
    #endif
        while (tt--) solve();
    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        cerr<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<"ms"<<nl;
    #endif
    return 0;
}