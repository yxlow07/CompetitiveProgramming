// Author: Yu Xuan
// Created On: 27 10 2024 - 22:22:05
// File: 2018Jan_1
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=783

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

bool covered(int x, int y, int x1, int y1, int x2, int y2) {
    // True if (x,y) is bounded by (x1,y1) and (x2,y2)
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    return x >= x1 && x <= x2 && y >= y1 && y < y2;
}

void solve() {
    // Billboard 1 -> to delete
    int x11, x12, y11, y12; cin>>x11>>y11>>x12>>y12;
    // Billboard 2 -> cow feed
    int x21, x22, y21, y22; cin>>x21>>y21>>x22>>y22;

    // Calculate covered corners
    int covered_corner = 0, area = (x12-x11) * (y12-y11);

    if (covered(x11, y11, x21, y21, x22, y22)) covered_corner++;
    if (covered(x11, y12, x21, y21, x22, y22)) covered_corner++;
    if (covered(x12, y11, x21, y21, x22, y22)) covered_corner++;
    if (covered(x12, y12, x21, y21, x22, y22)) covered_corner++;

    if (covered_corner <= 1) cout<<area;
    else if (covered_corner == 4) cout<<0;
    else {
        // Find intersection of rectangle
        int xTarpL = max(x11, x21), xTarpR = min(x12, x22), yTarpL = max(y11, y21), yTarpR = min(y12, y22);
        cout<<abs(area-(xTarpR-xTarpL) * (yTarpR-yTarpL));
    }
}

signed main() {
    fast();
    int tt = 1;
//    cin>>tt;
    while (tt--) {
        solve();
    }
}