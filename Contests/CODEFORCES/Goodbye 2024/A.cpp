// Author: Yu Xuan
// Created On: 28 12 2024 - 22:36:12
// File: A
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
    int n; cin>>n; vector<int> a(n); loop(x, a) cin>>x;
    vector<vector<bool>> stable(n+1, vector<bool>(n+1, false));
    ff(i, 1, n) {
        int mn = a[i-1], mx = a[i-1];
        ff(j, i, n) {
            if (j > i) mn = min(mn, a[j-1]), mx = max(mx, a[j-1]);
            stable[i][j] = (2 * mn > mx);
        }
    }
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    ff(i, 1, n) {
        int total = 0;
        ff(j, 0, i-1) {
            if (stable[j+1][i]) total += dp[j];
            if (total >= 2) {
                total = 2;
                break;
            }
        }
        dp[i] = total;
    }
    cout<<(dp[n] >= 2 ? "YES" : "NO")<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}