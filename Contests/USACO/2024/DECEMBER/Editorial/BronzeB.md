# Problem 2: Farmer John's Cheese Block

Editorial written by: [yxlow07](https://github.com/yxlow07/)

Problem Details: USACO DECEMBER 2024 BRONZE PROBLEM 2

## Problem Recap:

Given a `NxNxN` block, execute `Q` queries, where each query removes a `1x1x1` block. After that, output the number of `1x1xN` blocks that can be formed using the gaps of the removed block.

## Naive Approach:

Loop through each query, for each query, remove the `1x1x1` block and iterate through the block to check if you can place a `1x1xN` block. This results in a time complexity of `O(Q N^3)` solution where we definitely know it will not work for problem's constraints.

## Observation:

Notice that we can place a `1x1xN` block if and only if we carve out one full **layer, column** or **row**. That means, coordinate compression. Also, as a sidenote, once a `1x1xN` block can be cut out, it can always be cut out. So, the answer is **strictly increasing.**

## Solution:

Let's initialize `x, y, z` with size `NxN` since it represents a whole face of the cube and initialize all as `0` at the start. For each query, update the number of times a block is carved at the position. E.g. `x[idx_carved]` and vice-versa. Then, increment `answer` if `x[idx_carved]` is equal to `N` *(carved N times so it is completely hollow)*

The time complexity is `O(Q)` since each query just needs a constant time to check if it has completely hollowed out and increment the `answer`

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

void solve() {
    int n, q, xo, yo, zo; cin>>n>>q; 
    vector<vector<int>> queries(q, vector<int>(3, 0));
    ff(i, 0, q-1) cin>>queries[i][0]>>queries[i][1]>>queries[i][2];
    vector<int> x(n*n, 0), y(n*n, 0), z(n*n, 0);
    int ans = 0;
    ff(i, 0, q-1) {
        xo = queries[i][0]; yo = queries[i][1]; zo = queries[i][2];
        int idx_x = yo * n + zo, idx_y = xo * n + zo, idx_z = xo * n + yo;
        x[idx_x]++; y[idx_y]++; z[idx_z]++;
        if (x[idx_x] == n) ans++;
        if (y[idx_y] == n) ans++;
        if (z[idx_z] == n) ans++;
        cout<<ans<<nl;
    }
}

signed main() {
    solve();
}
```
