#include <iostream>

using namespace std;
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fi(i, a) for(int i=a;;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define fn(i, a, b, n) for(int i=a;i<=b;i+=n)
#define loop(a, b) for (auto &a : b)

/**
 * Determine if the word W follows the rules of toki pona phonotactics.
 * 
 * W: the word to check
 */
bool isCon(char c) {
    string con = "mnptkswjl";
    return con.find(c) != string::npos;
}

bool isVow(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string solve(string W) {
    int n = W.length(); bool a,b,c,d,x;
    ff(i, 0, n-2) {
        if ((W[i] == 'w' && (W[i+1] == 'u' || W[i+1] == 'o')) ||
            (W[i] == 'j' && W[i+1] == 'i') ||
            (W[i] == 't' && W[i+1] == 'i') ||
            (W[i] == 'n' && (W[i+1] == 'n' || W[i+1] == 'm')) ||
            (isVow(W[i]) && isVow(W[i+1]))
                ) return "ike";
        if ((!isVow(W[i]) && !isCon(W[i])) || (!isVow(W[i+1]) && !isCon(W[i+1]))) return "ike";
    }
    if (n==1) return isVow(W[0]) ? "pona" : "ike";
    int i = 0;
    while (i < n) {
        // Optionally consume a consonant (excluding 'n') or 'n' only if followed by a vowel
        if (isCon(W[i]) && W[i] != 'n') {
            i++;
            if (i >= n) return "ike"; // Expecting a vowel after consonant
        } else if (W[i] == 'n') {
            // 'n' can be a syllabic 'n' only if it's followed by a vowel
            if (i + 1 < n && isVow(W[i + 1])) {
                i++;
            } else {
                // Treat n as syllable
                i++;
                continue;
            }
        }

        // Must have a vowel after the optional consonant
        if (i >= n || !isVow(W[i])) {
            return "ike";
        }
        i++; // Consume the vowel

        // Optionally consume an 'n' at the end of the syllable
        if (i < n && W[i] == 'n') {
            i++;
        }
    }
    return "pona";
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string W;
        cin >> W;
        cout << solve(W) << '\n';
    }
}
