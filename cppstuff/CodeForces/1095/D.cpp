//
// Created by victor on 12/27/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long int
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

    int n;
    cin >> n;

    vector<pi> orig;
    vvi neighbor(n+1);
    orig.pb({0,0});
    for (int i=1;i<=n;i++){
        int a,b;
        cin >> a >>b;
        orig.pb({a,b});
        neighbor[a].pb(b);
        neighbor[b].pb(a);
    }

    if (n==3) {
        cout << 1 << " "<<2 <<" "<<3<<endl;
        return 0;
    }

    int ptr = 1;
    cout << 1 << " ";
    for (int i=1;i<n;i++){
        int a = orig[ptr].f;
        int b = orig[ptr].s;
        if (neighbor[a][0]==ptr || neighbor[a][1] == ptr) {
            cout << a << " ";
            ptr = a;
        }
        else {
            cout << b << " ";
            ptr = b;
        }
    }
    cout << endl;
}