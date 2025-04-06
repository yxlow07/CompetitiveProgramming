// Author: Yu Xuan
// Created On: 24 12 2024 - 22:31:10
// File: B
// Link: 

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
    int n,d; cin>>n>>d; set<int> ans; ans.insert(1);
    // Given number d repeats for n! times, which of 1,3,5,7,9 can divide the number
    // Case 1: 5
    if (d == 5 || d == 0) ans.insert(5);
    // Case 2: 3
    if (d % 3 == 0 || n >= 3) ans.insert(3);
    // Case 3: 7
    if (d % 7 == 0 || n >= 3) ans.insert(7);
    // Case 4: 9
    if (d % 9 == 0 || (n >= 6 || (n == 2 && d%9 == 0))) ans.insert(9);
    else if (3 <= n && n < 6 && d % 3 == 0) ans.insert(9);
    loop(c, ans) cout<<c<<" ";
    cout<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}