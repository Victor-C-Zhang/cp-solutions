//
// Created by victor on 12/24/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)

typedef long long ll;
typedef long double ld;

const int N = 2007;

int pascal[N][N];

int fill(int n, int k){
    if (pascal[n][k]!=-1) return pascal[n][k];
    if (n==k || k==0) return pascal[n][k] = 1;
    return pascal[n][k] = (fill(n-1,k) + fill(n-1,k-1))%mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k;
    cin >> n >> m >> k;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            pascal[i][j] = -1;
        }
    }
    int a = fill(n-1,k);
    a*=m;
    a%=mod;
    for (int i=0;i<k;i++){
        a*=m-1;
        a%=mod;
    }
    cout << a << endl;
}