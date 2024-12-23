// Author: Yu Xuan
// Created On: 04 12 2024 - 21:42:21
// File: 2033B
// Link: https://codeforces.com/contest/2033/problem/B

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
    int n; cin>>n; int grid[n][n];
    ff(i, 0, n-1) {
        ff(j, 0, n-1) {
            cin>>grid[i][j];
        }
    }
    int ans = 0, idx = 1;
    // loop through all diagonals of nxn grid
    ff(i, 0, n-1) {
        int mn = 1e9, r = n-idx, c = 0;
        while (r < n && c < n) {
            mn = min(mn, grid[r][c]);
            r++; c++;
        }
        idx++;
        if (mn < 0) ans -= mn;
    }
    ff(i, 1, n-1) {
        int mn = 1e9, r = 0, c = i;
        while (r < n && c < n) {
            mn = min(mn, grid[r][c]);
            r++; c++;
        }
        if (mn < 0) ans -= mn;
    }
    cout<<ans<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}