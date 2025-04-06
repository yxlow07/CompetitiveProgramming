#include <iostream>
#include <vector>
#include <algorithm> // for std::abs

using namespace std;

// Check if a sequence is possible with max difference K
bool canArrange(long long K, const vector<long long>& A, const vector<long long>& B) {
    int N = A.size();
    bool prev_A = true; // Can S_{i-1} be A_{i-1}?
    bool prev_B = true; // Can S_{i-1} be B_{i-1}?
    
    for (int i = 1; i < N; i++) {
        bool curr_A = false; // Can S_i be A_i?
        bool curr_B = false; // Can S_i be B_i?
        
        // From A_{i-1} to A_i
        if (prev_A && abs(A[i - 1] - A[i]) <= K) curr_A = true;
        // From B_{i-1} to A_i
        if (prev_B && abs(B[i - 1] - A[i]) <= K) curr_A = true;
        // From A_{i-1} to B_i
        if (prev_A && abs(A[i - 1] - B[i]) <= K) curr_B = true;
        // From B_{i-1} to B_i
        if (prev_B && abs(B[i - 1] - B[i]) <= K) curr_B = true;
        
        prev_A = curr_A;
        prev_B = curr_B;
        
        // If no choice is possible, return false early
        if (!prev_A && !prev_B) return false;
    }
    return prev_A || prev_B;
}

int main() {
    // Optimize I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    vector<long long> B(N);
    for (int i = 0; i < N; i++) cin >> B[i];
    
    // Binary search for minimum K
    long long low = 0;
    long long high = 1e18; // Upper bound for differences
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (canArrange(mid, A, B)) {
            high = mid; // Try a smaller K
        } else {
            low = mid + 1; // Need a larger K
        }
    }
    
    cout << low << "\n";
    return 0;
}