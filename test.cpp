// Author: Yu Xuan
// Created On: 03 09 2024 - 14:54:12
// File: template

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll unsigned long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define no cout << "NO" << '\n';
#define yes cout << "YES" << '\n';
#define negative cout << "-1" << '\n';
#define nl '\n'

#ifndef ONLINE_JUDGE

#else
#define debug(x)
#endif

const int MOD = 1e9+7;
const int inf = 2e18;

void fast(const string &file = "") {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout<<fixed<<setprecision(12);
    cerr<<fixed<<setprecision(12);
    if (!file.empty()) { (void) !freopen((file + ".in").c_str(), "r", stdin); (void) !freopen((file + ".out").c_str(), "w", stdout); }
#ifndef ONLINE_JUDGE
    string current_path = filesystem::current_path().string();
    freopen((current_path+"/inp.txt").c_str(), "r", stdin);
    freopen((current_path+"/out.txt").c_str(), "w", stdout);
    freopen((current_path+"/err.txt").c_str(), "w", stderr);
#endif
}

void solve() {

}

signed main() {
    auto start = chrono::high_resolution_clock::now();
    fast();
    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << "Time taken: " << time_taken << " ms" << '\n';
}

