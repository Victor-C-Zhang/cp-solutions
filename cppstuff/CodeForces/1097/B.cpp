//
// Created by victor on 1/4/19.
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
    cin >> n;
    int arr[(int)pow(2,n+1)];
    arr[1] = 0;
    for (int j=0;j<n;j++){
        cin >> k;
        for (int i=(int)pow(2,j);i<(int)pow(2,j+1);i++) {
            arr[2 * i] = (arr[i] - k) % 360;
            arr[2 * i + 1] = (arr[i] + k) % 360;
        }
    }

    for (int i=(int)pow(2,n);i<(int)pow(2,n+1);i++){
        if (arr[i] == 0 ) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}