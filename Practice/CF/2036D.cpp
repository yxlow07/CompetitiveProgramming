// Author: Yu Xuan
// Created On: 09 11 2024 - 14:39:01
// File: 2036D
// Link: https://codeforces.com/problemset/problem/2036/D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vll vector<ll>
#define ll unsigned long long
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>
#define mci map<char, int>
#define mii map<int, int>
#define mss map<string, string>
#define mib map<int, bool>

#define inputVec(arr) for(auto &ax: arr) {cin >> ax;}
#define inputStringVec(arr) for (auto &x: arr) { getline(cin, x); }
#define outputVec(arr) for(auto &a: arr) {cout << a << " ";}
#define ret return
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fi(i, a) for(int i=a;;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define fn(i,a,b,n) for(int i=a;i<=b;i+=n)
#define loop(a, b) for (auto &a : b)
#define no cout << "No" << '\n';
#define yes cout << "Yes" << '\n';
#define negative cout << "-1" << '\n';
#define nl '\n'
#define all(x) x.begin(), x.end()
#define init(a, n) memset((a), (n), sizeof(a));
#define initLimit(a, n, x) memset((a), (n), (x));
#define bg begin()
#define ed end()
#define sz(x) x.size()
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

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

struct Point { int x, y; };
struct Rectangle { Point leftBottom, rightTop; };
struct Cuboid { int x1, y1, z1; int x2, y2, z2; }; // Two opposite vertexes

const int MOD = 1e9+7;
const int inf = 2e18;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void fast(const string &file = "") {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); // Unbind cin cout
    cout<<fixed<<setprecision(35); // Set precision for double outputting
    cerr<<fixed<<setprecision(35);
    if (!file.empty()) { (void) !freopen((file + ".in").c_str(), "r", stdin); (void) !freopen((file + ".out").c_str(), "w", stdout); }
    #ifndef ONLINE_JUDGE
        string current_path = filesystem::current_path().string();
        freopen((current_path+"/inp.txt").c_str(), "r", stdin);
        freopen((current_path+"/out.txt").c_str(), "w", stdout);
        freopen((current_path+"/err.txt").c_str(), "w", stderr);
    #endif
}

void tourist() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    int ans = 0;
    for (int r = 0; r + r <= min(h - 1, w - 1); r++) {
        string t = "";
        for (int j = r + 1; j < w - r; j++) {
            t += s[r][j];
        }
        for (int i = r + 1; i < h - r; i++) {
            t += s[i][w - 1 - r];
        }
        for (int j = w - 2 - r; j >= r; j--) {
            t += s[h - 1 - r][j];
        }
        for (int i = h - 2 - r; i >= r; i--) {
            t += s[i][r];
        }
        t += t.substr(0, 3);
        debug(t);
        for (int i = 0; i <= t.size() - 4; i++) {
            if (t.substr(i, 4) == "1543") {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
}

void solve() {
    int n, m, ans = 0; cin>>n>>m; vector<string> grid(n);
    ff(i, 0, n-1) {
        cin>>grid[i];
    }
    for (int i = 0; i+i <= min(n-1, m-1); i++) {
        string s = "";
        ff(j, i+1, m-i-1) {
            s += grid[i][j];
        }
        ff(j, i+1, n-i-1) {
            s+= grid[j][m-1-i];
        }
        fb(j, m-2-i, i) {
            s += grid[n-1-i][j];
        }
        fb(j, n-2-i, i) {
            s += grid[j][i];
        }
        s += s.substr(0, 3);
        debug(s);
        ff(j, 0, s.length()-4) {
            // compare string
            if (s.substr(j, 4) == "1543") {
                ans++;
            }
        }
    }
    cout<<ans<<nl;
}

signed main() {
    fast();
    int tt = 1;
    cin>>tt;
    while (tt--) {
        cerr<<"Test case: "<<tt<<nl;
        solve();
    }
}