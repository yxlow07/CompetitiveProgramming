// Author: Yu Xuan
// Created On: 13 12 2024 - 18:49:31
// File: BookShop
// Link: https://cses.fi/problemset/task/1158

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
    int n, x; cin>>n>>x; int h[n], s[n]; ff(i, 0, n-1) cin>>h[i];
    ff(i, 0, n-1) cin>>s[i];
    vector<int> dp(x+1, 0);
    /*
     * let dp[i] = maximum number of pages that can be bought with i money
     * state transition: dp[i] = max(dp[i], dp[i-h[j]]+s[j])
     *  - case 1: don't buy book i => dp[i]
     *  - case 2: buy book i => dp[i-h[j]]+s[j]
     * base case: dp[0] = 0
     * answer: max(dp)
    */
    ff(i, 0, n-1) {
        fb(j, x, h[i]) {
            dp[j] = max(dp[j], dp[j-h[i]]+s[i]);
        }
    }
    cout<<dp[x]<<nl;
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}