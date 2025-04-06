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
typedef long long ll;
#define pb push_back
const ll INF = 1e18;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return rng()%(r-l+1)+l; }

bool valid(const int idx, const int k) {
    return idx >= 0 && idx < k;
}

void solve() {
    int a,b,n,k;
    in2(n,k);
    vpii monst(n,{0,0}), mines(k+2,{0,0}); vi mines_pos(k+2,0);
    mines[0] = {-1e18, 0}, mines[k+1] = {1e18, 0};
    mines_pos[0] = -1e18, mines_pos[k+1] = 1e18;
    ff(i, 0, n-1) {
        in2(a,b);
        monst[i] = {a,b}; // fi => loc, se => health
    }
    ff(i, 1, k) {
        in(a);
        // int a = mines_p[i];
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
        pos = monst[i].fi, health = monst[i].se;
        // first choice: decrease its health to 0 => health
        // second choice: move it to the nearest bomb
        int bomb_idx = lower_bound(all(mines_pos), pos) - mines_pos.begin();
        int dist = 1e18, dist2 = 1e18, dist3 = 1e18;
        if (valid(bomb_idx, k)) dist = abs(mines_pos[bomb_idx]-pos)+1ll;
        if (valid(bomb_idx-1,k)) dist2 = abs(mines_pos[bomb_idx-1]-pos)+1ll;
        if (valid(bomb_idx+1, k)) dist3 = abs(mines_pos[bomb_idx+1]-pos)+1ll;
        int best = min(dist, min(dist2, dist3));
        if (best <= health) {
            ans += best;
            // mines[bomb_idx].se++;
            if (best == dist && valid(bomb_idx,k)) mines[bomb_idx].se++;
            else if (best == dist2 && valid(bomb_idx-1,k)) mines[bomb_idx-1].se++;
            else mines[bomb_idx+1].se++;
            cerr<<"Monster "<<i<<" chose to use bomb"<<nl;
        } else {
            ans += health;
            cerr<<"Monster "<<i<<" chose to use health because dist is "<<abs(mines_pos[bomb_idx])<<nl;
        }
    }
    ff(i, 0, k-1) {
        if ((mines[i].se)>1ll) ans -= ((mines[i].se)-1ll);
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt = 1;
    while (tt--) {
        solve();
    }
}