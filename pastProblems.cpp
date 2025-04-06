#include<bits/stdc++.h>

#define int long long
#define vll vector<ll>
#define ll unsigned long long
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define mci map<char, int>

#define inputvec(arr) for(auto &a: arr) {cin >> a;}
#define outputvec(arr) for(auto &a: arr) {cout << a << " ";}
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

struct Point { int x, y; };
struct Rectangle { Point leftBottom, rightTop; };
using namespace std;

const int MOD = 1e9+7;
const int inf = 1e18;
int t=1;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void kattisMagicalCows() {
    int c, n, m, maxq = 0;
    cin>>c>>n>>m;
    int queries[m], initial[n];
    ff(i, 0, n-1) cin>>initial[i];
    ff(i, 0, m-1) {
        cin>>queries[i];
        maxq = max(maxq, queries[i]);
    }

    int dp[maxq+1][c+1];
    initDp(dp, 0);

    ff(i, 0, n-1) dp[0][initial[i]]++;

    ff(i, 0, maxq-1) { // this is <= not <
        ff(j, 1, c) {
            if (j<=(c/2)) dp[i+1][j*2] += dp[i][j]; // Double if does not exceed c
            else dp[i+1][j] += 2*dp[i][j]; // Double the same farm if exceed c
        }
    }

    ff(i, 0, m-1) {
// Output sum of farms
        int sum = 0;
        loop(f, dp[queries[i]]) sum += f;
        cout<<sum<<nl;
    }
}

void mco1() {
    int n, m, T;
    cin >> n >> m >> T;
    string s;
    cin >> s;

//    if (n==1) {
//        ff(i, 1, m) {
//            int y = i;
//            ff(k, 0, T-1) {
//                if (s[k] == 'W' && y > 1) y--;
//                else if (s[k] == 'E' && y < m) y++;
//            }
//            cout<<y-1<<" ";
//        }
//        ret;
//    }

    int dx = 0, dy = 0;
    ff(i, 0, T-1) {
        if (s[i] == 'N') dx--;
        if (s[i] == 'S') dx++;
        if (s[i] == 'W') dy--;
        if (s[i] == 'E') dy++;
    }
    cout<<"Dx="<<dx<<", Dy="<<dy<<nl;

    ff(i, 1, n) {
        ff(j, 1, m) {
            int x = i, y = j;
            if (i == 1 || j == 1) {
                ff(k, 0, T-1) {
                    if (s[k] == 'N' && x > 1) x--;
                    if (s[k] == 'S' && x < n) x++;
                    if (s[k] == 'W' && y > 1) y--;
                    if (s[k] == 'E' && y < m) y++;
                }
            }
            cout<<"("<<x<<","<<y<<") ";
//            cout<<(x-1)*m+(y-1)<<" ";
        }
        cout<<nl;
    }
}

int mco2solve(string s, vi power) {
    int n = power.size();
    int dead = 0;

    bool alive[n];
    int to_attack[n];

    ff(i, 0, n-1) {
        alive[i] = true;
        if (s[i] == '0') to_attack[i] = i-1;
        else to_attack[i] = i+1;
    }

    int alive_cnt = n;
    int prev_alive_cnt = 0;
    int target;

    while (alive_cnt != prev_alive_cnt) {
        prev_alive_cnt = alive_cnt;
        ff(i, 0, n-1) {
            if (alive[i]) {
                // Check who am i going to attack
                target = to_attack[i];
                if (target >= 0 && target < n) {
                    if (alive[target]) {
                        if (power[target] < power[i]) {
                            alive[target] = false;
                            alive_cnt--;
                            to_attack[i] += (s[i] == '0' ? -1 : 1);
                        }
                    }
                }
            }
        }
    }

    ret alive_cnt;
}

int32_t mco2() {
    fast();
//    cin>>t;
//    while (t--) solve();
    int n,q;
    cin>>n>>q;

    vi p(n, 0);

    ff(i, 0, n-1) cin>>p[i];

    string s;
    cin>>s;

    for(int i=0;i<q;i++){
        int x;
        cin>>x;

        x--;
        if(s[x] == '0') s[x] = '1';
        else s[x] = '0';

        cout<<solve(s, p)<<'\n';
    }
}

/**
 * Use upper_bound function to calculate this instead of this, calculates the maximal value to the left
 * @param arr
 * @param sz
 * @param num
 * @return
 */
int closest_binary_search(const int arr[], int sz, int num) {
    int left = 0, right = sz-1, ans = -1;

    while (left <= right) {
        int mid = left + (right-left)/2;

        if (arr[mid] <= num) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    ret ans != -1 ? ans+1 : 0;
}

/**
 * Use lower_bound - a.begin() +1 to find closest to the right, aka minimal value that is larger than num
 * @param arr
 * @param sz
 * @param num
 * @return
 */
int closest_binary_search(vi &arr, int sz, int num) {
    int left = 0, right = sz-1, ans = -1;

    while (left <= right) {
        int mid = left + (right-left)/2;

        if (arr[mid] >= num) {
            right = mid-1;
            ans = mid;
        } else {
            left = mid+1;
        }
    }
    ret ans != -1 ? ans+1 : sz+1;
}

/**
 * https://atcoder.jp/contests/abc399/tasks/abc399_f
 * 
 * Learn how to use math using grok
 */

 const int mod = 998244353;

int modinv(int a, int m) {
    int x0 = 0, x1 = 1, m0 = m, temp;
    if (m == 1) return 0;
    while (a > 1) {
        int q = a / m;
        temp = m;
        m = a % m, a = temp;
        temp = x0;
        x0 = x1 - q * x0;
        x1 = temp;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

void solve() {
    vi inv(11);
    ff(i, 1, 10) {
        inv[i] = modinv(i, mod);
    }
    in2(n,k);
    inVec(a, n);
    vi pre(n+1, 0);
    ff(i, 0, n-1) {
        pre[i+1] = (pre[i] + a[i]) % mod;
    }
    vector<vi> pw(k+1, vi(n+1, 0));
    ff(i, 1, n) {
        pw[0][i] = 1;
        ff(j, 1, k) {
            pw[j][i] = (pw[j-1][i] * pre[i]) % mod;
        }
    }
    vvi cum(k+1, vi(n+1, 0));
    ff(i, 1, k) {
        ff(j, 1, n) {
            cum[i][j] = (cum[i][j-1] + pw[i][j]) % mod;
        }
    }
    vi binom(k+1, 1);
    ff(i, 1, k) binom[i] = (binom[i-1] * (k-i+1) % mod * inv[i]) % mod;
    int ans = 0ll;
    ff(i, 1, n) {
        int tmp = (i * pw[k][i]) % mod;
        ff(j, 1, k) {
            int coeff = (binom[j] * (j % 2 ? mod - 1 : 1)) % mod;
            if (coeff < 0) coeff += mod;
            int term = (coeff * pw[k-j][i] % mod * cum[j][i-1]) % mod;
            tmp = (tmp + term) % mod;
        }
        ans = (ans + tmp) % mod;
    }
    cout<<ans<<nl;
}

void noiph2025p1() {
    in(n);
    int xmin = LLONG_MAX, xmax = LLONG_MIN;
    int ymin = LLONG_MAX, ymax = LLONG_MIN;
    int summin = LLONG_MAX, summax = LLONG_MIN;
    int diffmin = LLONG_MAX, diffmax = LLONG_MIN;

    ff(i, 0, n-1) {
        in2(a,b);
        xmin = min(xmin, a);
        xmax = max(xmax, a);
        ymin = min(ymin, b);
        ymax = max(ymax, b);
        summin = min(summin, a+b);
        summax = max(summax, a+b);
        diffmin = min(diffmin, b-a);
        diffmax = max(diffmax, b-a);
    }

    double ans1 = max(xmax-xmin, ymax-ymin);
    double ans2 = max((double)summax-summin, (double)diffmax-diffmin);
    cout<<min(ans1*ans1, ans2*ans2/2.0);
}

void abc400d() {
    in2(h,w);
    vector<string> grid(h);
    ff(i, 0, h-1) cin>>grid[i];
    in4(x1, y1, x2, y2);
    x1--; y1--; x2--; y2--;
    vvi dist(h, vi(w, INT_MAX));
    dist[x1][y1] = 0;

    deque<pii> dq;
    dq.push_back({x1, y1});

    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!dq.empty()) {
        // auto [x, y] = dq.front();
        int x = dq.front().fi, y = dq.front().se;
        dq.pop_front();
        int k = dist[x][y];
        for (auto & dir : directions) {
            int dx = dir.fi, dy = dir.se;
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (grid[nx][ny] != '.') continue;
            if (k < dist[nx][ny]) {
                dist[nx][ny] = k;
                dq.push_front({nx, ny});
            }
        }

        ff(dx, -2, 2) {
            ff(dy, -2, 2) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (k + 1 < dist[nx][ny]) {
                    dist[nx][ny] = k + 1;
                    dq.push_back({nx, ny});
                }
            }
        }
    }
    int finaldist = dist[x2][y2];
    if (finaldist == INT_MAX) {
        cout << -1 << nl;
        return;
    } 
    cout << finaldist << nl;
}