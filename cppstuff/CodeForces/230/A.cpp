//
// Created by victor on 12/25/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int unsigned long long int
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

    int s,n;
    cin >> s >> n;
    vector<pi> strength;
    for (int i=0;i<n;i++){
        int a,b;
        cin >> a >>b;
        strength.pb({a,b});
    }
    sort(strength.begin(),strength.end());
    for (pair ip : strength){
        if (s<=ip.f) {
            cout << "NO" << endl;
            return 0;
        }
        else s+=ip.s;
    }
    cout << "YES" << endl;
}