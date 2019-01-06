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
    vi fact;
    for (int i=1;i<=(int)sqrt(n);i++){
        if (n%i==0) {
            fact.pb(i);
            if (i!=n/i) fact.pb(n/i);
        }
    }
    sort(fact.rbegin(),fact.rend());
    for (int i: fact){
        cout << (1+n+1-i)*(n/i)/2 << " ";
    }
    cout << endl;
}