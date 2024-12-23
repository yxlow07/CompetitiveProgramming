// Author: Yu Xuan
// Created On: 14 12 2024 - 15:08:51
// File: SilverB
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

class bit {
public:
    explicit bit(int sz) : N(sz), tree(sz+2, 0) {}

    void update(int idx, int val = 1) {
        while (idx <= N) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int query_range(int l, int r) {
        return query(r) - query(l-1);
    }

private:
    int N;
    vector<int> tree;
};

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

void solve() {
    int n, k, a, b, c; cin>>n>>k; vector<int> trees(n); loop(x, trees) cin>>x;
    vector<tuple<int,int,int>> restrictions(k);
    ff(i, 0, k-1) {
        cin>>a>>b>>c;
        restrictions[i] = make_tuple(b, a, c);
    }
    sort(trees.begin(), trees.end()); sort(restrictions.begin(), restrictions.end());
    bit bt(n); vector<int> parent(n+2);
    ff(i, 0, n+1) {
        parent[i] = i;
    }

    auto find = [&](int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };

    int keep = 0;
    for (const auto& [ri, li, ti] : restrictions) {
        int l = lower_bound(trees.begin(), trees.end(), li) - trees.begin() + 1;
        int r = upper_bound(trees.begin(), trees.end(), ri) - trees.begin();
        if (l > r) continue;
        int ct = bt.query_range(l, r);
        if (ct >= ti) {
            continue;
        }
        int need = ti - ct;
        ff(i, 0, need-1) {
            int idx = find(r);
            if (idx < l) break;
            bt.update(idx, 1);
            parent[idx] = idx-1;
            keep++;
        }
    }
    cout<<n-keep<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}