//
// Created by victor on 1/23/19.
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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int a,b,c,d;
        cin >> a >>b >>c >>d;
        if (a==c || a==d) cout << b << " " << c << endl;
        else if (b==c) cout << a << " " << c << endl;
        else cout << a << " " << c << endl;
    }
}