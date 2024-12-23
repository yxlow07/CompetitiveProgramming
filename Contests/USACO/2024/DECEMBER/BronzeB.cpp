// Author: Yu Xuan
// Created On: 14 12 2024 - 13:53:52
// File: BronzeB
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

void solve() {
    int n, q, xo, yo, zo; cin>>n>>q; vector<vector<int>> queries(q, vector<int>(3, 0));
    ff(i, 0, q-1) cin>>queries[i][0]>>queries[i][1]>>queries[i][2];
    vector<int> x(n*n, 0), y(n*n, 0), z(n*n, 0);
    int ans = 0;
    ff(i, 0, q-1) {
        xo = queries[i][0]; yo = queries[i][1]; zo = queries[i][2];
        int idx_x = yo * n + zo, idx_y = xo * n + zo, idx_z = xo * n + yo;
        x[idx_x]++; y[idx_y]++; z[idx_z]++;
        if (x[idx_x] == n) ans++;
        if (y[idx_y] == n) ans++;
        if (z[idx_z] == n) ans++;
        cout<<ans<<nl;
    }
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}