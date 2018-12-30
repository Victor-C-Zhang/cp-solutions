//
// Created by victor on 12/28/18.
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
#define zp mp(0, 0)


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vvi angs(181);
    for (int i=3;i<=180;i++){

    }
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int deg;
        cin >> deg;
        if (deg==180) {
            cout << -1 << endl;
            continue;
        }
        deg*=2;
        if (deg<=180) {
            for (int n=3;n<=360;n++){
                if ((deg*n)%360 == 0) {
                    int k = (deg*n)/360;
                    if (k+2<=n) {
                        cout << n << endl;
                        break;
                    }
                }
            }
        }
        else if (deg>180) {
            deg = 360 - deg;
            for (int n=3;n<=360;n++){
                if ((deg*n)%360 == 0 && (deg*n)/360>1) {
                    cout << n << endl;
                    break;
                }
            }
        }
    }
}
