// Author: Yu Xuan
// Created On: 28 12 2024 - 22:36:18
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
    int n; cin>>n; vector<pair<int,int>> range(n); int mx_x = -1;
    loop(r, range) {
        cin>>r.first>>r.second;
        mx_x = max(mx_x, r.first);
    }
    vector<int> cnt(mx_x+2, 0);
    ff(i, 0, n-1) {
        if (range[i].first == range[i].second) cnt[range[i].first]++;
    }
    vector<int> allowed(mx_x+2, 0);
    allowed[0] = 0;
    ff(i, 1, mx_x) {
        allowed[i] = allowed[i-1] + (cnt[i] == 0 ? 1 : 0);
    }
    string s;
    ff(i, 0, n-1) {
        if (range[i].first == range[i].second) {
            s += (cnt[range[i].first] == 1 ? '1' : '0');
        } else {
            int li = max(range[i].first, 1LL), ri = min(range[i].second, mx_x);
            if (li > ri) s+='0';
            else {
                int cnt_allowed = allowed[ri] - ((li >1) ? allowed[li -1] : 0);
                if(cnt_allowed >=1) s += '1';
                else s += '0';
            }
        }
    }
    cout<<s<<nl;
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}