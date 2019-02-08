//
// Created by victor on 2/8/19.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define double long double
//#define mod 998244353
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

    int n,k,m, N;
    cin >> n >> k >>m;
    N =n;
    vi arr, pref(n);
    vi up(n);
    fill(up.begin(),up.end(),0);
    double A = 0.0;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        A+=a;
        arr.pb(a);
    }
    sort(arr.begin(),arr.end());
    if (n==1) {
        cout << arr[0]+min(m,k) << endl;
        return 0;
    }
    for (int i=1;i<n;i++) arr[i]+=arr[i-1];
    A/=n;
    double AA = A;
    A=(A*n+min(m,k*n))/n;
    for (int i=0;i<min(n-1,m);i++){
        double sol = (AA*n-arr[i]+min(k*(n-i-1),m-i-1))/(n-i-1);
        if (sol>A) {
            A=sol;
        }
    }
    cout << setprecision(17) << A << endl;
}
