//
// Created by victor on 6/18/19.
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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];
    int ans[n]; fill(ans,ans+n,-1);
    int inc = INT_MIN, dec= INT_MAX;
    for (int i=0;i<n;i++){
        if (arr[i]>=dec && arr[i]<=inc) {
            cout << "NO" << endl;
            return 0;
        }
        if (arr[i]>=dec) {
            inc = arr[i];
            ans[i] = 0;
        }
        else if (arr[i]<=inc){
            dec = arr[i];
            ans[i] = 1;
        }
        else {
            if (i==n-1) ans[i] = 0;
            else if (arr[i+1]>arr[i]){
                inc = arr[i];
                ans[i] = 0;
            }
            else {
                dec = arr[i];
                ans[i] = 1;
            }
        }
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++) cout << ans[i] << " ";
    cout << endl;
}
