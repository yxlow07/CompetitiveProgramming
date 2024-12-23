// Author: Yu Xuan
// Created On: 16 12 2024 - 20:28:13
// File: Labyrinth
// Link: https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define nl '\n'

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
template <class T> void _print(const T t) { cerr << t; }
template <class T, class V> void _print(const pair <T, V> p);
template <class T> void _print(const vector <T> v);
template <class T> void _print(const set <T> v);
template <class T, class V> void _print(const map <T, V> v);
template <class T> void _print(const multiset <T> v);
template <class T, class V> void _print(const pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(const vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(const set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(const multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(const map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve() {
    int n, m; cin>>n>>m; vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> start, end;
    ff(i, 0, n-1) {
        ff(j, 0, m-1) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }
    // BFS starting on start
    bool found = false;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q; q.push(start); visited[start.first][start.second] = true;
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    parent[start.first][start.second] = {0, 0};
    while (!q.empty()) {
        if (q.front() == end) {
            found = true; break;
        }
        pair<int, int> curr = q.front(); q.pop();
        int x = curr.first, y = curr.second;
        ff(i, 0, 3) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
                parent[nx][ny] = {x, y};
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
    if (!found) {
        cout<<"NO"<<nl;
        return;
    } else {
        cout<<"YES"<<nl;
        // Reconstruction
        string path = "";
        while (end != start) {
            pair<int, int> prev = parent[end.first][end.second];
            if (prev.first == end.first) {
                if (prev.second < end.second) path += 'R';
                else path += 'L';
            } else {
                if (prev.first < end.first) path += 'D';
                else path += 'U';
            }
            end = prev;
        }
        reverse(path.begin(), path.end());
        cout<<path.size()<<nl<<path<<nl;
    }
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}