//
// Created by victor on 11/28/18.
//

//
// Created by victor on 11/28/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int ca = 0;ca<t;ca++){
        int n,x,y,d;
        cin >> n >> x >>y >>d;
        int a = 1;
        int b = x%d;
        int c = n%d;
        int j = y%d;
        if (j!=a && j!=b && j!=c) {
            cout << -1 << endl;
            continue;
        }
        int ansa=0,ansb=0,ansc=0;
        if (j==b){
            ansb = abs(x-y)/d;
            cout << ansb << endl;
            continue;
        }
        if (a==c){
            ansa = (x-a)/d+1 + (y-a)/d;
            ansc = (n-x)/d + 1 + (n-y)/d;
            cout << min(ansa,ansc) << endl;
            continue;
        }
        if (j==c){
            ansc = (n-x)/d + 1 + (n-y)/d;
            cout << ansc << endl;
        }
        else if (j==a) {
            ansa = (x-1)/d+1 + (y-a)/d;
            cout << ansa << endl;
        }
    }
}