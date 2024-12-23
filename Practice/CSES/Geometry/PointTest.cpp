// Author: Yu Xuan
// Created On: 19 12 2024 - 20:18:16
// File: PointLocationTest
// Link: https://cses.fi/problemset/task/2189

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
    int x1, x2, x3, y1, y2, y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
    // Case 1: They intersect, calculate area of the triangle == 0
    int area = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)), area1;
    if (area == 0) {
        cout<<"TOUCH"<<nl;
    } else {
        int m = (y2-y1) / (x2-x1);
        if (m > 0) {
            if (x2 > x1) swap(x1, x2), swap(y1, y2);
        } else {
            if (x1 > x2) swap(x1, x2), swap(y1, y2);
        }
        area1 = (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
        if (area1 > 0) {
            cout<<"LEFT"<<nl;
        } else {
            cout<<"RIGHT"<<nl;
        }
    }
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}