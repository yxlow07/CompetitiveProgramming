//#include <iostream>
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int bs() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    int a[n], b[m];
//
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//
//    sort(a, a+n);
//
//    for (int i = 0; i < m; i++) {
//        cin >> b[i];
//        // Solving for b[i]
//        int l = -1, r = n;
//        while (r-l>1) {
//            int mid = (l+r)/2;
//            if (a[mid] <= b[i]) {
//                l = mid;
//            } else {
//                r = mid;
//            }
//        }
//        cout << r << " ";
//    }
//    return 0;
//}
    int main() {
        int n, k; cin >> n >> k;
        int a[n], b[k];

        for (int i = 0; i <n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i <n; i++) {
            cin >> b[i];
        }
}