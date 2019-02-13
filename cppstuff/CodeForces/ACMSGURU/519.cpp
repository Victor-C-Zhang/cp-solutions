//
// Created by victor on 2/13/19.
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

    int n,m; cin >> n >>m;
    int ans = 0;
    int arr[n+2][m+2];
    for (int i=0;i<n+2;i++){
        fill(arr[i],arr[i]+m+2,0);
    }
    for (int i=1;i<=n;i++){
        string a;
        cin >> a;
        for (int j=1;j<=m;j++){
            arr[i][j] = a[j-1]-'0';
            if (arr[i][j]) ans+=2;
        }
    }
    for (int i=1;i<n+2;i++)
        for (int j=1;j<m+2;j++)
            ans+=abs(arr[i][j]-arr[i-1][j])+abs(arr[i][j]-arr[i][j-1]);

    cout << ans << endl;
}
