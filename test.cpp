#include "bits/stdc++.h"
using namespace std;
#define int long long

#define ff(i,a,b) for(int i=a;i<=b;i++)
void fast(const string &file = "") {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); // Unbind cin cout
    cout<<fixed<<setprecision(15); // Set precision for double outputting
    cerr<<fixed<<setprecision(15);
    if (!file.empty()) { (void) !freopen((file + ".in").c_str(), "r", stdin); (void) !freopen((file + ".out").c_str(), "w", stdout); }
#ifndef ONLINE_JUDGE
    string current_path = filesystem::current_path().string();
    freopen((current_path+"/inp.txt").c_str(), "r", stdin);
    freopen((current_path+"/out.txt").c_str(), "w", stdout);
    freopen((current_path+"/err.txt").c_str(), "w", stderr);
#endif
}

signed main() {
    fast();
    int n,x;cin>>n; int sum= 0;
    while(n--) {
        cin>>x;
        sum+=x;
    }
    cout<<sum;
    return 0;
}
