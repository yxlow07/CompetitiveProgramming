// Author: Yu Xuan
// Created On: 28 11 2024 - 19:29:21
// File: 2041D
// Link: https://codeforces.com/problemset/problem/2041/D

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
    #ifdef LOCAL
        #include <filesystem>
        string current_path = filesystem::current_path().string();
        freopen((current_path+"/inp.txt").c_str(), "r", stdin);
        freopen((current_path+"/out.txt").c_str(), "w", stdout);
        freopen((current_path+"/err.txt").c_str(), "w", stderr);
    #endif
}

struct Point { int x, y; };

void solve() {
    int n, m; cin>>n>>m; char grid[n][m];
    Point start, target;
    ff(i, 0, n-1) {
        ff(j, 0, m-1) {
            cin>>grid[i][j];
            if (grid[i][j] == 'S') start = {i, j};
            else if (grid[i][j] == 'T') target = {i, j};
        }
    }
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    bool visited[n][m][4][4];
    memset(visited, false, sizeof(visited));

    // initialize BFS
    queue<tuple<int,int,int,int,int>> q;
    q.emplace(start.x, start.y, -1, 0, 0);
    ff(i, 0, 3) {
        q.emplace(start.x, start.y, i, 0, 0);
        visited[start.x][start.y][i][0] = true;
    }
    // Run bfs
    while (!q.empty()) {
        auto [x, y, dir, dist, turns] = q.front();
        q.pop();

        if (x == target.x && y == target.y) {
            cout<<dist<<nl;
            return;
        }

        // Explore
        ff(i, 0, 3) {
            int cx = x + dx[i], cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m || grid[cx][cy] == '#') continue;
            int new_turns = (i == dir) ? turns+1 : 1;
            if (new_turns > 3 || visited[cx][cy][i][new_turns]) continue;
            visited[cx][cy][i][new_turns] = true;
            q.emplace(cx, cy, i, dist+1, new_turns);
        }
    }
    cout<<-1<<nl;
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}