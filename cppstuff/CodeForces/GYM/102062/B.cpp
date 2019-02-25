//
// Created by victor on 2/22/19.
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
#define pppi pair<ppi,int>

const double PI = 3.1415926535897;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i=1; i<=t; i++){
        int m,d; cin >> m >> d;
        double v = (double)m/d;
        double r = cbrt(v*3/4/PI);
        cout << "Case " << i << ": ";
        cout << setprecision(4) << fixed << 4*PI*r*r << endl;
    }

}
