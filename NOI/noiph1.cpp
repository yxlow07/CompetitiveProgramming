#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int MAXSUM = 200010;

int n, m;
map<int, int> ingredient_id; // Maps ingredient to id
int next_id = 0;
vector<int> L[MAXN], H[MAXN]; // Loved and hated ingredients per guest
vector<int> Love[MAXN], Hate[MAXN]; // Guests per ingredient id

// Union-Find
int parent[MAXN], sz[MAXN];
int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
}

// Conflict graph
vector<int> conflict[MAXN];
bool vis[MAXN];
int color[MAXN];

// Bitset for DP
bitset<MAXSUM> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // Input
    cin >> n >> m;
    set<int> hated_ingredients;
    vector<int> original_ingredients;
    for (int i = 0; i < m; i++) {
        int guest, ingredient;
        string opinion;
        cin >> guest >> opinion >> ingredient;
        guest--; // 0-based
        if (ingredient_id.find(ingredient) == ingredient_id.end()) {
            ingredient_id[ingredient] = next_id++;
            original_ingredients.push_back(ingredient);
        }
        int id = ingredient_id[ingredient];
        if (opinion == ":)") {
            L[guest].push_back(id);
            Love[id].push_back(guest);
        } else {
            H[guest].push_back(id);
            Hate[id].push_back(guest);
            hated_ingredients.insert(ingredient);
        }
    }
    
    // Find t1, t2 not in hated_ingredients
    int t1 = 1, t2 = 2;
    while (hated_ingredients.count(t1)) t1++;
    while (hated_ingredients.count(t2) || t2 == t1) t2++;
    
    // Initialize union-find
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    
    // Union guests
    for (int id = 0; id < next_id; id++) {
        for (size_t j = 1; j < Love[id].size(); j++) unite(Love[id][0], Love[id][j]);
        for (size_t j = 1; j < Hate[id].size(); j++) unite(Hate[id][0], Hate[id][j]);
    }
    
    // Build conflict graph and check impossibility
    for (int id = 0; id < next_id; id++) {
        if (!Love[id].empty() && !Hate[id].empty()) {
            int comp_L = find(Love[id][0]);
            int comp_H = find(Hate[id][0]);
            if (comp_L == comp_H) {
                cout << ">:( " << "\n";
                return 0;
            }
            conflict[comp_L].push_back(comp_H);
            conflict[comp_H].push_back(comp_L);
        }
    }
    
    // BFS on conflict graph
    vector<pair<int, int>> sums; // {left_sum, right_sum} per connected component
    for (int i = 0; i < n; i++) {
        if (parent[i] != i || vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        color[i] = 0;
        int left_sum = 0, right_sum = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            (color[u] == 0 ? left_sum : right_sum) += sz[u];
            for (int v : conflict[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    cout << ">:( " << "\n";
                    return 0;
                }
            }
        }
        sums.push_back({left_sum, right_sum});
    }
    
    // Bitset DP
    dp[0] = 1;
    for (auto [left_sum, right_sum] : sums) {
        dp |= (dp << left_sum) | (dp << right_sum);
    }
    
    int total = n;
    int best_A = -1;
    int min_diff = INT_MAX;
    for (int A = 0; A <= total; A++) {
        if (dp[A] && abs(2 * A - total) < min_diff) {
            min_diff = abs(2 * A - total);
            best_A = A;
        }
    }
    
    // Reconstruct assignment to achieve best_A
    vector<int> assignment(n);
    int current_A = best_A;
    vector<int> choices(sums.size());
    for (int i = sums.size() - 1; i >= 0; i--) {
        int left = sums[i].first, right = sums[i].second;
        bitset<MAXSUM> prev = dp & ~((dp << left) | (dp << right));
        if (current_A >= left && ((prev << left) | (prev << right))[current_A - left]) {
            choices[i] = 0; // Choose left
            current_A -= left;
        } else {
            choices[i] = 1; // Choose right
            current_A -= right;
        }
        dp = prev;
    }
    
    // Assign guests based on choices
    fill(vis, vis + n, false);
    for (int i = 0, idx = 0; i < n; i++) {
        if (parent[i] != i || vis[i]) continue;
        int comp = i;
        queue<int> q;
        q.push(comp);
        vis[comp] = true;
        int col = choices[idx];
        color[comp] = col;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : conflict[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        idx++;
    }
    for (int i = 0; i < n; i++) assignment[i] = color[find(i)] + 1;
    
    // Construct dishes
    set<int> dish1, dish2;
    for (int i = 0; i < n; i++) {
        if (assignment[i] == 1) {
            for (int id : L[i]) dish1.insert(original_ingredients[id]);
        } else {
            for (int id : L[i]) dish2.insert(original_ingredients[id]);
        }
    }
    dish1.insert(t1);
    dish2.insert(t2);
    
    // Output
    cout << ":)\n";
    cout << dish1.size() << "\n";
    for (int x : dish1) cout << x << " ";
    cout << "\n";
    cout << dish2.size() << "\n";
    for (int x : dish2) cout << x << " ";
    cout << "\n";
    for (int x : assignment) cout << x << " ";
    cout << "\n";
    
    return 0;
}