//
// Created by victor on 12/25/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define double long double
#define mod 998244353
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int> , int >
#define zp mp(0, 0)


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int ca = 0;ca < T; ca++){
        int a,b;
        cin >> a >> b;
        int n = abs(a -b);
        if (n==0) {
            cout << 0 << endl;
            continue;
        }
        int k = floor(sqrt(n));
        int t = n-k*k;
        if (t==0) cout << 2*k-1 << endl;
        else if (t<=k) cout << 2*k << endl;
        else cout << 2*k + 1 << endl;
    }
}