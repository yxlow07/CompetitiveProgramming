// Author: Yu Xuan
// Created On: 01 01 2025 - 00:25:45
// File: RoundTrip
// Link: https://cses.fi/problemset/task/1669

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define nl '\n'
#define in(n) int n; cin>>n;
#define in2(n, m) int n, m; cin>>n>>m;
#define in3(n, m, k) int n, m, k; cin>>n>>m>>k;
#define in4(n, m, k, l) int n, m, k, l; cin>>n>>m>>k>>l;
#define in5(n, m, k, l, o) int n, m, k, l, o; cin>>n>>m>>k>>l>>o;
#define inVec(a, n) vector<int> a(n); loop(x, a) cin>>x;
#define inPii(a, n) vector<pair<int,int>> a(n); loop(x, a) { int p, q; cin>>p>>q; a.emplace_back(p, q); }

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

bool found = false;
vector<bool> visited(100001, false);

void printResult(int node, vector<int> &path) {
    found = true;
    int count = 1;
    string result = "";
    result += to_string(node) + " ";
    for (int i = path.size() - 1; i >= 0; i--) {
        result += to_string(path[i]);
        count++;
        if (path[i] == node)
            break;
        else
            result += " ";
    }
    cout << to_string(count) << "\n" << result << endl;
}

void dfs(int node, int parent, vector<int> &path, vector<vector<int>> &adj) {
    if (found) return;
    if (visited[node]) {
        if (path.size() > 2) printResult(node, path);
        return;
    }
    visited[node] = true;
    path.push_back(node);
    loop(neigh, adj[node]) {
        if (neigh == parent) continue;
        dfs(neigh, node, path, adj);
    }
    path.pop_back();
}

void solve() {
    in2(n, m);
    vector<vector<int>> adj(n+1); int a,b;
    ff(i, 1, m) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ff(i, 1, n) {
        if (!visited[i]) {
            vector<int> path;
            dfs(i, -1, path, adj);
        }
    }
    if (!found) cout<<"IMPOSSIBLE"<<nl;
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}