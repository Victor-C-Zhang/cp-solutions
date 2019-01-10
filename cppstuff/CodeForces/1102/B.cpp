//
// Created by victor on 1/9/19.
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

    int n,k;
    cin >> n >> k;
    vector<pi> arr;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        arr.pb({a,i});
    }
    sort(arr.begin(),arr.end());
    vi ans(n);
    bool rounded = false;
    if (k==1) {
        int num = arr[0].f;
        ans[arr[0].s] = 1;
        for (int i=1;i<n;i++){
            if (arr[i].f==num) {
                cout << "NO" << endl;
                return 0;
            }
            num = arr[i].f;
        }
        cout << "YES" << endl;
        for (int i=0;i<n;i++){
            cout << 1 << " ";
        }
        cout << endl;
    }
    else {

        int same = 1;
        int color = 1;
        int num = arr[0].f;
        ans[arr[0].s] = color;
        color++;
        if (color > k) {
            color %= k;
            rounded = true;
        }
        for (int i = 1; i < n; i++) {
            if (num == arr[i].f) same++;
            else {
                same = 1;
                num = arr[i].f;
            }
            if (same > k) {
                cout << "NO" << endl;
                return 0;
            }
            ans[arr[i].s] = color;
            if (color == k) rounded = true;
            color++;
            if (color > k) color %= k;
        }
        if (!rounded) {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}