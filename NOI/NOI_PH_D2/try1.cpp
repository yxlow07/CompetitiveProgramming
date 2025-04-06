#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll m;
    cin >> n >> m;
    vector<string> cmp(n);
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2 >> cmp[i] >> x[i]; // "Is A [cmp] x?"
    }
    
    vector<uint64_t> r(n);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < n; i++) {
        r[i] = rng();
    }
    
    set<ll> C;
    for (int i = 0; i < n; i++) {
        if (cmp[i] == "<") C.insert(x[i]);
        else if (cmp[i] == "<=") C.insert(x[i] + 1);
        else if (cmp[i] == ">") C.insert(x[i] + 1);
        else if (cmp[i] == ">=") C.insert(x[i]);
        else if (cmp[i] == "==" || cmp[i] == "!=") {
            C.insert(x[i]);
            C.insert(x[i] + 1);
        }
    }
    
    vector<ll> change_points;
    for (ll c : C) {
        if (c >= 1 && c <= m) {
            change_points.push_back(c);
        }
    }
    
    vector<uint64_t> hashes;
    
    bool has_one = find(change_points.begin(), change_points.end(), 1) != change_points.end();
    if (change_points.empty() || change_points[0] > 1) {
        uint64_t h = 0;
        for (int i = 0; i < n; i++) {
            bool yes = false;
            if (cmp[i] == "<") yes = (1 < x[i]);
            else if (cmp[i] == "<=") yes = (1 <= x[i]);
            else if (cmp[i] == ">") yes = (1 > x[i]);
            else if (cmp[i] == ">=") yes = (1 >= x[i]);
            else if (cmp[i] == "==") yes = (1 == x[i]);
            else if (cmp[i] == "!=") yes = (1 != x[i]);
            if (yes) h ^= r[i];
        }
        hashes.push_back(h);
    }
    
    for (ll c : change_points) {
        uint64_t h = 0;
        for (int i = 0; i < n; i++) {
            bool yes = false;
            if (cmp[i] == "<") yes = (c < x[i]);
            else if (cmp[i] == "<=") yes = (c <= x[i]);
            else if (cmp[i] == ">") yes = (c > x[i]);
            else if (cmp[i] == ">=") yes = (c >= x[i]);
            else if (cmp[i] == "==") yes = (c == x[i]);
            else if (cmp[i] == "!=") yes = (c != x[i]);
            if (yes) h ^= r[i];
        }
        hashes.push_back(h);
    }
    
    sort(hashes.begin(), hashes.end());
    auto it = unique(hashes.begin(), hashes.end());
    hashes.resize(distance(hashes.begin(), it));
    ll num_valid = hashes.size();
    
    ll sum_narrow = m;
    cout << num_valid % MOD << " " << sum_narrow % MOD << endl;
    
    return 0;
}