// Author: Yu Xuan
// Created On: 07 12 2024 - 11:23:03
// File: 2050B
// Link: https://codeforces.com/contest/2050/problem/B

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
    int n; cin>>n; int nums[n], sm = 0; loop(num, nums) cin>>num, sm += num;
    if (sm % n != 0) {
        cout<<"NO"<<nl;
        return;
    }
    int avg = sm / n, diff = 0;
    ff(i, 1, n-2) {
        if (nums[i-1] > avg) {
            diff = nums[i-1]-avg;
            nums[i+1] += diff;
            nums[i-1] -= diff;
        } else if (nums[i-1] < avg) {
            diff = avg-nums[i-1];
            nums[i+1] -= diff;
            nums[i-1] += diff;
        }
    }
    bool flag = true;
    loop(num, nums) {
        if (num != avg) {
            flag = false;
            break;
        }
    }
    if (flag) cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}