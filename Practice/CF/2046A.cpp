// Author: Yu Xuan
// Created On: 03 12 2024 - 17:34:35
// File: 2046A
// Link: https://codeforces.com/contest/2046/problem/A

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
    int n; cin>>n; int grid[2][n]; vector<int> best_grid(n, -1e9);
    ff(i, 0, 1) {
        ff(j, 0, n-1) {
            cin >> grid[i][j];
            best_grid[j] = max(best_grid[j], grid[i][j]);
        }
    }
    int sm = accumulate(best_grid.begin(), best_grid.end(), 0LL), ans = -1e9;
    ff(i, 0, n-1) {
        // choose this column as best
        ans = max(ans, sm-best_grid[i]+grid[1][i]+grid[0][i]);
    }
    cout<<ans<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}