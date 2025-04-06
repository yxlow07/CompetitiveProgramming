// Author: Yu Xuan
// Created On: 11 01 2025 - 19:56:08
// File: E
// Link: 

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define nl '\n'
#define in(n) int n; cin>>n;
#define in2(n, m) int n, m; cin>>n>>m;
#define in3(n, m, k) int n, m, k; cin>>n>>m>>k;
#define in4(n, m, k, l) int n, m, k, l; cin>>n>>m>>k>>l;
#define in5(n, m, k, l, o) int n, m, k, l, o; cin>>n>>m>>k>>l>>o;
#define inVec(a, n) vector<int> a(n); loop(x, a) cin>>x;
#define inPii(a, n) vector<pair<int,int>> a(n); loop(x, a) { int p, q; cin>>p>>q; a.emplace_back(p, q); }

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

void wa() {
    in(n);
    inVec(a, n);
    int ans = 0, ub = n;
    fb(i, n-1, 0) {
        int r = upper_bound(a.begin(), a.begin()+ub, a[i]/2) - a.begin();
        if (r > 0) ans++, ub = r-1;
    }
    cout<<ans<<nl;
}

bool ok(int m, vector<int> &a, int n) {
    ff(i, 0, m-1) {
        if (a[i] > a[n-m+i]/2) return false;
    }
    return true;
}

void solve() {
    in(n); inVec(a, n);
    int l = 0, r = n/2, ans = 0;

    while (l <= r) {
        int m = l+(r-l)/2;
        if (ok(m, a, n)) {
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    cout<<ans<<nl;
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}