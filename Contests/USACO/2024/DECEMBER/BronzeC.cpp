// Author: Yu Xuan
// Created On: 14 12 2024 - 13:53:58
// File: BronzeC
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
bool isValidMoo(string s) {
    return s[0] != s[1] && s[1] == s[2];
}

void solve() {
    int n,f; cin>>n>>f; string S,t; cin >> S;
    vector<string> possible; string alphabets = "abcdefghijklmnopqrstuvwxyz";
    ff(i, 0, 25) {
        ff(j, 0, 25) {
            if (i == j) continue;
            possible.push_back(string(1, alphabets[i])+string(2, alphabets[j]));
        }
    }

    unordered_map<string, int> moo;
    unordered_map<string, vector<int>> moo_position;
    vector<unordered_set<string>> moo_position_spanned(n);
    for (int i = 0; i < n - 2; ++i) {
        t = S.substr(i, 3);
        if (isValidMoo(t)) {
            moo[t]++, moo_position[t].push_back(i), moo_position_spanned[i].insert(t), moo_position_spanned[i + 1].insert(t), moo_position_spanned[i + 2].insert(t);
        }
    }
    unordered_map<string, unordered_set<int>> covered_positions;
    // No modifications
    loop(m, possible) {
        unordered_set<int> positions;
        loop(p, moo_position[m]) {
            positions.insert(p), positions.insert(p+1), positions.insert(p+2);
        }
        covered_positions[m] = positions;
    }
    // One modification
    unordered_map<string, vector<int>> maybe;
    for (int i = 0; i < n - 2; ++i) {
        t = S.substr(i, 3);
        ff(j, 0, 2) {
            char ori = t[j];
            loop(c, alphabets) {
                if (c == ori) continue;
                t[j] = c;
                if (isValidMoo(t)) {
                    maybe[t].push_back(i);
                }
            }
            t[j] = ori;
        }
    }
    unordered_set<string> valid;
    loop(m, possible) {
        int count = moo[m];
        if (count > f) valid.insert(m);
        else if (count == f) {
            if (covered_positions[m].size() < n) valid.insert(m);
        } else if (count == f-1) {
            loop(start, maybe[m]) {
                if (covered_positions[m].find(start) == covered_positions[m].end() &&
                    covered_positions[m].find(start + 1) == covered_positions[m].end() &&
                    covered_positions[m].find(start + 2) == covered_positions[m].end()) {
                    valid.insert(m);
                    break;
                }
            }
        }
    }
    vector<string> svalid(valid.begin(), valid.end());
    sort(svalid.begin(), svalid.end());
    cout << svalid.size() << nl;
    loop(m, svalid) cout << m << nl;
}

signed main() {
    fast();
    int tt = 1; 
//    cin>>tt;
    while (tt--) solve();
}