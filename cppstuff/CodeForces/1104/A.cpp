//
// Created by victor on 1/22/19.
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

    int n;
    cin >> n;
    for (int i=9;i>0;i--){
        if (n%i==0) {
            cout << n/i << endl;
            for (int j=0;j<n/i;j++){
                cout << i << " ";
            }
            cout << endl;
            return 0;
        }
    }
    int ans = n/9 +1;
    for (int i = 0;i<ans-1;i++){
        cout << 9 << " ";
    }
    cout << n%9 << endl;
}