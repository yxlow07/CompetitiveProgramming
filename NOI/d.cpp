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

bool check_bounds(const int x, const int y, const int h, const int w) {
    return y >= 0 && y <= h+1 && x >= 0 && x <= w+1;
}

void solve() {
    in2(h,w);
    vi special(w+1);
    ff(i, 1, w) {
        cin>>special[i];
    }
    in(q);
    bool vis[w+2];
    memset(vis, false, sizeof vis);
    int preans[w+2];
    memset(preans, 0, sizeof preans);
    while (q--) {
        in2(a,b);
        int ans = 0;
        ff(i, a, b) {
            if (vis[i]) {
                cout<<"Precalculated for col "<<i<<nl;
                ans += preans[i];
                continue;
            }
            set<int> reachable;
            vis[i] = true;

            // do a bfs, add all possible states
            queue<int> exp_x, exp_y;
            exp_x.push(i); exp_y.push(0);

            while (!exp_x.empty() && !exp_y.empty()) {
                int x = exp_x.front(), y = exp_y.front();
                exp_x.pop(), exp_y.pop();

                if (!check_bounds(x, y, h, w)) {
                    cout<<x<<sp<<y<<" does not pass bounds check"<<nl;
                    continue;
                } else {
                    cout<<x<<sp<<y<<" pass bounds check"<<nl;
                }

                // check if reached destination
                if (y == w+1) {
                    reachable.insert(x);
                    continue;
                }

                // check if is special cell
                if (special[y] == x) {
                    cout<<"Special cell at "<<x<<sp<<y<<nl;
                    // first case: its red, robot moves upwards
                    exp_x.push(x+1); exp_y.push(y);
                    cout<<"Red cell added at special cell"<<x<<sp<<y<<nl;
                    // second case: its blue, robot moves downwards
                    exp_x.push(x-1); exp_y.push(y);
                    cout<<"Blue cell added at special cell"<<x<<sp<<y<<nl;
                } else {
                    cout<<"White cell"<<nl;
                    // white cell move right
                    exp_x.push(x); exp_y.push(y+1);
                }
            }
            preans[i] = reachable.size();
            cout<<"Answer for starting at col "<<i<<" = "<<preans[i]<<nl;
            ans += preans[i];
        }
        cout<<ans<<nl;
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