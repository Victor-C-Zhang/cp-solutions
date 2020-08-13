#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long int
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

int times(int n) {
    int ret = 1;
    while (n!=0) {
        if ((n%10) != 0 ) ret*=(n%10);
        n/=10;
    }
    return ret;
}

vvi arr(10, vi(1000007));
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[1000007] = {-1};
    for (int i=1;i<10;++i) dp[i] = i;
    for (int i=10;i<1000001;++i) dp[i] = dp[times(i)];
    for (int i=1;i<=9;++i) arr[i][0] = 0;
    for (int i = 1; i< 1000001; ++i) {
        for (int j=1;j<10;++j) {
            arr[j][i] = arr[j][i-1];
        }
        ++arr[dp[i]][i];
    }
    int q; cin >> q;
    int l,r,k;
    while (q--) {
        cin >> l >> r >> k;
        cout << arr[k][r] - arr[k][l-1] << endl;
    }

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */