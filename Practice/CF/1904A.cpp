// Author: Yu Xuan
// Created On: 05 12 2024 - 15:36:19
// File: 1904A
// Link: https://codeforces.com/contest/1904/problem/A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &(a) : b)
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
    int a,b,x1,y1,x2,y2; cin>>a>>b>>x1>>y1>>x2>>y2;
    set<pair<int,int>> changes = {{a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
    set<pair<int,int>> possible_knight_king, possible_knight_queen;
    for (auto [dx, dy] : changes) {
        possible_knight_king.insert({x1 + dx, y1 + dy});
        possible_knight_queen.insert({x2 + dx, y2 + dy});
    }
    int ans = 0;
    loop(king, possible_knight_king) {
        if(possible_knight_queen.find(king) != possible_knight_queen.end()) ans++;
    }
    cout<<ans<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}