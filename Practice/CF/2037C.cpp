// Author: Yu Xuan
// Created On: 22 11 2024 - 18:56:45
// File: 2037C
// Link: https://codeforces.com/contest/2037/problem/C

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
    int n; cin>>n;
    if (n <= 4) cout<<-1<<nl;
    else {
        for (int i = 1; i <= n; i+=2) {
            if (i == 5) continue;
            cout<<i<<" ";
        }
        cout<<"5 4 ";
        for (int i = 2; i <= n; i+=2) {
            if (i == 4) continue;
            cout<<i<<" ";
        }
        cout<<nl;
    }
}

signed main() {
    fast();
    int tt = 1; cin>>tt;
    while (tt--) solve();
}