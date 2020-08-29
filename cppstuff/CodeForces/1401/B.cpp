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
 
// std::random_device dev;
// std::mt19937 rng(dev());
// std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t; cin >> t;
    while (t--) {
        int x1,y1,z1, x2,y2,z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int ans = 0;
        if (z1 >= y2) {
            ans += 2*y2;
            z1 -= y2;
            if (z2 > z1) {
                z2 -= z1;
                if (z2 > x1) ans-= 2*(z2 - x1);
            }
        } else {
            ans+= 2*z1;
            y2 -= z1;
            if (z2 > x1) {
                ans -= 2*(z2 - x1);
            }
        }
        cout << ans << endl;
    }
 
    return 0;
}
 
 
/* List of CP snippets:
 *
 * cp-header (standard header)
 */