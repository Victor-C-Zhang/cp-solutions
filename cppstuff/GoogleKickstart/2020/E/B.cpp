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
        int a,b,c; cin >> a >> b >> c;
        cout << "Case #" << ca << ":";
        if (a + b - c > n) {
            cout << " IMPOSSIBLE" << endl;
            continue;
        }
        if (a + b - c < n && n < 3) {
            cout << " IMPOSSIBLE" << endl;
            continue;
        }
        if (a + b - c == n && n < 2) {
            cout << " 1" << endl;
            continue;
        }
        if (a + b - c == n) {
            for (int i=0;i<a-c;++i) cout << " " << 1;
            for (int i=0;i<c;++i) cout << " " << 2;
            for (int i=0;i<b-c;++i) cout << " " << 1;
        } else {
            if (a-c == 0 && b-c == 0 && c == 1) {
                cout << " IMPOSSIBLE" << endl;
                continue;
            } else if (c == 1) {
                if (n < 3) {
                    cout << " IMPOSSIBLE" << endl;
                    continue;
                }
                if (a-c == 0) {
                    for (int i=0;i<a-c;++i) cout << " " << 1;
                    for (int i=0;i<c;++i) cout << " " << 3;
                    for (int i=0;i<n-a-b+c;++i) cout << " " << 1;
                    for (int i=0;i<b-c;++i) cout << " " << 2;
                } else {
                    for (int i=0;i<a-c;++i) cout << " " << 2;
                    for (int i=0;i<n-a-b+c;++i) cout << " " << 1;
                    for (int i=0;i<c;++i) cout << " " << 3;
                    for (int i=0;i<b-c;++i) cout << " " << 1;
                }
            } else {
                for (int i=0;i<a-c;++i) cout << " " << 1;
                for (int i=0;i<c - 1;++i) cout << " " << 2;
                for (int i=0;i<n-a-b+c;++i) cout << " " << 1;
                cout << " " << 2;
                for (int i=0;i<b-c;++i) cout << " " << 1;
            }
        }
        cout << endl;
    }

    
    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */