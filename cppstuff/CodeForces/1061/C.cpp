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
//#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)

int N = 1007;
bool prime[1007];
vi vs;

void sieve()
{
    for(int i = 2; i < N; i++) prime[i] = true;

    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            vs.pb(i);
            for(int j = i * i; j < N; j += i) prime[j] = false;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    sieve();
    vvi allfactors;
    for (int i=0;i<n;i++){
        vi factors;
        factors.pb(1);
        for (auto pr : vs){
            int temp = 0;
            while (arr[i]%pr==0){
                temp++;
                arr[i]/=pr;
            }
            int end = factors.size();
            for (int j=1;j<=temp;j++){
                for (int k=0;k<end;k++){
                    factors.pb(pow(pr,j)*factors.at(k));
                }
            }
        }
        if (arr[i]!=1) {
            int pr = arr[i];
            int end = factors.size();
            for (int k=0;k<end;k++){
                factors.pb(pr*factors.at(k));
            }
        }

        allfactors.pb(factors);
    }

    int dp[n][n+1];
    for (int i=0;i<n;i++){
        for (int j=0;j<=n;j++){
            dp[i][j] = 0;
        }
    }
    dp[0][1] = 1;
    for (int i=1;i<n;i++){
        for (int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j];
        }
        for (int j: allfactors.at(i)){
            if (j==1) {
                dp[i][j] = dp[i-1][j]+1;
                dp[i][j] %= mod;
            }
            else if (dp[i-1][j-1]!=0) {
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        ans+=dp[n-1][i];
        ans %= mod;
    }
    cout << ans << endl;
}