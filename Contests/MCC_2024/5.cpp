// Author: Yu Xuan
// Created On: 16 11 2024 - 22:34:30
// File: 5
// Link: 

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

bool check(int mid, int k, int n, int m, vector<int> targets) {
    int res;
    ff(i, 0, n-1) {
        while (k > 0 && targets[i] > 0) {
            --k;
            ff(j, i, n-1) {
                res = m * mid - ((j - i) * (j -i));
                if (res > 0) {
                    targets[j] -= res;
                }
            }
        }
    }
    ff(i, 0, n-1) {
        if (targets[i] > 0) return false;
    }
    return true;
}

void solve() {
    int n,m,k; cin>>n>>m>>k;
    vector<int> targets(n);
    ff(i, 0, n-1) cin>>targets[i];
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l+r)/2;
        if (!check(mid, k, n, m, targets)) l = mid+1;
        else r = mid;
    }
    cout<<l<<nl;
}

signed main() {
    fast();
    int tt = 1;
    while (tt--) solve();
}