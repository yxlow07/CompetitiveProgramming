// Author: Yu Xuan
// Created On: 22 12 2024 - 22:33:58
// File: E
// Link: 

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define nl '\n'

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

template <class T> void _print(const T t) { cerr << t; }
template <class T, class V> void _print(const pair <T, V> p);
template <class T> void _print(const vector <T> v);
template <class T> void _print(const set <T> v);
template <class T, class V> void _print(const map <T, V> v);
template <class T> void _print(const multiset <T> v);
template <class T, class V> void _print(const pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(const vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(const set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(const multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(const map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void fast(const string &file = "") {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout<<fixed<<setprecision(12); 
    if (!file.empty()) { (void) !freopen((file + ".in").c_str(), "r", stdin); (void) !freopen((file + ".out").c_str(), "w", stdout); }
    #ifdef LOCAL
        #include <filesystem>
        string current_path = filesystem::current_path().string();
        freopen((current_path+"/inp.txt").c_str(), "r", stdin);
        freopen((current_path+"/out.txt").c_str(), "w", stdout);
        freopen((current_path+"/err.txt").c_str(), "w", stderr);
    #endif
}

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

void tle() {
    int n,k; cin>>n>>k; vector<int> a(n), b(n);
    ff(i, 0, n-1) cin>>a[i];
    ff(i, 0, n-1) cin>>b[i];

    vector<int> p = a;
    p.insert(p.end(), b.begin(), b.end()); sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    vector<pair<int,int>> customers(n);
    ff(i, 0, n-1) customers[i] = {a[i], b[i]};
    sort(customers.begin(), customers.end(), [&](const pair<int, int> &x, const pair<int, int> &y) -> bool{
        if(x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    });
    multiset<int> included; int mx = 0, l = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    loop(c, p) {
        while (l < n && customers[l].first < c) {
            included.insert(customers[l].second);
            l++;
        }
        int buy = b.end() - lower_bound(b.begin(), b.end(), c);
        int neg = distance(included.lower_bound(c), included.end());

        if (neg <= k) {
            int earn = c * buy;
            if (earn > mx) mx = earn;
        }
    }
    cout<<mx<<nl;
}

void solve() {
    int n,k; cin>>n>>k; vector<int> a(n), b(n);
    ff(i, 0, n-1) cin>>a[i];
    ff(i, 0, n-1) cin>>b[i];

    vector<int> p = a;
    p.insert(p.end(), b.begin(), b.end()); sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    vector<pair<int,int>> customers(n);
    ff(i, 0, n-1) customers[i] = {a[i], b[i]};
    sort(customers.begin(), customers.end(), [&](const pair<int, int> &x, const pair<int, int> &y) -> bool {
        if(x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    });

    // find unique elements
    sort(b.begin(), b.end());
    vector<int> uq = b; uq.erase(unique(uq.begin(), uq.end()), uq.end());

    FenwickTree ft(uq.size()); int mx = 0, l = 0;
    loop(c, p) {
        while (l < n && customers[l].first < c) {
            int curr = customers[l].second, rank = lower_bound(uq.begin(), uq.end(), curr) - uq.begin() + 1;
            ft.update(rank);
            l++;
        }
        // find neg reviews
        int pos = lower_bound(uq.begin(), uq.end(), c) - uq.begin() + 1, neg = 0;
        if (pos <= uq.size()) neg = ft.query_range(pos);
        if (neg <= k) {
            int buy = n - (lower_bound(b.begin(), b.end(), c)-b.begin());
            int earn = c * buy;
            if (earn > mx) mx = earn;
        }
    }
    cout<<mx<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}