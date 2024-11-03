// Author: Yu Xuan
// Created On: 18 09 2024 - 11:31:20
// File: b

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vll vector<ll>
#define ll unsigned long long
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
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
#define loop(a, b) for (auto &a : b)
#define no cout << "No" << '\n';
#define yes cout << "Yes" << '\n';
#define negative cout << "-1" << '\n';
#define nl '\n'
#define all(x) x.begin(), x.end()
#define initDp(dp, val) memset(dp, val, sizeof dp);
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
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if (!file.empty()) { (void) !freopen((file + ".in").c_str(), "r", stdin); (void) !freopen((file + ".out").c_str(), "w", stdout); }
    #ifndef ONLINE_JUDGE
        string current_path = filesystem::current_path().string();
        freopen((current_path+"/inp.txt").c_str(), "r", stdin);
        freopen((current_path+"/out.txt").c_str(), "w", stdout);
        freopen((current_path+"/err.txt").c_str(), "w", stderr);
    #endif
}
int add(int x, int y) { return (x += y) >= MOD ? x - MOD : x; }
int mul(int x, int y) { return x * 1ll * y % MOD; }
int sum(vi a, int init = 0LL) { return accumulate(all(a), init); }
int sum(int arr[], int sz, int init = 0LL) { return accumulate(arr, arr + sz, init); }
int pair_sort_first(const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; }
int first_two_digits(int n) { int n1 = n, n2 = n; while (n) { n2 = n1; n1 = n; n /= 10; } return n2; }
int remove_first_n_digits(int num, int n) { string numStr = to_string(num); if (numStr.length() <= n) return 0; else return stol(numStr.substr(n), nullptr, 10); }
bool overlap(int a1, int a2, int b1, int b2) { return max(a1, a2) >= min(b1, b2) && max(b1, b2) >= min(a1, a2); }
int calcVolume(int a1, int a2, int b1, int b2) { return min(max(a1, a2), max(b1, b2)) - max(min(a1, a2), min(b1, b2)); }
vector<int> calculateSieve(int n) { vector<int> sieve(n+1, 0), result(n+1, 0); for (int i = 2; i <= n; i++) if (sieve[i] == 0) for (int j = 1; j*i <= n; j++) if (sieve[i*j] == 0) sieve[i*j] = i; for (int i = 2; i <= n; i++) sieve[i] = sieve[i/sieve[i]] + 1, result[i] = result[i-1] + sieve[i]; return result; }
template<class T> inline bool dpmax(T& a, T b) { if (a<b) {a=b; ret true;} ret false; }
template<class T> inline bool dpmin(T& a, T b) { if (a>b) {a=b; ret true;} ret false; }

signed main() {
    fast();
    int tt = 1;
//    cin>>tt;
    while (tt--) {
        int n, m; cin>>n>>m; bool family[n]; int k; char g;
        ff(i, 0, n-1) family[i] = false;
        ff(i, 0, m-1) {
            cin>>k>>g;
            if (family[k-1] || g == 'F') {
                cout<<"No"<<nl;
            } else {
                family[k-1] = (g == 'M');
                cout<<"Yes"<<nl;
            }
        }
    }
}