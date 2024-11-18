// Author: Yu Xuan
// Created On: 16 11 2024 - 22:34:38
// File: 6
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
    if (!file.empty()) { (void) !freopen((file + ".in").c_str(), "r", stdin); (void) !freopen((file + ".out").c_str(), "w", stdout); }
    #ifndef ONLINE_JUDGE
        string current_path = filesystem::current_path().string();
        freopen((current_path+"/inp.txt").c_str(), "r", stdin);
        freopen((current_path+"/out.txt").c_str(), "w", stdout);
        freopen((current_path+"/err.txt").c_str(), "w", stderr);
    #endif
}

const int MOD = 998244353;

vector<vector<int>> matrix_mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = 4;
    vector<vector<int>> res(n, vector<int>(n, 0));
    ff(i, 0, n-1) {
        ff(k, 0, n-1) {
            if (a[i][k]) {
                ff(j, 0, n-1) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
    }
    return res;
}

vector<vector<int>> matrix_pow(vector<vector<int>> &a, int b) {
    int n = 4;
    vector<vector<int>> res(n, vector<int>(n, 0));
    ff(i, 0, n-1) res[i][i] = 1;
    while (b) {
        if (b & 1) res = matrix_mul(res, a);
        a = matrix_mul(a, a);
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k; cin>>n>>k; string s; cin>>s;
    int s00 = 0, s01 = 0, s10 = 0, s11 = 0;
    ff(i, 1, n-1) {
        char a = s[i - 1];
        char b = s[i];
        int contrib = 1LL * i * (n - i);
        if (a == '0' && b == '0') s00 += contrib, s00 %= MOD;
        else if (a == '0' && b == '1') s01 += contrib, s01 %= MOD;
        else if (a == '1' && b == '0') s10 += contrib, s10 %= MOD;
        else if (a == '1' && b == '1') s11 += contrib, s11 %= MOD;
    }

    vector<int> s0 = {s00, s01, s10, s11};
    vector<vector<int>> transformation = {
        {2, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 1, 0}
    };

    vector<vector<int>> mk = matrix_pow(transformation, k);
    vector<int> sk(4, 0);
    ff(i, 0, 3) {
        ff(j, 0, 3) {
            sk[i] += mk[i][j] * s0[j];
            sk[i] %= MOD;
        }
    }

    cout<<(sk[0]+sk[3])%MOD<<nl;
}

signed main() {
    fast();
    int tt = 1; //cin>>tt;
    while (tt--) solve();
}