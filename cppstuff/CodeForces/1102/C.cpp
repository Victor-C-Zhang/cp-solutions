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

    int n,x,y;
    cin >> n >> x >>y;
    if (x>y) {
        cout << n << endl;
        return 0;
    }
    vi arr(n);
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    int a = 0;
    for (int i=0;i<n;i++){
        if (arr[i]<=x) a++;
    }
    cout << (a+1)/2 << endl;
}