//
// Created by victor on 2/16/19.
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

    int n; cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    if (n==1) {
        cout << arr[0] <<endl;
        return 0;
    }
    int mini = arr[0], maxi = arr[n-1];
    vvi factor(107);
    for (int i=1;i<=100;i++){
        for (int j=i;j<=100;j+=i) factor[j].pb(i);
    }
    int ans = 0;
    for (int i=n-1;i>0;i--){
        for (int k:factor[arr[i]]) {
            if (arr[0]+arr[i]-(arr[i]/k+mini*k)<ans) break;
            ans = arr[0]+arr[i]-(arr[i]/k+mini*k);
        }
    }
    ans*=-1;
    for (int i=0;i<n;i++) ans+=arr[i];
    cout << ans << endl;
}
