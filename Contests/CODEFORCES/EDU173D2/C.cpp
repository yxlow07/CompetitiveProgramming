// Author: Yu Xuan
// Created On: 24 12 2024 - 22:31:15
// File: C
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

auto compute_subarray_sums(int start, int end, vector<int> a) -> vector<long long> {
    vector<int> sums;
    // Using prefix sums to compute all possible subarray sums
    vector<int> prefix(end - start + 2, 0);
    ff(i, start, end-1) prefix[i - start +1] = prefix[i - start] + a[i];
    ff(i, 0, end-start) {
        ff(j, i+1, end-start) {
            sums.push_back(prefix[j] - prefix[i]);
        }
    }
    return sums;
}

void solve() {
    int n; cin>>n; vector<int> a(n); int p = -1, x = -1;
    ff(i, 0, n-1) {
        cin>>a[i];
        if (abs(a[i]) != 1) p = i, x = a[i];
    }
    vector<int> ans; ans.push_back(0);
    if (p != -1) {
        if (p > 0) {
            vector<int> left = compute_subarray_sums(0, p, a);
            ans.insert(ans.end(), left.begin(), left.end());
        }
        if (p < n-1) {
            vector<int> right = compute_subarray_sums(p+1, n, a);
            ans.insert(ans.end(), right.begin(), right.end());
        }
        vector<int> left = {0}, right = {0}; int s = 0;
        fb(i, p-1, 0) {
            s += a[i];
            left.push_back(s);
        }
        s = 0;
        ff(i, p+1, n-1) {
            s += a[i];
            right.push_back(s);
        }
        loop(l, left) {
            loop(r, right) {
                ans.push_back(x+l+r);
            }
        }
    } else {
        int t = 0, mn_s = 0, mx_s = 0;
        loop(c, a) t += c, mn_s = min(mn_s, t), mx_s = max(mx_s, t);
        ff(i, mn_s, mx_s) ans.push_back(i);
        ans.push_back(0);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout<<ans.size()<<nl;
    loop(c, ans) cout<<c<<" ";
    cout<<nl;

}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}