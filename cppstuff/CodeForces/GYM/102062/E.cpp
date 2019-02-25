//
// Created by victor on 2/22/19.
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

const double PI = acos(-1.0);
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i=1; i<=t; i++){
        int d, x; cin >> d >> x;
        cout << "Case " << i << ": ";
        int ans = 0;
        bool flag = true;
        for (int i=d; i>=-1;i--){
            if (ans<0) break;
            if (ans==x) {
                cout << "YES " << d-i << endl;
                flag = false;
                break;
            }
            else if (x>ans) ans+=(int)pow(2,i);
            else ans-=(int)pow(2,i);

        }
        if (flag) cout << "NO" << endl;
    }

}
