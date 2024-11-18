// Author: Yu Xuan
// Created On: 17 11 2024 - 07:59:11
// File: 2
// Link: 

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define nl '\n'

void fast(const string &file = "") {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout<<fixed<<setprecision(12); 
}

void solve() {
    string n; cin>>n;
    map<char, int> mp, required;
    ff(i, 0, 25) {
        mp['a'+i] = 0;
        required['a'+i] = 0;
    }
    string s = "calico";
    loop(a, s) mp[a]++;
    map<char,vector<char>> rotatable;
    rotatable['n'] = {'c', 'u', 'z'}; rotatable['u'] = {'c', 'n'}, rotatable['c'] = {'n', 'u'};
    rotatable['h'] = {'i'}; rotatable['p'] = {'d'}; rotatable['m'] = {'w'}, rotatable['w'] = {'m'};
    rotatable['i'] = {'h'}; rotatable['d'] = {'p'}; rotatable['b'] = {'q'}, rotatable['q'] = {'b'};
    rotatable['z'] = {'n'};
    loop(c, n) c = tolower(c);
    loop(c, n) {
        if (mp[c] == 0) {
            // Find from rotating
            bool found = false;
            loop(r, rotatable) {
                if (r.first == c) {
                    loop(rot, r.second) {
                        if (mp[rot] > 0) {
                            found = true;
                            required[rot]++;
                            break;
                        }
                    }
                }
                if (found) break;
            }
            if (!found) {
                cout<<-1<<nl;
                return;
            }
        } else {
            required[c]++;
        }
    }
    int ans = 0;
    loop(r, required) {
        if (r.second > 0) {
            ans = max(ans, (r.second / mp[r.first]) + (r.second % mp[r.first] == 0 ? 0 : 1));
        }
    }
    cout<<ans<<nl;
}

signed main() {
    fast();
    int tt = 1; cin>>tt;
    while (tt--) solve();
}