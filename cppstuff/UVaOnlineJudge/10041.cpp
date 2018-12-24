//
// Created by victor on 12/15/18.
//

//
// Created by victor on 11/28/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int ca=0;ca<N;ca++){
        int n;
        cin >> n;
        int arr[n];
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        int mid = arr[n/2];
        int ans = 0;
        for (int i=0;i<n/2;i++){
            ans+=arr[n/2]-arr[i];
        }
        for (int i= n/2+1;i<n;i++){
            ans+=arr[i]-arr[n/2];
        }
        cout << ans << endl;
    }
}