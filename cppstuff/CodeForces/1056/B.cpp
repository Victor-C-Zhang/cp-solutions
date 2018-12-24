//
// Created by victor on 11/25/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
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

    int n,m;
    cin >> n >> m;

    int divs[m];
    for (int i=0;i<m;i++){
        divs[i]=0;
    }
    for (int i=0;i<m;i++){
        divs[(i*i)%m]++;
    }

    int mult = n/m;
    int rem = n%m;
    for (int i=0;i<m;i++){
        divs[i]*=mult;
    }
    for (int i=1;i<=rem;i++){
        divs[(i*i)%m]++;
    }
    int ans = 0;
    ans+=divs[0]*divs[0];
    for (int i=1;i<m;i++){
        ans+=divs[i]*divs[m-i];
    }
    cout << ans << endl;
}