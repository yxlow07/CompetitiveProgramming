#include "iostream"
#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k, mx; cin >> n >> k;
    ll s[n];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        mx = max(mx, s[i]);
    }
    for (int i = 0; i < n-k; i++) {
        mx = max(mx, s[i] + s[2*(n-k)-1-i]);
    }

    cout << mx;

    return 0;
}
/*
 * #include<bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
    lli t;
    cin >> t;

    while (t--)
    {
        lli n;
        cin>>n;

        string s;
        cin>>s;

        vector<lli>v;

        lli z = 0;

        for(lli i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                z++;
                v.push_back(i);
            }
        }

        lli ans = 0;

        for(lli i = 0; i < n; i++)
        {
            if(z < i+1)
            {
                cout<<"-1"<<" ";
            }
            else
            {
                ans += abs(n-1-i-v[v.size()-1-i]);

                cout<<ans<<" ";
            }
        }

        cout<<endl;
    }

    return 0;
}
 */