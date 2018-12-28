//
// Created by victor on 12/26/18.
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

const int N = 2000;
bool prime[N];
unordered_set<int> vs;

void sieve()
{
    for(int i = 2; i < N; i++) prime[i] = 1;

    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            vs.insert(i);
            for(int j = i * i; j < N; j += i) prime[j] = 0;
        }
    }
}
int powmod(int a, int b, int m) {
    int res = 1;
    while(b)
        if(b & 1) res = (res * 1ll * a) % m, --b;
        else a = (a * 1ll * a) % m,  b >>= 1;
    return res;
}
int miller_rabin(int n) {
    if(n == 1) return 0;

    int b = 2;
    for(int g; (g = gcd(n, b)) != 1; ++b)
        if(n > g) return 0;
    int p = 0, q = n - 1;
    while((q & 1) == 0)
        ++p,  q >>= 1;
    int rem = powmod(b, q, n);
    if(rem == 1 || rem == n - 1) return 1;
    for(int i = 1; i < p; ++i) {
        rem = (rem * 1ll * rem) % n;
        if(rem == n - 1) return 1;
    }
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, orig;
    cin >> n;
    orig = n;
    sieve();
    while (!miller_rabin(n)) n--;
    vi ans;
    ans.pb(n);
    int targ = orig-n;
    if (targ ==2) {
        cout << 2 << endl << 2 <<" "<< n << endl;
        return 0;
    }
    if (targ == 0) {
        cout << 1 << endl << n << endl;
        return 0;
    }
    for (int p: vs){
        if (vs.find(targ - p)!=vs.end()) {
            cout << 3 << endl << p <<" "<< targ-p <<" "<< n << endl;
            break;
        }
    }
}