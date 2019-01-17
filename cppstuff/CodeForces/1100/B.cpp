//
// Created by victor on 1/13/19.
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

    int n, m;
    cin >> n >> m;
    vvi arr(n+1);
    for (int i=0;i<m;i++){
        int a;
        cin >> a;
        arr[a].pb(i);
    }
    int maxrep = INT_MAX;
    for (int i=1;i<=n;i++){
        if (arr[i].empty()) {
            for (int j=0;j<m;j++){
                cout << "0";
            }
            cout << endl;
            return 0;
        }
        if (arr[i].size()<maxrep) maxrep = arr[i].size();
    }
    vector<int> ans;
    int maxans;
    for (int i=0;i<maxrep;i++){
        maxans = -1;
        for (int j=1;j<=n;j++){
            if (arr[j][i]>maxans) maxans = arr[j][i];
        }
        ans.pb(maxans);
    }
    int arrr[m];
    fill(arrr,arrr+m,0);
    for (auto i: ans) arrr[i] = 1;
    for (int i=0;i<m;i++){
        cout << arrr[i];
    }
    cout << endl;
}