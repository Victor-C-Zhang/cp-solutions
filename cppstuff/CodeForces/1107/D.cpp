//
// Created by victor on 2/7/19.
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

int disc(char c){
    switch (c) {
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        default: return (c-'0');
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int dp[n+1][n+1];
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=0;j<n/4;j++){
            int a = disc(s[j]);
            dp[i][j*4+4] = a%2;
            a/=2;
            dp[i][j*4+3] = a%2;
            a/=2;
            dp[i][j*4+2] = a%2;
            a/=2;
            dp[i][j*4+1] = a%2;
        }
    }
    for (int i=0;i<=n;i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            dp[i][j] = dp[i][j-1]+dp[i][j];
        }
    }
    for (int j=1;j<=n;j++){
        for (int i=1;i<=n;i++){
            dp[i][j] = dp[i-1][j]+dp[i][j];
        }
    }
    int ans = 1;
    bool flag = false;
    for (int c=2;c<=n;c++){
        if (n%c!=0) continue;
        for (int i=1;i<=n;i+=c){
            for (int j=1;j<=n;j+=c){
                if (!(dp[i+c-1][j+c-1]-dp[i+c-1][j-1]-dp[i-1][j+c-1]+dp[i-1][j-1] == c*c ||
                      dp[i+c-1][j+c-1]-dp[i+c-1][j-1]-dp[i-1][j+c-1]+dp[i-1][j-1] == 0 )) flag = true;
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) {
            flag = false;
            continue;
        }
        ans=c;
    }
    cout << ans << endl;
}
