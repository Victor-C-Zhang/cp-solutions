//
// Created by victor on 2/20/19.
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

    int n,k; cin >> n >> k;
    if (k*(k-1)<n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int h=1;h<=k;h++){
        int i = 1, j=h;
        while (j>0 && n>0){
            if (i!=j) {
                cout << i << " " << j << endl;
                n--;
            }
            j--;
            i++;
        }
    }
    for (int i = 2;i<=k;i++){
        int j = k, h = i;
        while (h<=k && n>0){
            if (h!=j) {
                cout << h << " " << j << endl;
                n--;
            }
            j--;
            h++;
        }
    }
}

