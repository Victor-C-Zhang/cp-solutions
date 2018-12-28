//
// Created by victor on 12/27/18.
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
#define zp mp(0, 0)


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vi arr;
    for (int i=0;i<n;i++){
        int a;
        cin >>a;
        arr.pb(a);
    }
    sort(arr.begin(),arr.end());
    cout << min(arr[arr.size()-1]-arr[1],arr[arr.size()-2]-arr[0]) << endl;
}