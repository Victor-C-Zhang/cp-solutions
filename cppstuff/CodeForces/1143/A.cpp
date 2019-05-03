//
// Created by victor on 3/30/19.
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
    int flag = arr[n-1], ans = 0;
    for (int i=n-1;arr[i]==flag;i--) ans = i;
    cout << ans << endl;
}
