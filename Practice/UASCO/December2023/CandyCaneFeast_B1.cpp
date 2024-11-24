// Author: Yu Xuan
// Created On: 18 11 2024 - 20:23:10
// File: CandyCaneFeast_B1
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1347

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
    int n, m; cin>>n>>m; int cows[n], candies[m];
    ff(i, 0, n-1) cin>>cows[i];
    ff(i, 0, m-1) cin>>candies[i];

    ff(i, 0, m-1) {
        int height = candies[i], base = 0;
        ff(j, 0, n-1) {
            if (cows[j] > base) {
                int eat_up_to = min(cows[j], height);
                if(eat_up_to > base) {
                    int amount_eaten = eat_up_to - base;
                    cows[j] += amount_eaten;
                    base += amount_eaten;
                    if(base >= height) break;
                }
            }
        }
    }
    ff(i, 0, n-1) cout<<cows[i]<<nl;
}

signed main() {
    fast();
    int tt = 1;
    while (tt--) solve();
}