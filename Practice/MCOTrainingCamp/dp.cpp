#include "bits/stdc++.h"
#include "vector"

using namespace std;
using i64 = long long;
typedef long long int lli;

int bits_manipulation() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--) {
        lli n; string s;
        vector<lli>v;

        cin >> n;
        cin >> s;

        lli z = 0;

        for (int j = 0; j < n; j++) {
            if (s[j] == '0') {
                z++;
                v.push_back(j);
            }
        }

        lli ans = 0;
        for (int i = 0; i < n; i++) {
            if (z < i + 1) {
                cout << "-1" << " ";
            } else {
                // index of last bit - current bit - position of the last 0
                ans += abs((n - 1) - i - v[v.size() - 1 - i]);
                cout << ans << " ";
            }
        }
        cout << endl;

    }

    return 0;

}

void frog_b() {
    int n, k;
    cin >> n >> k;
    vector<i64> h(n + 1);
    vector<i64> dp(n + 1, 1e9);
    dp[1] = 0;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int nx = 0; nx < i + k; nx++) {
            dp[nx] = min(dp[nx], dp[i] + abs(h[i] - h[nx]));
        }
    }

    cout << dp[n];
}

void minimise_coin() {
    lli n, x; cin >> n >> x;
    vector<i64> c(n+1);

    vector<i64> dp(x + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int w; cin >> w;
        for (int j = 0; j <= x; j++) {
            dp[j] = min(dp[j], (j-w > 0 ? dp[j-w] +1 : (int) 1e9));
        }
    }

    lli result = dp[x] == 1e9 ? -1 : dp[x];
    cout << result << endl;
}

void grid() {
    int n; cin >> n;
    const i64 MOD = 1e9+7;

    vector<vector<char>> grid(n+1, vector<char>(n+1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        if (grid[0][i] == '*') {
            break;
        }
        dp[0][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (grid[i][0] == '*') {
            break;
        }
        dp[i][0] = 1;
    }

    // Calculate the number of paths for each square
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;
}

typedef long long ll;
#define int long long

int32_t q3() {
    int q;
    cin >> q;
    while (q--) {
        int w, f, n;
        cin >> w >> f >> n;
        vector<int> s(n);
        int sum_s = 0;

        // Read monster strengths and calculate the total strength
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            sum_s += s[i];
        }

        // Initialize DP array
        vector<bool> dp(sum_s + 1);
        dp[0] = true;

        // Bottom-up DP to find achievable sums
        for (int i = 0; i < n; ++i) {
            for (int sum = sum_s; sum - s[i] >= 0; --sum) {
                dp[sum] = dp[sum] || dp[sum - s[i]];
            }
        }

        int ans = 2e9;

        // Iterate over achievable sums to find the minimum time
        for (int sum = 0; sum <= sum_s; ++sum) {
            if (dp[sum]) {
                ans = min(ans, max((sum + w - 1) / w, (sum_s - sum + f - 1) / f));
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

int32_t mainq1() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> sizes(n);
        for (int i = 0; i < n; ++i) {
            cin >> sizes[i];
        }

        vector<int> dp(n, 1);  // dp[i] represents the maximum length of beautiful arrangement ending at index i

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if ((i + 1) % (j + 1) == 0 && sizes[i] > sizes[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxBeautiful = *max_element(dp.begin(), dp.end());
        cout << maxBeautiful << endl;
    }

    return 0;
}

int32_t mainq12() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> sizes(n);
        for (int i = 0; i < n; ++i) {
            cin >> sizes[i];
        }

        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if ((i + 1) % (j + 1) == 0 && sizes[i] > sizes[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxBeautiful = *max_element(dp.begin(), dp.end());
        cout << maxBeautiful << endl;
    }

    return 0;
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> sizes(n);
        for (int i = 0; i < n; ++i) {
            cin >> sizes[i];
        }

        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0 && (i + 1) % (j + 1) == 0; --j) {
                if (sizes[i] > sizes[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxBeautiful = *max_element(dp.begin(), dp.end());
        cout << maxBeautiful << endl;
    }

    return 0;
}