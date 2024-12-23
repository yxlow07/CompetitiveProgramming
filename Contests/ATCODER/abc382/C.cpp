// Author: Yu Xuan
// Created On: 30 11 2024 - 20:08:00
// File: C
// Link: https://atcoder.jp/contests/abc382/tasks/abc382_c

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
    int n, m; cin>>n>>m;
    vector<pair<int,int>> b(m); int a[n];
    ff(i, 0, n-1) cin>>a[i];
    ff(i, 0, m-1) cin>>b[i].first, b[i].second = i;
    sort(b.begin(), b.end());
    vector<int>ans(m);
    ff(i, 0, n-1) {
        while (!b.empty() && b.back().first >= a[i]) {
            ans[b.back().second] = i+1;
            b.pop_back();
        }
    }
    for (int i = 0; i < m; i++) {
        if (!ans[i]) cout << -1 << "\n";
        else cout << ans[i] << "\n";
    }
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}