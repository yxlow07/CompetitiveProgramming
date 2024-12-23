// Author: Yu Xuan
// Created On: 17 12 2024 - 16:05:51
// File: ShortestRoutes1
// Link: https://cses.fi/problemset/task/1671

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

void tle() {
    int n, m, a, b, c; cin>>n>>m; vector<vector<pair<int, int>>> adj(n+1);
    ff(i, 1, m) {
        cin>>a>>b>>c;
        adj[a].emplace_back(b, c);
    }
    vector<int> dist(n+1, 1e18); dist[1] = 0;
//    vector<int> p(n+1, -1);
    vector<bool> marked(n+1, false);
    ff(i, 1, n) {
        int v = -1;
        ff(j, 1, n) {
            if (!marked[j] && (v == -1 || dist[j] < dist[v])) v = j;
        }
        if (dist[v] == 1e18) break;
        marked[v] = true;
        for (auto [to, len] : adj[v]) {
            dist[to] = min(dist[to], dist[v]+len);
        }
    }

    ff(i, 1, n) cout<<dist[i]<<" ";
}

void solve() {
    int n, m, a, b, c; cin>>n>>m; vector<vector<pair<int, int>>> adj(n+1);
    ff(i, 1, m) {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    vector<int> dist(n+1, 1e18); dist[1] = 0; set<pair<int, int>> s; s.insert({0, 1});
    while (!s.empty()) {
        int v = s.begin()->second; s.erase(s.begin());
        for (auto [to, len] : adj[v]) {
            if (dist[v]+len < dist[to]) {
                s.erase({dist[to], to});
                dist[to] = dist[v]+len;
                s.insert({dist[to], to});
            }
        }
    }
    ff(i, 1, n) cout<<dist[i]<<" ";
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}