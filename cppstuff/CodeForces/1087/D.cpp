//
// Created by victor on 12/23/18.
//


#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)

typedef long long ll;
typedef long double ld;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ld k;
    cin >> n >> k;
    vvi tree(n+1);
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    ld cnt = 0;
    for (int i=1;i<=n;i++){
        if (tree[i].size()==1) cnt++;
    }
    cout.precision(17);
    cout << k/cnt*2 << endl;
}