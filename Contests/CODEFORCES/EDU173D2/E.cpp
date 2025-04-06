// Author: Yu Xuan
// Created On: 24 12 2024 - 23:53:58
// File: E
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

bool can_transform_AND_then_OR(int n, int m, const vector<vector<int>> &A, const vector<vector<int>> &B) {
    // Initialize row masks to all bits set and column masks to 0
    vector<int> R(n, (1LL << 31) - 1);
    vector<int> C(m, 0);

    // Iterate through each bit position
    for(int bit = 0; bit < 31; bit++) {
        // First pass: Handle B[i][j] == 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if( ((B[i][j] >> bit) & 1) == 0 ) {
                    // C[j] bit must be 0
                    C[j] &= ~(1LL << bit);
                    // If A[i][j] has bit set, R[i] bit must be 0
                    if( ((A[i][j] >> bit) & 1) == 1 ) {
                        R[i] &= ~(1LL << bit);
                    }
                }
            }
        }

        // Second pass: Handle B[i][j] == 1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if( ((B[i][j] >> bit) & 1) == 1 ) {
                    if( ((A[i][j] >> bit) & 1) == 0 ) {
                        // C[j] bit must be 1 to set this bit
                        C[j] |= (1LL << bit);
                    }
                }
            }
        }

        // Third pass: Ensure that for B[i][j] ==1 and A[i][j]==1, either R[i] or C[j] has the bit set
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if( ((B[i][j] >> bit) & 1) == 1 && ((A[i][j] >> bit) & 1) ==1 ) {
                    if( ((C[j] >> bit) & 1) == 0 && ((R[i] >> bit) & 1) == 0 ) {
                        // Cannot satisfy the condition
                        return false;
                    }
                }
            }
        }
    }

    // After setting R and C, verify the transformation
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int transformed = (A[i][j] & R[i]) | C[j];
            if(transformed != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Helper function to check transformation by performing OR on columns then AND on rows
bool can_transform_OR_then_AND(int n, int m, const vector<vector<int>> &A, const vector<vector<int>> &B) {
    // Initialize column masks to 0 and row masks to all bits set
    vector<int> C(m, 0);
    vector<int> R(n, (1LL << 31) - 1);

    // Iterate through each bit position
    for(int bit = 0; bit < 31; bit++) {
        // First pass: Handle B[i][j] == 1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if( ((B[i][j] >> bit) & 1) == 1 ) {
                    if( ((A[i][j] >> bit) & 1) == 0 ) {
                        // C[j] bit must be 1 to set this bit
                        C[j] |= (1LL << bit);
                    }
                    // R[i] bit must be 1 to preserve or set this bit
                    R[i] |= (1LL << bit);
                }
            }
        }

        // Second pass: Handle B[i][j] == 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if( ((B[i][j] >> bit) & 1) == 0 ) {
                    // If A[i][j] has bit set or C[j] has bit set, then R[i] must unset this bit
                    if( ((A[i][j] >> bit) & 1) == 1 || ((C[j] >> bit) & 1) == 1 ) {
                        R[i] &= ~(1LL << bit);
                    }
                }
            }
        }
    }

    // After setting R and C, verify the transformation
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int transformed = (A[i][j] | C[j]) & R[i];
            if(transformed != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> B(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> B[i][j];
        }
    }

    // Check both transformation orders
    bool and_then_or = can_transform_AND_then_OR(n, m, A, B);
    bool or_then_and = can_transform_OR_then_AND(n, m, A, B);

    if(and_then_or || or_then_and) {
        cout << "Yes" << nl;
    }
    else {
        cout << "No" << nl;
    }
}

signed main() {
    fast();
    int tt = 1; 
    cin>>tt;
    while (tt--) solve();
}