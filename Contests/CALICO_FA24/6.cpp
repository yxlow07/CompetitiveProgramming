// Author: Yu Xuan
// Created On: 17 11 2024 - 07:59:34
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);
}
const int MAX_D = 2000000;
int phi_arr[MAX_D + 1];
long long cum_phi[MAX_D + 1];

void compute_totients() {
    // Initialize phi_arr where phi[k] = k
    for(int i = 0; i <= MAX_D; i++) phi_arr[i] = i;

    // Compute phi values
    for(int p = 2; p <= MAX_D; p++) {
        if(phi_arr[p] == p) { // p is prime
            for(int multiple = p; multiple <= MAX_D; multiple += p) {
                phi_arr[multiple] -= phi_arr[multiple] / p;
            }
        }
    }
}

// Function to compute cumulative sums of phi values.
void precompute_cumulative_phi() {
    cum_phi[0] = 0;
    cum_phi[1] = 0;
    for(int D = 2; D <= MAX_D; D++) {
        cum_phi[D] = cum_phi[D-1] + phi_arr[D];
    }
}

int find_D(long long N) {
    // Binary search over cum_phi[2...MAX_D]
    int left = 2, right = MAX_D;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(cum_phi[mid] < N){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

pair<int, int> find_coordinates(int N){
    // Find the Manhattan distance D
    int D = find_D(N);

    // Calculate the target position within D
    long long prev_cum = cum_phi[D-1];
    int target = N - prev_cum;
    int x = -1;
    int count = 0;
    for(int i = 1; i < D; i++){
        if(__gcd(i, (int)D) == 1){
            count++;
            if(count == target){
                x = i;
                break;
            }
        }
    }
    int y = D - x;
    return {x, y};
}

void solve() {
    int N;
    cin >> N;
    pair<int, int> coordinates = find_coordinates(N);
    cout << coordinates.first << " " << coordinates.second << nl;
}

//signed main() {
//    fast();
//    compute_totients();
//    precompute_cumulative_phi();
//    int tt = 1; cin>>tt;
//    while (tt--) solve();
//}

signed main() {
    auto start = chrono::high_resolution_clock::now();
    fast();
    compute_totients();
    precompute_cumulative_phi();
    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << "Time taken: " << time_taken << " ms" << '\n';
}
