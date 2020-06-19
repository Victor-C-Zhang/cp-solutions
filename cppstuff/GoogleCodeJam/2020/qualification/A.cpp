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

signed main(){
    int t; cin >> t;
    for (int ca = 1; ca <= t; ++ca){
        int n; cin >> n;
        vvi rows(n+1,vi(n+1,0));
        vvi cols(n+1,vi(n+1,0));

        int a;
        int numrows = 0, numcols = 0, tr = 0;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j){
                cin>>a;
                ++rows[i][a];
                ++cols[j][a];
                if (i==j) tr+=a;
            }


        for (vi row : rows) {
            for (int i : row){
                if (i>1) {
                    ++numrows;
                    break;
                }
            }
        }
        for (vi row : cols) {
            for (int i : row){
                if (i>1) {
                    ++numcols;
                    break;
                }
            }
        }
        printf("Case #%lld: %lld %lld %lld\n", ca, tr, numrows, numcols);
    }

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */