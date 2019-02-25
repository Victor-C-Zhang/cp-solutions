//
// Created by victor on 2/20/19.
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

    int n; cin >>n;
    vvi sum(n,vi(2));//even, odd
    for (int i=0;i<n;i++){
        fill(sum[i].begin(),sum[i].end(),0);
    }
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sum[0][0] = arr[0];
    sum[0][1] = arr[0]*-1;
    for (int i=1;i<n;i++){
        sum[i][i%2]=sum[i-1][i%2]+arr[i];
        sum[i][(i+1)%2]=sum[i-1][(i+1)%2]-arr[i];
    }
    int ans = 0;
    for (int i=1;i<n;i++){
        if (sum[i-1][i%2]+sum[n-1][(i+1)%2]-sum[i][(i+1)%2]==0) ans++;
    }
    if (sum[n-1][1]+arr[0]==0) ans++;
    cout << ans << endl;
}

