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
    vi fact;
    set<int> bigfact;
    for (int i=0;i<t;i++){
        int a;
        cin >> a;
        fact.pb(a);
    }
    sort(fact.begin(),fact.end());
    int big = fact[fact.size()-1];
    for (int i=1;i<=big;i++){
        if (big%i == 0) bigfact.insert(i);
    }
    for (auto j: bigfact){
        for (int i=0;i<fact.size();i++){
            if (fact[i]==j) {
                fact[i] = 0;
                break;
            }
        }
    }
    sort(fact.begin(),fact.end());
    cout << big << " " << fact[fact.size()-1] << endl;
}