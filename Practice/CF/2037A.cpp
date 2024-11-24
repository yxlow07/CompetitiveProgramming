// Author: Yu Xuan
// Created On: 22 11 2024 - 16:03:35
// File: 2037A
// Link: https://codeforces.com/contest/2037/problem/A

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
    #ifndef ONLINE_JUDGE
        string current_path = filesystem::current_path().string();
        freopen((current_path+"/inp.txt").c_str(), "r", stdin);
        freopen((current_path+"/out.txt").c_str(), "w", stdout);
        freopen((current_path+"/err.txt").c_str(), "w", stderr);
    #endif
}

void solve() {
    int n, x; cin>>n;
    map<int,int> mp;
    ff(i, 0, n-1) cin>>x, mp[x]++;
    int ans = 0;
    loop(a, mp) {
        ans += a.second/2;
    }
    cout<<ans<<nl;
}

signed main() {
    fast();
    int tt = 1; cin>>tt;
    while (tt--) solve();
}