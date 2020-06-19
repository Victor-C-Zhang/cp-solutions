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

    int n; cin >> n;

    int arr[n];
    bool contained[200007];
    bool reserved[200007];
    for (int i=0;i<200007;++i) {
        contained[i] = 0;
        reserved[i] = 0;
    }
    for (int i=0;i<n;++i) {
        cin >> arr[i]; reserved[arr[i]] = 1;
    }
    vi res;

    int curr_max = -1, curr_mex = 0;
    for (int i=0;i<n;++i) {
        if (arr[i] == curr_mex) {
            ++curr_max;
            while (reserved[curr_max] || contained[curr_max]) ++curr_max;
            res.pb(curr_max);
            contained[curr_max] = 1;
            while (contained[curr_mex]) ++ curr_mex;
        }
        else {
            contained[curr_mex] = 1;
            res.pb(curr_mex);
            while (contained[curr_mex]) ++curr_mex;
            if (curr_mex != arr[i]) {
                // for (int i: res) cout << i << " ";
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for (auto i: res) cout << i << " ";
    cout << endl;

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */