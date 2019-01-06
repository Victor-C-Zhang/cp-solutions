//
// Created by victor on 1/4/19.
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

    string s;
    cin >> s;
    string t;
    char a= s[0],b = s[1];
    for (int i=0; i<5;i++){
        cin >> t;
        if (t[0]==a || t[1] == b) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}