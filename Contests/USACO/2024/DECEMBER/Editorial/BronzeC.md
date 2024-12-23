# Problem 3: It's Mooin' Time

Editorial written by: <u>[yxlow07](https://github.com/yxlow07/)</u>

Problem Details: USACO DECEMBER 2024 BRONZE PROBLEM 3

## Problem Recap:

If you are allowed to change one character in a string with length `N` to find `moo` with at least `F` occurrences, print it out in lexicographical order. A definition of a `moo` is `1` occurrence of a letter followed by `2` occurrences of a *different* letter.

## Naive Solution:

For each substring of length `3`, check if it forms a `moo` by the definition. Count occurrences of each valid `moo`. Consider each possible corrupted version of the string by changing one character at a time. Print all `moo` that appear at least `F` times after sorting with built-in sort function.

Time Complexity: `O(25 N^2)`. Given `N` goes up to `20000`, worst case scenario is that the code will run for `10,000,000,000` `(10 million)` iterations which most certainly results in `TLE`

## Observations:

The slow part is **rechecking** for the count of `moo` in the string which increases the order by `1`. If it is in constant time, `O(25N)` can definitely pass.

## Solution:

First, loop through the string to find the occurrences of `moo` by using a `unordered_map<string, int>` to store the number of occurrences so lookup would be `O(1)`.  Then, calculate the number of *possible* creations of new `moo`.

By looping through all possible `moo` -> `25*26=650` pairs will only needed to be considered. There are 3 cases for the `count`:

1. `count > f`: increment answer by 1 since you can modify 1 of it into another `moo` without making it `< f`
2. `count == f`: check if it covers all of the `s`. If it does, that means 1 modification will break it and we should not increase the answer and vice-versa.
3. `count == f-1`: check if 1 modification can result in the string, if it can, increment answer by 1

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

bool isValidMoo(string s) {
    return s[0] != s[1] && s[1] == s[2];
}

void solve() {
    int n,f; cin>>n>>f; string S,t; cin >> S;
    vector<string> possible; 
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    ff(i, 0, 25) {
        ff(j, 0, 25) {
            if (i == j) continue;
            possible.push_back(string(1, alphabets[i])+string(2, alphabets[j]));
        }
    }

    unordered_map<string, int> moo;
    unordered_map<string, vector<int>> moo_position;
    vector<unordered_set<string>> moo_position_spanned(n);
    for (int i = 0; i < n - 2; ++i) {
        t = S.substr(i, 3);
        if (isValidMoo(t)) {
            moo[t]++, moo_position[t].push_back(i), moo_position_spanned[i].insert(t);
            moo_position_spanned[i + 1].insert(t);
            moo_position_spanned[i + 2].insert(t);
        }
    }
    unordered_map<string, unordered_set<int>> covered_positions;
    // No modifications
    loop(m, possible) {
        unordered_set<int> positions;
        loop(p, moo_position[m]) {
            positions.insert(p), positions.insert(p+1);
            positions.insert(p+2);
        }
        covered_positions[m] = positions;
    }
    // One modification
    unordered_map<string, vector<int>> maybe;
    for (int i = 0; i < n - 2; ++i) {
        t = S.substr(i, 3);
        ff(j, 0, 2) {
            char ori = t[j];
            loop(c, alphabets) {
                if (c == ori) continue;
                t[j] = c;
                if (isValidMoo(t)) {
                    maybe[t].push_back(i);
                }
            }
            t[j] = ori;
        }
    }
    unordered_set<string> valid;
    loop(m, possible) {
        int count = moo[m];
        if (count > f) valid.insert(m);
        else if (count == f) {
            if (covered_positions[m].size() < n) {
                valid.insert(m);
            }
        } else if (count == f-1) {
            loop(start, maybe[m]) {
                if (covered_positions[m].find(start) == covered_positions[m].end() &&
                    covered_positions[m].find(start + 1) == covered_positions[m].end() &&
                    covered_positions[m].find(start + 2) == covered_positions[m].end()) {
                    valid.insert(m);
                    break;
                }
            }
        }
    }
    vector<string> svalid(valid.begin(), valid.end());
    sort(svalid.begin(), svalid.end());
    cout << svalid.size() << nl;
    loop(m, svalid) cout << m << nl;
}

signed main() {
    solve();
}
```
