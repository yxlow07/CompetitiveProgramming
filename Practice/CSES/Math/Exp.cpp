// Author: Yu Xuan
// Created On: 09 12 2024 - 21:49:34
// File: Exp
// Link: https://cses.fi/problemset/task/1095

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define nl '\n'

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

int MOD = 1e9+7;

int fastExp(int a, int b) {
    if (b == 0) return 1;
    int res = fastExp(a, b/2);
    if (b % 2 == 0) return (res*res)%MOD;
    return (((res*res)%MOD)*a)%MOD;
}

void solve() {
    int a,b; cin>>a>>b;
    cout<<fastExp(a,b)<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}