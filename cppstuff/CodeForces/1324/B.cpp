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
    while (t--) {
        int n,a; cin >> n;
        int arr[n+1];
        fill(arr,arr+n+1,-1);
        bool flag = false;
        for (int i=0;i<n;++i) {
            cin >> a;
            if (flag) continue;
            if (arr[a]==-1) arr[a] = i;
            else if (arr[a] < i-1) {
                cout << "YES" << endl;
                flag = true;
            }
        }
        if (!flag) cout << "NO" << endl;
    }

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */