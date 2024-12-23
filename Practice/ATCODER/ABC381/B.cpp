// Author: Yu Xuan
// Created On: 27 11 2024 - 00:17:11
// File: B
// Link: https://atcoder.jp/contests/abc381/tasks/abc381_b

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
    string s; cin>>s;
    int n = s.size();
    bool flag = (n % 2 == 0);
    if (!flag) {
        cout<<"No"<<nl;
    } else {
        map<char,int> mp;
        loop(c, s) mp[c]++;
        ff(i, 0, (n/2)-1) {
            if(s[2*i] != s[2*i+1]) flag=false;
        }
        loop(ch, mp) {
            if (ch.second != 0 && ch.second != 2) flag = false;
        }
        if (flag) {
            cout<<"Yes"<<nl;
        } else {
            cout<<"No"<<nl;
        }
    }
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}