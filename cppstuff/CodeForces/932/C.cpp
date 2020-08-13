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

    int n,a,b; cin >> n >> a >> b;
    int numa = 0, numb;
    while (n - numa*a >=0) {
        if ((n - numa*a)%b) ++numa;
        else break;
    }
    if ((numb = n-numa*a) < 0) {
        cout << -1 << endl;
        return 0;
    }
    numb/=b;
    int i = 1;
    vi ans;
    while (numa--) {
        for (int j= i+1; j<i+a;++j) cout << j << " ";
        cout << i << " ";
        i+=a;
    }
    while (numb--) {
        for (int j= i+1; j<i+b;++j) cout << j << " ";
        cout << i << " ";
        i+=b;
    }
    cout << endl;

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */