//
// Created by victor on 9/4/19.
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

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

vi safe;
int binl(int col){
    int l=0,r=safe.size()-1,mid;
    while (l<r){
        mid = l + (r-l)/2;
        if (safe[mid]==col) return col;
        if (safe[mid]<col) l = mid+1;
        else r = mid;
    }
    while (safe[mid]>col && mid>0) mid--;
    return safe[mid];
}
int binr(int col){
    int l=0,r=safe.size()-1,mid;
    while (l<r){
        mid = l + (r-l)/2;
        if (safe[mid]==col) return col;
        if (safe[mid]<col) l = mid+1;
        else r = mid;
    }
    while (safe[mid]<col && mid<safe.size()-1) mid++;
    return safe[mid];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k,q; cin >> n >> m >> k >> q;
    int extreme[2][n+1]; fill(extreme,extreme[0][n+1],INT_MAX); fill(extreme[1][0],extreme[1][n+1],0);
    int dp[2][n+1]; fill(dp,dp[2][n+1],0);
    int a,b;
    while (k--){
        cin >> a >> b;
        extreme[0][a] = (b<extreme[0][a]) ? b : extreme[0][a];
        extreme[1][a] = (b>extreme[1][a]) ? b : extreme[1][a];
    }

    while (q--) {
        cin >> a;
        safe.pb(a);
    }
    sort(safe.begin(),safe.end());
    dp[0][1] = extreme[1][1]*2-1-extreme[0][1];
    dp[1][1] = extreme[1][1]-1;
    for (int i=2;i<=n;++i){
        if (extreme[1][i]==0) {
            dp[0][i]++; dp[1][i]++;
            continue;
        }
        dp[0][i] = min(min(dp[0][i-1] + extreme[0][]),min())


    }
}
