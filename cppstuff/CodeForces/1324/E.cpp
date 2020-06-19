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

vi prefix(2007);
int n,h,l,r;
vvi dp(2007,vi(2007));

int recur(int i, int push) {
    if (i>=n) return 0;
    if (dp[i][push]!=-1) return dp[i][push];
    int ttr = ((prefix[i]-push+h)%h <=r && (prefix[i]-push+h)%h >= l)
        + max(recur(i+1,push),recur(i+1,(push+1)%h));
    // cout << "(" << i <<"," << push << "): " << ttr << endl;
    return dp[i][push] = ttr;
}

signed main(){
    cin >> n >> h >> l >> r;
    for (int i=0;i<n;++i)
        for (int j=0;j<h;++j)
            dp[i][j] = -1;
    for (int i=0;i<n;++i) cin >> prefix[i];
    for (int i=1;i<n;++i) {
        prefix[i]+=prefix[i-1];
        prefix[i]%=h;
    }
    cout << max(recur(0,0),recur(0,1)) << endl;

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */