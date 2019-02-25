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

const int N = 1000007;
bool prime[N];
vi vs;

void sieve()
{
    for(int i = 2; i < N; i++) prime[i] = 1;

    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            vs.pb(i);
            for(int j = i * i; j < N; j += i) prime[j] = 0;
        }
    }
}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

const double PI = acos(-1.0);
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    int t; cin >> t;
    vi factors;
    for (int T=1; T<=t; T++){
        int n; cin >> n;
        for (int i = 0; vs[i]<=n;i++){
            int a = 0;
            while (n%vs[i]){
                n/=vs[i];
                a++;
            }
            if (a!=0) factors.pb(a);

        }

        cout << "Case " << T << ": ";
        int gg = gcd(a,n);
        cout << a/gg << '/' << n/gg << endl;
    }

}
