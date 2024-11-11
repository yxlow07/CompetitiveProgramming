#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long long int lli;
#define pb push_back;
#define mp make_pair;
#define FOR(i, a, b) for (int i = a; i < b; i++)
typedef vector<int> vi;
typedef vector<pair<int, int>> vp;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin  >> s[i];
    }

    int used[n][m];
    vi dx = {0, 0, 1, -1};
    vi dy = {1, -1, 0, 0};
    int cc = 0; // Times bfs is done
    memset(used, 0, sizeof(used));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (used[i][j] || s[i][j] == "#") continue;
            cc++;
            // Connected components containing (i, j)
            vector<pair<int, int>> bfs;
            bfs.push_back({i, j}); used[i][j] = 1;

            for (int k = 0; k < bfs.size(); k++) {
                int x = bfs[k].first;
                int y = bfs[k].second;

                for (int l = 0; l < 4; l++) {
                    int u = x+dx[l];
                    int v = y+dy[l];

                    // {u, v} is neighbour of (x, y)
                    if (0 <= u && u < n && 0 <=v && v<n) {
                        if (s[u][v] == "#") continue;
                        used[u][v] = 1; bfs.push_back({u, v});
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

//    int t; cin >> t;

//    while (t--) {
//        solve();
//    }
solve();
    return 0;
}
