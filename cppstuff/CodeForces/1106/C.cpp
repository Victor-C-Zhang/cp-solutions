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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int ans = 0;
    for (int i=0;i<n/2;i++){
        ans+=(arr[i]+arr[n-1-i])*(arr[i]+arr[n-1-i]);
    }
    cout << ans << endl;
}
