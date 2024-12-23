# Problem 1: Roundabout Rounding

Editorial written by: [yxlow07](https://github.com/yxlow07/)

Problem Details: USACO DECEMBER 2024 BRONZE PROBLEM 1

## Problem Recap:

Given `N`, find how many numbers that differ when using *rounding* and *chain rounding* `1 <= N <= 1e9`

## Naive Approach:

Write a program that goes through 1 to `N` that does rounding on both numbers and keeps a counter of the number of different roundings.
Time Complexity: `O(log i)` for each number -> `O(n log i)` for `t` test cases.
Simple calculation can show that `1e9*1e5` (ignoring log i) will result in **TLE** error

## Observations:

*Chain rounding* will differ from *rounding* depending on its second to last digit, for example: `45` -> it will depend on `5`, `445` -> it will depend on `4`

## Optimised Approach

Using the above observation, notice that the only time rounding will be different would be is when the last digit rounds off by carrying forward to the next digit and et cetera.

> For example: 445 -> 450 -> 500

The solution is simply to precalculate the intervals of 45-49 (since from 50 onwards it rounds normally both ways), 445-499, ... Then, solve the question in `O(1)` time by reusing the precomputed result.

## Implementation:

```cpp
// Author: Yu Xuan  

#include <bits/stdc++.h>  
using namespace std;  
  
#define int long long  
#define ff(i,a,b) for(int i=a;i<=b;i++)  
#define fb(i,b,a) for(int i=b;i>=a;i--)  
#define loop(a, b) for (auto &a : b)  
#define nl '\n'  

vector<pair<int,int>> a;  
  
void solve() {  
    int n, l, r; cin>>n;  
    int count = 0;  
    loop(p, a) {  
        if (p.first > n) continue;  
        l = p.first, r = min(p.second, n);  
        if (l > r) continue;  
        count += r - l + 1;  
    }  
    cout<<count<<nl;  
}  
  
signed main() {  
    for (int P = 2; P <= 12; ++P) {  
        int power_P_minus_1 = pow(10, P - 1);  
        int numerator = 5 * (power_P_minus_1 - 1) + 8;  
        int ceil_div = numerator / 9;  
        int low = 5 * power_P_minus_1 - ceil_div;  
        int high = 5 * power_P_minus_1 - 1;  
        a.emplace_back(low, high);  
    }  
    int tt = 1;   
    cin>>tt;  
    while (tt--) solve();  
}
```
