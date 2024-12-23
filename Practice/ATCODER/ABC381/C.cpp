// Author: Yu Xuan
// Created On: 27 11 2024 - 00:33:35
// File: C
// Link: https://atcoder.jp/contests/abc381/tasks/abc381_c

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
    int n; cin>>n; string s; cin>>s;
    int ans = 0;
    ff(i, 0, n-1) {
        if (s[i] == '/') {
            // Start search
            int l = i-1, r = i+1, local_sum = 1;
            if (l < 0 || r >= n) {
                ans = max(ans, local_sum);
                continue;
            }
            while (l >= 0 && r <= n && l < r) {
                if (s[l--] == '1' && s[r++] == '2') {
                    local_sum += 2;
                } else {
                    break;
                }
            }
            ans = max(ans, local_sum);
        }
    }
    cout<<ans<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}