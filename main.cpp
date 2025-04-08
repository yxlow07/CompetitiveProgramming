// Author: Yu Xuan
// Finish Time: 3/11/2025, 5:11:42 PM AC

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define nl '\n'
#define sp ' '
#define in(n) int n; cin>>n;
#define in2(n, m) int n, m; cin>>n>>m;
#define in3(n, m, k) int n, k, m; cin>>n>>m>>k;
#define in4(n, m, k, l) int n, m, k, l; cin>>n>>m>>k>>l;
#define in5(n, m, k, l, o) int n, m, k, l, o; cin>>n>>m>>k>>l>>o;
#define ins(s) string s; cin>>s;
#define ins2(s, t) string s, t; cin>>s>>t;
#define inc(c) char c; cin>>c;
#define inVec(a, n) vector<int> a(n); loop(x, a) cin>>x;
#define inPii(a, n) vector<pair<int,int>> a(n); loop(x, a) { int p, q; cin>>p>>q; a.emplace_back(p, q); }
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define yes cout<<"YES"<<nl;
#define no cout<<"NO"<<nl;
#define fi first
#define se second
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define i128 __int128_t

map<int,bool> calc;
map<int,int> factans;

int rnd(int l, int r) { return rng()%(r-l+1)+l; }
int fact(int n) { if (calc[n] == true) return factans[n]; int ans = 1; ff(i, 2, n) ans *= i; calc[n] = true; return factans[n] = ans; }
int npr(int n, int r) { return fact(n)/fact(n-r); }
int ncr(int n, int r) { return fact(n)/(fact(r)*fact(n-r)); }
int leastSignificantUnsetBit(int n) { return (n+1)&~n; }
int ceil(int a, int b) { return (a+b-1)/b; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout<<fixed<<setprecision(10);
    int tt = 1;
    // cin>>tt;
    while (tt--) {
        solve();
    }
}
