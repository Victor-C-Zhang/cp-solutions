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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int ca = 1;ca<=t;++ca) {
        int n; cin >> n;
        int cend = 0, jend = 0;
        bool imp = false;
        char ans[n+1];
        ans[n] = '\0';

        vector<ppi> inputs;
        for (int i = 0;i<n;++i) {
            int a,b; cin >> a >> b;
            inputs.pb({{a,b},i});
        }
        sort(inputs.begin(),inputs.end());
        for (ppi pp : inputs) {
            if (pp.f.f >= cend) {
                cend = pp.f.s;
                ans[pp.s] = 'C';
            }
            else if (pp.f.f >= jend) {
                jend = pp.f.s;
                ans[pp.s] = 'J';
            }
            else {
                imp = true; break;
            }
        }
        cout << "Case #" << ca << ": ";
        if (imp) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
    
    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */