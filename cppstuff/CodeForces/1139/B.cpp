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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];
    int ans = arr[n-1];
    int maxm = arr[n-1];
    for (int i=n-2;i>-1;i--){
        if (arr[i]<maxm) {
            maxm = arr[i];
            ans+=arr[i];
        }
        else {
            ans+=max(0LL, maxm-1);
            maxm = max(0LL,maxm-1);
        }
    }
    cout << ans << endl;
}
