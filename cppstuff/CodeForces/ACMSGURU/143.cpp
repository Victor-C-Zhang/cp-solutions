//
// Created by victor on 1/6/19.
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

const int N = 16007;

vvi graph(N+1);
int arr[N+1],dp[N+1];
bool touch[N+1];

int recur(int node){
    if (dp[node]!=INT_MIN) return dp[node];
    touch[node] = true;
    dp[node] = arr[node];
    if (graph[node].size()==1 && node!=1) return dp[node];
    for (int i: graph[node]) {
        if (!touch[i] && recur(i)>=0) dp[node]+=recur(i);
    }
    return dp[node];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> arr[i];
    }
    fill(dp,dp+n+1,INT_MIN);
    fill(touch,touch+n+1,false);

    for (int i=1;i<n;i++){
        int a,b;
        cin >> a >>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    recur(1);
    int ans = INT_MIN;
    for (int i=1;i<=n;i++){
        if (dp[i]>ans) ans = dp[i];
    }
    cout << ans << endl;
}