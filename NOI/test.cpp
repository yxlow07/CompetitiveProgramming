#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for (int i = a; i<=b; i++)
#define loop(a,b) for (auto &a: b)
#define nl '\n'
#define sp ' '
#define in(n) cin>>n;
#define in2(a,b) cin>>a>>b;
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define fi first
#define se second

bool valid(const int idx, const int k) {
    return idx >= 0 && idx < k;
}

void solve() {
    int a,b,n,k;
    in2(n,k);
    bool all_hi_1e9 = true;
    vpii monst(n,{0,0}), mines(k,{0,0}); vi mines_pos(k,0);
    ff(i, 0, n-1) {
        in2(a,b);
        monst[i] = {a,b}; // fi => loc, se => health
        if (b != 1e9) all_hi_1e9 = false;
    }
    ff(i, 0, k-1) {
        in(a);
        mines[i] = {a,0};
        mines_pos[i] = a;
    }
    sort(all(mines));
    sort(all(mines_pos));
    // ff(i, 0, k-1) cout<<mines_pos[i]<<sp;
    // cout<<nl;
    int ans = 0ll;
    // loop thru all monsters
    int pos, health;
    ff (i, 0, n-1) {
        
    }
    ff(i, 0, k-1) {
        if ((mines[i].se)>1ll) ans -= ((mines[i].se)-1ll);
    }
    cout<<ans;
    cout.flush();
    return;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // cout<<fixed<<setprecision(12);
    int tt = 1;
    // cin>>tt;
    while (tt--) {
        solve();
    }
}