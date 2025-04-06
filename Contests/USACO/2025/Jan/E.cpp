// Author: Yu Xuan

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define loop(a, b) for (auto &a : b)
#define nl '\n'
#define in(n) int n; cin>>n;
#define in2(n, m) int n, m; cin>>n>>m;
#define in3(n, m, k) int n, m, k; cin>>n>>m>>k;
#define in4(n, m, k, l) int n, m, k, l; cin>>n>>m>>k>>l;
#define in5(n, m, k, l, o) int n, m, k, l, o; cin>>n>>m>>k>>l>>o;
#define inVec(a, n) vector<int> a(n); loop(x, a) cin>>x;
#define inPii(a, n) vector<pair<int,int>> a(n); loop(x, a) { int p, q; cin>>p>>q; a.emplace_back(p, q); }

void solve() {
	in2(n, m); 
	inVec(a, n);
	vector<int> remainders(n);
	sort(a.begin(), a.end());
	ff(i, 0, n-1) remainders[i] = a[i] % m;
	int tgt = remainders[n/2], ans = 0, ans1 = 0;
	ff(j, 0, n-1) {
		int diff = abs(remainders[j]-tgt);
		ans += min(diff, m-diff);
	}
	tgt = remainders[(n-1)/2];
	ff(j, 0, n-1) {
		int diff = abs(remainders[j]-tgt);
		ans1 += min(diff, m-diff);
	}
	cout<<min(ans1, ans)<<nl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout<<fixed<<setprecision(12);
    int tt = 1;
    cin>>tt;
    while (tt--) solve();
}

