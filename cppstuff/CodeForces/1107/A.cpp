//
// Created by victor on 2/6/19.
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

    int q; cin >> q;
    while (q--){
        int a; string b;
        cin >> a >>b;
        if (a>2) {
            cout << "YES" << endl << 2 << endl;
            cout << b[0] << " ";
            for (int i=1;i<a;i++) cout << b[i];
            cout << endl;
        }
        else {
            if (b[0]>=b[1]) cout << "NO" << endl;
            else {
                cout << "YES" << endl << 2 << endl << b[0] << " "<<b[1] << endl;
            }
        }
    }
}
