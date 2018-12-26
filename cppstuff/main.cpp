#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int unsigned long long int
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

    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        int g;
        cin >> g;
        if (g==0) cout << 1 << endl;
        else if (g==1) cout << 1 << endl;
        else if (g==2) cout << 2 << endl;
        else {
            int n = g-3;
            int f = ((n*(n+1)*(n*n + 5*n + 18))/4 + 12*n)/6 +4;
            cout << f << endl;
        }
    }
}