//
// Created by victor on 1/5/19.
//

//finish this up
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

const int N = (int)4e7;
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

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int power(int x, int y, int m) {
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}
int modInverse(int a, int m)
{
    int g = gcd(a, m);
    if (g != 1)
        return -1;
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        return power(a, m-2, m);
    }
}

int basen(string s, int base){
    int b = 1;
    int ans=0;
    for (int i=s.size()-1;i>-1;i--){
        ans+=(s[i]-'0')*b;
        b*=base;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    sieve();
    vector<pi> fact;
    for (int i=0;n>1;i++){
        if (n%vs[i]==0){
            int j=0;
            while (n%vs[i]==0){
                n/=vs[i];
                j++;
            }
            fact.pb({vs[i],j});
        }
    }
    int base = fact.size();
    if (base==0) {
        cout << 1 << endl;
        return 0;
    }
    int a=1,b=1;
    for (int i=0;i<base;i++){
        int en = fact[i].s;
        int ba = fact[i].f;
        vector<vector<pi>> dp1(en+1, vector<pi>(k+1)); //n,k
        for (int j=0;j<=en;j++){
            for (int m=0;m<=k;m++){
                dp1[j][m] = {1,1};
            }
        }
        for (int j=0;j<en;j++){
            dp1[j][0] = {0,1};
        }
        for (int t=0;t<k;t++){
            for (int u = 0;u<en;u++){
                if (dp1[t][u].f!=0){
                    //do the thing
                }
            }
        }
    }

}