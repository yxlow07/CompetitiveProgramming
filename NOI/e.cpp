#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for (int i = a; i<=b; i++)
#define loop(a,b) for (auto &a: b)
#define nl '\n'
#define sp ' '
#define in(n) int n; cin>>n;
#define in2(a,b) int a,b; cin>>a>>b;
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
#define yes cout<<"YES"
#define no cout<<"NO"
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {return rng()%(r-l+1)+l;}

// problem: reachability
void solve() {
    in(n);
    vi l(n); ff(i, 0, n-1) cin>>l[i];
    vi adj[n];
    // edge list
    vpii edge(n-1);
    ff(i, 0, n-2) {
        in2(a,b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge[i] = {a,b};
    }
    // try all possibilities
    bool found = false;
    
    
    if (found) yes;
    else no;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout<<fixed<<setprecision(12);
    int tt = 1;
    // cin>>tt;
    while (tt--) {
        solve();
    }
}