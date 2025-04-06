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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve() {
    in2(h,w);
    int grid[h][w], backup[h][w]; char c;
    ff(i, 0, h-1) {
        ff(j, 0, w-1) cin>>c, grid[i][j] = c-48, backup[i][j] = c-48;
    }
    int ans = 0;
    // first subtask, h=1
    if (h == 1) {
        ff(i, 0, w-1) {
            // loop through each cell that is empty and start bfs, 2 = flooded
            if (grid[0][i] == 0) {
                //cout<<"Started bfs at cell "<<i+1<<nl;
                queue<int> q;
                int total = 1;
                q.push(i);
                while (!q.empty()) {
                    int nodex = q.front();
                    grid[0][nodex] = 2;
                    q.pop();
                    if (nodex-1 >= 0 && grid[0][nodex-1] != 2) {
                        if (grid[0][nodex-1] == 1) {
                            // check if its other neighbour is flooded
                            if (nodex-2 >= 0 && grid[0][nodex-2] == 2) {
                                q.push(nodex - 1); // left cell
                                total++;
                                // cout<<"Node pushed to queue (1)(-): "<<nodex-1<<nl;
                            }
                        } else total++, q.push(nodex-1);// cout<<"Node pushed to queue (0)(-): "<<nodex-1<<nl;
                    }
                    if (nodex+1 < w && grid[0][nodex+1] != 2) {
                        if (grid[0][nodex+1] == 1) {
                            // check if its other neighbour is flooded
                            if (nodex+2 <w && grid[0][nodex+2] == 2) {
                                q.push(nodex + 1); // left cell
                                total++;
                                // cout<<"Node pushed to queue (1)(+): "<<nodex+1<<nl;
                            }
                        } else total++, q.push(nodex+1);// cout<<"Node pushed to queue (0)(+): "<<nodex+1<<nl;
                    }
                }
                // cout<<"Total: "<<total<<nl;
                ans += total;
                ff(j, 0, h-1) {
                    ff(k, 0, w-1) grid[j][k] = backup[j][k];
                }
            }
        }
    } else {
        ff(i, 0, h-1) {
            ff(j, 0, w-1) {
                // loop through all cells that are empty
                if (grid[i][j] == 0) {
                    // cout<<"Started bfs at cell "<<i<<sp<<j<<nl;
                    queue<int> qx, qy;
                    bool vis[h][w];
                    memset(vis, false, sizeof vis);
                    int total = 1;
                    qx.push(i); qy.push(j);
                    while (!qx.empty()) {
                        int nodex = qx.front(), nodey = qy.front();
                        // cout<<"Visiting cell "<<nodex<<sp<<nodey<<nl;
                        grid[nodex][nodey] = 2;
                        qx.pop(), qy.pop();

                        // explore all of its neighbours
                        ff(k, 0, 3) {
                            int cx = nodex+dx[k], cy = nodey+dy[k];
                            
                            // check if cell is valid
                            if (cx < 0 || cy < 0 || cx >= h || cy >= w) continue;
                            if (vis[cx][cy]) continue;

                            // has a building, check if neighbouring cells of the building cnt >= 2
                            if (grid[cx][cy] == 1) {
                                int count_neigh_flooded = 0;
                                ff(z, 0, 3) {
                                    int ccx = cx+dx[z], ccy = cy+dy[z];
                                    if (ccx < 0 || ccy < 0 || ccx >= h || ccy >= w) continue;
                                    if (grid[ccx][ccy] == 2) count_neigh_flooded++;
                                }
                                if (count_neigh_flooded >= 2) qx.push(cx), qy.push(cy), total++, vis[cx][cy] = true;
                            } else if (grid[cx][cy] == 0) {
                                // cout<<"Cell "<<cx<<sp<<cy<<" is not flooded, now flooded"<<nl;
                                qx.push(cx); qy.push(cy);
                                vis[cx][cy] = true;
                                total++;
                            }
                        }
                    }
                    // cout<<"Total when flooding cell: "<<i<<sp<<j<<sp<<total<<nl;
                    ans += total;
                    ff(j, 0, h-1) ff(k, 0, w-1) grid[j][k] = backup[j][k];
                }
            }
        }
    }
    cout<<ans;
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