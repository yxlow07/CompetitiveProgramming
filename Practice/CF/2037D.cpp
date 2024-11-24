// Author: Yu Xuan
// Created On: 23 11 2024 - 13:14:11
// File: 2037D
// Link: https://codeforces.com/contest/2037/problem/D

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
    int n,m,l; cin>>n>>m>>l;
    vector<pair<int,int>> h(n);
    ff(i,0,n-1) cin>>h[i].first>>h[i].second; // first is start, second is end
    vector<pair<int,int>> p(m);
    ff(i,0,m-1) cin>>p[i].first>>p[i].second; // first is location, second is value
    sort(p.begin(), p.end());
    int pwr = 1, ptr = 0, ans = 0; multiset<int> powerups;
    priority_queue<pair<int,int>> pq;
    loop(pi, p) {
        pq.emplace(pi.second, pi.first);
    }
    ff(i, 0, n-1) {
        // collect all powerups
        while (ptr < m && p[ptr].first < h[i].first) {
            powerups.insert(p[ptr++].second);
        }
        while (pwr <= h[i].second-h[i].first+1) {
            if (powerups.empty()) {
                ans = -1;
                break;
            }
            auto it = prev(powerups.end());
            pwr += *it;
            powerups.erase(it);
            ans++;
        }
        if (ans == -1) break;
    }
    cout<<ans<<nl;
}

signed main() {
    fast();
    int tt = 1; cin>>tt;
    while (tt--) solve();
}