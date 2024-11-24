// Author: Yu Xuan
// Created On: 22 11 2024 - 16:11:00
// File: 2037B
// Link: https://codeforces.com/contest/2037/problem/B

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
    int k,x; cin>>k; map<int,int> mp;
    ff(i, 0, k-1) cin>>x, mp[x]++;
    int ans = k-2;
    // find factors of ans
    vector<int> factors;
    ff(i, 1, sqrt(ans)) {
        if (ans % i == 0) {
            factors.push_back(i);
            if (i != ans/i) factors.push_back(ans/i);
        }
    }
    loop(factor, factors) {
        if (mp[factor] >= 1 && mp[ans/factor] >= 1) {
            cout<<factor<<" "<<ans/factor<<nl;
            return;
        }
    }
}

signed main() {
    fast();
    int tt = 1; cin>>tt;
    while (tt--) solve();
}