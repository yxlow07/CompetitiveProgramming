// Author: Yu Xuan
// Created On: 30 11 2024 - 20:04:11
// File: B
// Link: https://atcoder.jp/contests/abc382/tasks/abc382_b

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
    int n, d; cin>>n>>d;
    string s; cin>>s; int count = 0, empty = 0; vector<int> ptrs;
    ff(i, 0, n-1) {
        if (s[i] == '@') count++, ptrs.push_back(i);
        else empty++;
    }
    int sz = ptrs.size();
    ff(i, 0, d-1) {
        s[ptrs[sz-1-i]] = '.';
    }
    cout<<s<<nl;
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}