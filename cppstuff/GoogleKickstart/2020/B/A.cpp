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
    for (int ca = 1;ca <=t;++ca) {
        int n; cin >> n;
        int arr[n];
        for (int i=0;i<n;++i) cin >> arr[i];
        int cnt = 0;
        for (int i=1;i<n-1;++i) {
            if (arr[i]>arr[i-1] && arr[i]>arr[i+1]) ++cnt;
        }
        cout << "Case #" << ca << ": " << cnt << endl;
    }

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */