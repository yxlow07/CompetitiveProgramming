//#include "iostream"
//#include "bits/stdc++.h"
//
//typedef long long ll;
//
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
////    int max = 0;
//    ll n, k; cin >> n >> k;
//    ll a[n], b[n];
//
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//
//    for (int i = 0; i < n; i++) {
//        cin >> b[i];
////        int val = b[i] / a[i];
////
////        // Find the minimum value
////        if (i == 0) {
////            max = val;
////        } else {
////            if (max < val) {
////                max = val;
////            }
////        }
//    }
//    ll l = 0, r=3e9;
//    while(r-l>1) {
//        ll mid = (l+r)/2;
//        ll val = 0;
//        for (int i = 0; i < n; i++) {
//            val += max((ll)0, mid*a[i]-b[i]);
//            if (val > k) break;
//        }
//        if (val <= k) {
//            l = mid;
//        } else {
//            r = mid;
//        }
//    }
//    cout << l << "\n";
//
////    for (int i = max; i > 0; i--) {
////        int powder_needed = 0;
////        for (int j = 0; j < n; j++) {
////            c[j] = i * a[j];
////            if (c[i] > b[i]) {
////                powder_needed += (c[i] - b[i]);
////            }
////        }
////        if (powder_needed < k) {
////            cout << i << " ";
////        }
////    }
//    return 0;
//}