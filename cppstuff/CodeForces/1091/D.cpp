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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n+1];
    arr[n] = n;
    for (int i=n-1;i>0;i--){
        arr[i] = arr[i+1]*i;
        arr[i]%=mod;
    }
    int ans = (n*arr[1])%mod;
    for (int i=2;i<=n;i++){
        ans=ans-arr[i]+mod;
        ans%=mod;
    }
    cout << ans << endl;
}