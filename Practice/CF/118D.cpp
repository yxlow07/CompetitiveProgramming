// Author: Yu Xuan
// Created On: 01 12 2024 - 13:53:27
// File: 118D
// Link: https://codeforces.com/problemset/problem/118/D

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

int MOD = 1e8;
int dp[101][101][11][11];
int k1, k2;

int c(int f, int h, int lf, int lh) {
    if ((f + h) == 0) {
        return 1;
    }
    if (dp[f][h][lf][lh] != -1) {
        return dp[f][h][lf][lh];
    }

    int x = 0, y = 0;
    if (lf > 0 && f > 0) x = c(f - 1, h, lf - 1, k2);
    if (lh > 0 && h > 0) y = c(f, h - 1, k1, lh - 1);
    dp[f][h][lf][lh] = (x + y) % MOD;
    return dp[f][h][lf][lh];
}

void solve() {
    int n1, n2; cin>>n1>>n2>>k1>>k2;
    memset(dp, -1, sizeof dp);
    int ans = c(n1, n2, k1, k2);
    cout<<ans<<nl;
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}