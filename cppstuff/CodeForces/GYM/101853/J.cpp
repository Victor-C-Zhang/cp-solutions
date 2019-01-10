//
// Created by victor on 1/7/19.
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
#define vi vector <char>
#define vvi vector < vector <char> >
#define pi pair <int, int>
#define ppi pair < pair <int, int> , int >
#define pppi pair<ppi,int>




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    int dp[10007];
    cin >> test;
    while (test--){
        int n,a;
        cin >> n;
        fill(dp,dp+10007,0);
        for (int i=0;i<n;i++){
            cin >> a;
            dp[a]++;
        }
        int ans = dp[1]+dp[2];
        for (int i=2;i<10000;i++){
            ans=max(ans,dp[i]+dp[i+1]);
        }
        cout << ans << endl;
    }
}