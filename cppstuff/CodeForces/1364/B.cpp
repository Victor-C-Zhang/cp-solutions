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

int det_dir(int x) {
    if (x>0) return 1;
    if (x<0) return -1;
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi arr, res;
        int temp;
        for (int i=0;i<n;++i) {
            cin >> temp; arr.pb(temp);
        }
        res.pb(arr[0]);
        temp = arr[0];
        if (n == 2) {
            res.pb(arr[1]);
            cout << 2 << endl;
            for (auto i : res) cout << i << " ";
            cout << endl;
            continue;
        }
        int direction = det_dir(arr[1]-arr[0]);
        for (int i=1; i<n;++i) {
            if (det_dir(arr[i] - temp) == 0) continue;
            else if (det_dir(arr[i] - temp) == direction) temp = arr[i];
            else {
                res.pb(temp);
                direction = det_dir(arr[i] - temp);
                temp = arr[i];
            }
        }
        if (arr[n-1] != res[res.size()-1]) res.pb(arr[n-1]);
        cout << res.size() << endl;
        for (auto i : res) cout << i << " ";
        cout << endl;

    }

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */