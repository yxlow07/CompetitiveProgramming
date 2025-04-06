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

void solve() {
    in2(n,m);
    vpii rb(n);
    vi thumps(m);
    ff(i, 0, n-1) {
        in2(a,b);
        rb[i] = {a,b};
    }
    ff(i, 0, m-1) {
        cin>>thumps[i];
        thumps[i]--;
    }
    ff(i, 0, m-1) {
        // cout<<"Thumper of idx "<<thumps[i]<<nl; 
        int x = rb[thumps[i]].fi, y = rb[thumps[i]].se;
        ff(j, 0, n-1) {
            if (j == thumps[i]) continue;
            // cout<<"Currently moving rabbit at idx "<<i<<nl;
            // rowdiff coldiff
            // cout<<x<<sp<<y<<nl;
            // cout<<rb[i].fi<<sp<<rb[i].se<<nl;
            int rowdiff = abs(x-rb[j].fi), coldiff = abs(y-rb[j].se);
            // cout<<rowdiff<<sp<<coldiff<<nl;
            if (rowdiff == coldiff) {
                // cout<<"Initially "<<rb[j].fi<<sp<<rb[j].se<<nl;
                if (x-rb[j].fi >= 0) rb[j].fi--;
                else rb[j].fi++;
                if (y-rb[j].se >= 0) rb[j].se--;
                else rb[j].se++;
                
            } else if (rowdiff > coldiff) {
                // move two rows away from thumper
                // cout<<"move two rows away"<<nl;
                if (x-rb[j].fi >= 0) rb[j].fi-=2;
                else rb[j].fi+=2;
            } else {
                // move two cols away
                // cout<<"move two cols away"<<nl;
                if (y-rb[j].se >= 0) rb[j].se-=2;
                else rb[j].se+=2;
            }
            // cout<<"After "<<rb[j].fi<<sp<<rb[j].se<<nl;
        }
    }
    ff(i, 0, n-1) {
        cout<<rb[i].fi<<sp<<rb[i].se;
        if (i != n-1) cout<<nl;
    }
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