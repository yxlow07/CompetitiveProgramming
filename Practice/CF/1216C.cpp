// Author: Yu Xuan
// Created On: 29 10 2024 - 17:43:23
// File: 1216C
// Link: https://codeforces.com/contest/1216/problem/C

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

bool ok(int &x, int &y, Rectangle &b1, Rectangle &b2) {
    return !(b1.leftBottom.x <= x && b1.rightTop.x >= x && b1.leftBottom.y <= y && b1.rightTop.y >= y) && !(b2.leftBottom.x <= x && b2.rightTop.x >= x && b2.leftBottom.y <= y && b2.rightTop.y >= y);
}

void solve() {
    vector<Rectangle> rects(3); int x1, y1, x2, y2;
    ff(i, 0, 2) {
        cin>>x1>>y1>>x2>>y2;
        rects[i].leftBottom.x = x1*2, rects[i].rightTop.x = x2*2;
        rects[i].leftBottom.y = y1*2, rects[i].rightTop.y = y2*2;
    }
    // Loop through white rectangle -> rects[0]
    ff(i, rects[0].leftBottom.x, rects[0].rightTop.x) {
        if (ok(i, rects[0].rightTop.y, rects[1], rects[2]) || ok(i, rects[0].leftBottom.y, rects[1], rects[2])) {
            yes
            ret;
        }
    }
    ff(i, rects[0].leftBottom.y, rects[0].rightTop.y) {
        if (ok(rects[0].rightTop.x, i, rects[1], rects[2]) || ok(rects[0].leftBottom.x, i, rects[1], rects[2])) {
            yes
            ret;
        }
    }
    no;
}

signed main() {
    fast();
    int tt = 1;
//    cin>>tt;
    while (tt--) {
        solve();
    }
}