//
// Created by victor on 3/21/19.
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
#define vpi vector < pair < set <int>, int > >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > >
#define zp mp(0, 0)

const int N = 100007;
const int K = 107;
int dp[N][K];

int pascal(int n, int k){
    if (k>n) return 0;
    if (n==k || k==0) return dp[n][k] = 1;
    return dp[n][k] = pascal(n-1,k)+pascal(n-1,k-1);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;
    vvi red(n+1);
    for (int i=1;i<n;i++){
        int a,b,c; cin >> a >>b >>c;
        if (c==0) {
            red[a].pb(b);
            red[b].pb(a);
        }
    }
    int ans = 0;
    queue<int> q;
    bool touch[n+1];
    fill(touch,touch+n+1,0);
    for (int i=1;i<=n;i++){
        if (touch[i]) continue;
        else {
            int num = 0;
            queue<int> empty;
            swap(q,empty);
            touch[i] = true;
            q.p(i);
            while (!q.empty()){
                int node = q.front();
                q.pop();
                num++;
                for (int a: red[node]){
                    if (!touch[a]) {
                        touch[a] = true;
                        q.p(a);
                    }
                }
            }
            int aabb = num;
            for (int j=1;j<k;j++){
                aabb*=num;
                aabb%=mod;
            }
            ans+=aabb;
            ans%=mod;
        }
    }
    int big = 1;
    while (k--) {
        big*=n;
        big%=mod;
    }
    big-=ans;
    big=(big+mod)%mod;
    cout << big << endl;
}
