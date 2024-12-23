// Author: Yu Xuan
// Created On: 16 12 2024 - 21:05:58
// File: MessageRoute
// Link: https://cses.fi/problemset/task/1667

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

void solve() {
    int n, m, a, b; cin>>n>>m; vector<vector<int>> adj(n+1);
    ff(i, 1, m) {
        cin>>a>>b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    vector<int> dist(n+1, -1); queue<int> q; q.push(1); dist[1] = 0; vector<int> parent(n+1, -1); parent[1] = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        loop(neigh, adj[curr]) {
            if (dist[neigh] == -1) {
                parent[neigh] = curr;
                dist[neigh] = dist[curr]+1;
                q.push(neigh);
            }
        }
    }
    if (dist[n] == -1) {
        cout<<"IMPOSSIBLE"<<nl;
        return;
    }
    cout<<dist[n]+1<<nl;
    vector<int> path; int curr = n;
    while (curr != 0) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    loop(p, path) cout<<p<<" ";
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}