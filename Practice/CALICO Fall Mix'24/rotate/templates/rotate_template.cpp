#include <iostream>
#include "vector"

using namespace std;
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fi(i, a) for(int i=a;;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define fn(i, a, b, n) for(int i=a;i<=b;i+=n)
#define loop(a, b) for (auto &a : b)

/**
 * Return the position of the card labelled K after shuffling a deck with N
 * cards, where the topmost card is in position 1, the second from topmost card
 * is position 2, and so on.
 * 
 * N: the number of cards in the deck
 * K: the label of the target card
 */
int solve(int n, int k) {
    if (n == 1 && k == 1) return 1;
    vector<int> cards(n+1, -1); int p, prev; // Cards store the card at the i-th position
    ff(i, 1, n) cards[i] = i;
    cout<<"";
    ff(i, 1, n-1) {
        p = cards[i];
        ff(j, i, n) {
            cards[j] = cards[j+1];
        }
        cards[n] = p;
        continue;
    }
    ff(i, 1, n) {
        if (cards[i] == k) {
            return i;
        }
    }
    return n;
}

int main() {
    int T;
    int N, K;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        cout << solve(N, K) << '\n';
    }
}
