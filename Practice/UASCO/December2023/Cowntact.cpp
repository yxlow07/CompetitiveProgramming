// Author: Yu Xuan
// Created On: 18 11 2024 - 21:32:30
// File: Cowntact
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1348

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
//    #ifndef ONLINE_JUDGE
//        string current_path = filesystem::current_path().string();
//        freopen((current_path+"/inp.txt").c_str(), "r", stdin);
//        freopen((current_path+"/out.txt").c_str(), "w", stdout);
//        freopen((current_path+"/err.txt").c_str(), "w", stderr);
//    #endif
}

void solve() {
    int n; cin>>n; vector<int> interval_lengths;
    string s; cin>>s;
    int interval = 0;
    loop(c, s) {
        if (c == '1') interval++;
        else if (interval > 0) interval_lengths.push_back(interval), interval = 0;
    }
    if (interval > 0) interval_lengths.push_back(interval);
    if (interval_lengths.empty()) {
        cout<<0<<nl;
        return;
    }
    int max_days = min(interval_lengths[0], interval_lengths.back())-1, num_infected = 0; bool front_zero = false, back_zero = false;
    if (s[0] == '1') {
        max_days = min(max_days, interval_lengths[0]-1LL), front_zero = true;
    }
    if (s[n-1] == '1') {
        max_days = min(max_days, interval_lengths.back()-1), back_zero = true;
    }
    ff(i, 0, interval_lengths.size()-1) {
        if (i == 0 && front_zero) continue;
        if (i == interval_lengths.size()-1 && back_zero) continue;
        max_days = min(max_days, (interval_lengths[i]-1LL)/2LL);
    }
    loop(inter, interval_lengths) {
        num_infected += (inter + 2LL * max_days + 1LL - 1) / (2LL * max_days + 1LL);
    }
    cerr<<max_days<<nl;
    cout<<num_infected<<nl;
}

signed main() {
    fast();
    int tt = 1;
    while (tt--) solve();
}