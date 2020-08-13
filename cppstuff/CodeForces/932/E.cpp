#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define vpi vector < pair < set <int>, int > >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > >
#define zp mp(0, 0)
 
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

int N;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int exp(int pow) {
    return binpow(2,pow,mod);
}

vector<vvi> dp(5002,vvi(5002,vi(5002)));

int recur(int k, int p, int q) {
    if (dp[k][p][q] != -1) return dp[k][p][q];
    if (k==0) return dp[k][p][q] = exp(N-q);
    if (p == 0) return dp[k][p][q] = ((N-q)*recur(k-1,p+1,q+1))%mod;
    return dp[k][p][q] = (p*recur(k-1,p,q) + (N-q)*recur(k-1,p+1,q+1))%mod;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0;i<5002;++i) {
        for (int j=0;j<5002; ++j) {
            for (int k=0;k<5002;++k) {
                dp[i][j][k] = -1;
            }
        }
    }
    cin >> N;
    int k; cin >> k;
    cout << recur(k,0,0) << endl;
    
    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */