// Author: Yu Xuan
// Created On: 28 11 2024 - 20:40:17
// File: A_Frog1
// Link: https://atcoder.jp/contests/dp/tasks/dp_a

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

void solve() {
    int n; cin>>n; int h[n];
    ff(i,0,n-1) cin>>h[i];
    int dp[n+1]; // dp[i] = min cost to reach i
    dp[0] = 0; dp[1] = abs(h[1]-h[0]);
    ff(i, 2, n-1) {
        int x, y;
        x = dp[i-1]+abs(h[i]-h[i-1]);
        y = dp[i-2]+abs(h[i]-h[i-2]);
        dp[i] = min(x, y);
    }
    cout<<dp[n-1]<<nl;
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}