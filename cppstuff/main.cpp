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
    vi factors;
    for (int T=1; T<=t; T++){
        int n; cin >> n;
        int places = 0;
        while (n){
            if (n-9*pow(10,places)>=0) {
                n-=9*pow(10,places);
                places++;
            }
        }
        places++;
        int ans = 0;
        cout << "Case " << T << ": ";
        int gg = gcd(a,n);
        cout << a/gg << '/' << n/gg << endl;
    }

}
