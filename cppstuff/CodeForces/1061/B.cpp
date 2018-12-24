//
// Created by victor on 11/22/18.
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



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,tot=0;
    cin >> n >> m;

    int arr[n+1];
    for (int i=0;i<n;i++){
        int temp;
        cin >> temp;
        arr[i]=temp;
        tot+=temp;
    }
    arr[n] = 0;

    sort(arr,arr+n, greater<int>());
    int ans = 0;
    int point = arr[0];
    for (int i=0;i<n;i++){
        if (point == 1) ans++;
        else if (point>arr[i+1]) {
            ans+=point-arr[i+1];
            point-=point-arr[i+1];
        }
        else {
            ans++;
            point--;
        }
    }
    cout << tot-ans << endl;
}