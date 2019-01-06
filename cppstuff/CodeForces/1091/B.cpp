//
// Created by victor on 1/5/19.
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

    int n;
    cin >> n;
    int a=0,b=0;
    for (int i=0;i<2*n;i++){
        int c,d;
        cin >> c >>d;
        a+=c;
        b+=d;
    }
    cout << a/n << " "<<b/n << endl;
}