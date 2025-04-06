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
	in(n);
	inVec(a, n);
	inVec(b, n);
	map<int, vector<int>> bmp;
	ff(i, 0, n-1) {
		bmp[b[i]].push_back(i+1);
	}
	map<int, pair<vector<int>,pair<vector<int>,vector<int>>>> bdt;
	loop(e, bmp) {
		auto& l = e.second;
		sort(l.begin(), l.end());
		vector<int> pre(l.size()+1, 0);
		ff(i, 0, l.size()-1) pre[i+1] = pre[i]+l[i];
		vector<int> suf(l.size()+1, 0);
		fb(i, l.size()-1, 0) suf[i] = suf[i+1] + (n+1-l[i]);
		bdt[e.first] = {l, {pre, suf}};
	}
	
	int sm = 0; 
	ff(i, 0, n-1) {
		if(a[i] == b[i]) {
			int c = (int)i*(i+1)/2 + (int)(n-i-1)*(n-i)/2;
			sm += c;
		}
	}
	
	int sm2 = 0;
	ff(i, 0, n-1) {
		int x = a[i];
		if(bdt.find(x) == bdt.end()) continue;
		const auto& l = bdt[x].first; 
		const auto& pre = bdt[x].second.first;
		const auto& suf = bdt[x].second.second;
		int k = min(i+1, n-i), pos_k = upper_bound(l.begin(), l.end(), k) - l.begin();
		int sm_p1 = pre[pos_k];
		int pos_i = upper_bound(l.begin(), l.end(), i+1) - l.begin();
		int cnt_p2 = pos_i - pos_k;
		int sm_p2 = (int)(n-i)*cnt_p2;
		int t = n-i;
		int lwr = i+2, upp = t-1, cnt_p3 = 0;
		if(lwr<=upp) {
			int pl = lower_bound(l.begin(),l.end(), lwr)-l.begin();
			int ph = upper_bound(l.begin(),l.end(), upp)-l.begin();
			cnt_p3 = ph-pl;
		}
		int sm_p3 = (int)(i+1)*cnt_p3;
		
		int pos_T = lower_bound(l.begin(), l.end(), t) - l.begin();
        int pos_i_l = upper_bound(l.begin(), l.end(), i+1) - l.begin();
        int start_idx = max(pos_T, pos_i_l);
        int sm_p4 = suf[start_idx];

        int total_contribution = sm_p1 + sm_p2 + sm_p3 + sm_p4;
        sm2 += total_contribution;
	}
	int total = sm+sm2;
	cout<<total<<nl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout<<fixed<<setprecision(12);
    int tt = 1;
    // cin>>tt;
    while (tt--) solve();
}

