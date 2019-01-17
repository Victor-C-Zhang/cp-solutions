//
// Created by victor on 12/29/18.
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
    string s;
    cin >> s;
    vi cost(n);
    for (int i=0;i<n;i++){
        cin >> cost[i];
    }
    vvi dp(n,vi(5));
    dp[0][0] = 0;
    for (int i=1;i<5;i++){
        dp[0][i] = LONG_LONG_MAX;
    }
    int fringe = 0;
    if (s[0]=='h'){
        fringe++;
        dp[0][0] = cost[0];
        dp[0][1] = 0;
    }
    for (int i=1;i<n;i++){
        int wh;
        switch (s[i]){
            case 'h': wh = 1;
                break;
            case 'a': wh = 2;
                break;
            case 'r': wh = 3;
                break;
            case 'd': wh = 4;
                break;
            default : wh = 0;
        }
        for (int j=0;j<5;j++){
            dp[i][j] = dp[i-1][j];
        }
        if (wh>0 && wh<=fringe+1) {
            dp[i][wh] = min(dp[i-1][wh-1],dp[i-1][wh]);
            dp[i][wh-1] = dp[i-1][wh-1]+cost[i];
            if (wh==fringe+1) fringe++;
        }

    }
    cout << *min_element(dp[n-1].begin(),dp[n-1].end()-1) << endl;
}