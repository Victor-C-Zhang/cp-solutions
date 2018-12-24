//
// Created by victor on 12/24/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)

typedef long long ll;
typedef long double ld;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pi> peep;
    int ans[n];

    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        peep.pb({n-a-1,i});
    }
    sort(peep.begin(), peep.end());
    int cnt = 1;

    for (int i=0;i<n;i++){
        int a = peep[i].f;
        ans[peep[i].s] = cnt;
        for (int j = i+1;j<=i+a;j++){
            if (peep[j].f == a) ans[peep[j].s] = cnt;
            else {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        i+=a;
        cnt++;
    }
    cout << "Possible" << endl;
    for (int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}