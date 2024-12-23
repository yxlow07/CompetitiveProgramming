// Author: Yu Xuan
// Created On: 07 12 2024 - 11:31:42
// File: 2050C
// Link: https://codeforces.com/contest/2050/problem/C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define nl '\n'
#define debug(x) cerr << #x <<" "<<x; cerr << endl;

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
    int n = s.size(), sm = 0;
    loop(c, s) sm += c - '0';
    if (sm % 9 == 0) {
        cout<<"YES"<<nl;
        return;
    }
    map<int,int> mp;
    ff(i, 0, n-1) {
        mp[s[i] - '0']++;
    }
    int diff = sm % 9, c2 = mp[2], c3 = mp[3];
    if (c2 > 0 && c3 > 0) {
        ff(i, 0, c2) {
            ff(j, 0, c3) {
                if ((i*2 + j*6+diff) % 9 == 0) {
                    cout<<"YES"<<nl;
                    return;
                }
            }
        }
    } else if (c2 > 0) {
        ff(i, 0, c2) {
            if ((i*2+diff) % 9 == 0) {
                cout<<"YES"<<nl;
                return;
            }
        }
    } else if (c3 > 0) {
        ff(i, 0, c3) {
            if ((i*6+diff) % 9 == 0) {
                cout<<"YES"<<nl;
                return;
            }
        }
    }
    debug(sm);
    cout<<"NO"<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}