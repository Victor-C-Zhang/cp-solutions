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
    for (int ca = 1; ca <= t; ++ca) {
        cout << "Case #" << ca << ": ";

        int n; cin >> n;
        int e[n], r[n];
        int tot_e = 0;
        for (int i=0;i<n;++i) {
            cin >> e[i] >> r[i];
            tot_e += e[i];
        }
        int extra[n];
        for (int i=0;i<n;++i) {
            extra[i] = tot_e - e[i] - r[i];
        }
        bool flag = false;
        int remaining = n;
        for (int i=0;i<n;++i) {
            if (extra[i] < 0) {
                if (remaining == 1) {
                    cout << n - remaining << " " << e[i] << endl;
                    flag = true; break;
                }
                for (int j = 0; j<i;++i) {
                    if (extra[j] - e[i] < 0) {
                        int sum = 0;
                        for (int k = 0;k<i;++k) sum+=e[k];
                        cout << n - remaining << " " << tot_e + sum << endl;
                        flag = true; break;
                    }
                }
                if (flag) break;
                if (i < n - 1 && extra[i+1] - e[i] < 0) {
                    int sum = 0;
                    for (int k = 0;k<i;++k) sum+=e[k];
                    cout << n - remaining << " " << tot_e + sum << endl;
                    flag = true; break;
                }
                remaining--;
                tot_e -= e[i];
                for (int j=0;j<n;++j) {
                    extra[j] -= e[i];
                }
                extra[i] = LONG_MAX;
                e[i] = 0;
            }
        }
        if (flag) continue;
        cout << n - remaining << " INDEFINITELY" << endl;

    }

    
    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */