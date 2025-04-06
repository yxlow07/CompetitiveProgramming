#include "bits/stdc++.h"
using namespace std;

pair<int, vector<int>> generate_random_vector_cpp(int max_length) {
     random_device rd; // Obtain a random number from hardware
     mt19937 gen(rd()); // Seed the generator
     uniform_int_distribution<> length_dist(1, max_length); // Distribution for length
     uniform_int_distribution<> value_dist(1, 10); // Distribution for values (1 to 10)

     int n = length_dist(gen); // Random length
     vector<int> v(n);
     for (int i = 0; i < n; ++i) {
          v[i] = value_dist(gen); // Random values
     }
     return {n, v};
}

vector<int> fas(int n, vector<int> v) {
     for (int i = 0; i < n; i++) {
          pair<int, int>maxn;
          for (int j = i; j < n; j++) {
               if (v[j] >= maxn.first) {
                    maxn.first = v[j];
                    maxn.second = j;
               }
          }
          if (v[i] != maxn.first) {
               v.erase(v.begin() + maxn.second);
               v.insert(v.begin() + i, maxn.first);
               break;
          }
     }
     stack<int>stk;
     for (int i = 0; i < n; i++) {
          while (stk.size() && v[i] > stk.top())stk.pop();
          stk.push(v[i]);
     }
     vector<int>ans;
     while (stk.size()) {
          ans.push_back(stk.top());
          stk.pop();
     }
     vector<int> returns;
     for (int j = ans.size() - 1; j >= 1; j--)returns.push_back(ans[j]);
     returns.push_back(ans[0]);
     return returns;
}

vector<int> brute(int n, vector<int> v) {
     vector<int>a;
     for (int i = 0; i < n; i++) {
          for (int j = i - 1; j >= 0; j--) {
               vector<int>arr = v;
               int temp = arr[i];
               arr.erase(arr.begin() + i);
               arr.insert(arr.begin() + j, temp);
               stack<int>stk;
               for (int i = 0; i < n; i++) {
                    while (stk.size() && arr[i] > stk.top())stk.pop();
                    stk.push(arr[i]);
               }
               vector<int>ans;
               while (stk.size()) {
                    ans.push_back(stk.top());
                    stk.pop();
               }
               reverse(ans.begin(), ans.end());
               if (ans > a)a = ans;
          }
     }
     vector<int> ans;
     for (int i = 0; i < a.size() - 1; i++) ans.push_back(a[i]);
     ans.push_back(a[a.size() - 1]);
     return ans;
}

int main() {
     for (int j = 0; j < 10; ++j) {
          auto data = generate_random_vector_cpp(10);
          int n = data.first; vector<int> v = data.second;
          auto time1start = chrono::high_resolution_clock::now();
          vector<int> a = fas(n, v);
          auto time1end = chrono::high_resolution_clock::now();
          auto time1 = chrono::duration_cast<chrono::nanoseconds>(time1end - time1start).count();
          auto time2start = chrono::high_resolution_clock::now();
          vector<int> b = brute(n, v);
          auto time2end = chrono::high_resolution_clock::now();
          auto time2 = chrono::duration_cast<chrono::nanoseconds>(time2end - time2start).count();
          if (a != b) {
               cout << "Failed" << endl;
               cout << "Input: " << n << endl;
               for (int i = 0; i < n; i++) cout << v[i] << " ";
               cout << endl << "Output: ";
               cout << endl;
               cout << "Expected: ";
               for (int i = 0; i < n; i++) cout << b[i] << " ";
               cout << endl;
               cout << "Got: ";
               for (int i = 0; i < n; i++) cout << a[i] << " ";
               cout << endl;
          }
          else cout << "Passed" << endl;
          // report time for function running
          cout << "Time for fas: " << time1 << " ns" << endl;
          cout << "Time for brute: " << time2 << " ns" << endl;
     }
     return 0;
}