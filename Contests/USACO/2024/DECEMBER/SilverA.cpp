// Author: Yu Xuan
// Created On: 14 12 2024 - 14:32:44
// File: SilverA
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

void tlewa() {
    int n; cin>>n; vector<int> cakes(n); loop(x, cakes) cin>>x;
    vector<int> prefix_sum(n+1, 0);
    ff(i, 0, n-1) prefix_sum[i+1] = prefix_sum[i] + cakes[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    ff(i, 0, n-1) dp[i][i] = cakes[i];
    ff(len, 2, n) {
        ff(i, 0, n-len) {
            int j = i+len-1, sm = prefix_sum[j+1] - prefix_sum[i];
            dp[i][j] = max(sm-dp[i+1][j], sm-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<" ";
    cout<<prefix_sum[n]-dp[0][n-1]<<nl;
}

void solve() {
    int n; cin>>n; vector<int> cakes(n); loop(x, cakes) cin>>x;
    int k = n/2-1; k = max(0LL, k);
    vector<int> prefix_sum(n+1, 0);
    ff(i, 0, n-1) prefix_sum[i+1] = prefix_sum[i] + cakes[i];
    vector<int> suffix_sum(n+1, 0);
    fb(i, n-1, 0) suffix_sum[n-i] = suffix_sum[n-i-1] + cakes[i];
    int e = 0;
    ff(i, 0, k) {
        if (i > n || (k-i) > n) continue;
        e = max(prefix_sum[i] + suffix_sum[k - i], e);
    }
    int b = prefix_sum[n] - e;
    cout << b << " " << e << nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}