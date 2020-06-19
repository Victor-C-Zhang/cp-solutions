//
// Created by victor on 11/18/19.
//

//
// Created by victor on 9/4/19.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long int
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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--){
        int h,n; cin >> h >> n;
        vi tops;
        int a, out;
        cin >> a;
        if (a!=h) tops.pb(h);
        tops.pb(a);
        out = a;
        for(int i=1;i<n;++i){
            cin >> a;
            if (out == a+1) out = a;
            else {
                tops.pb(out-1);
                tops.pb(a);
                out = a;
            }
        }
        if (out!=1) tops.pb(out-1);
        vi segments;
        for (int i=0;i<tops.size()-1;++i){
            segments.pb(tops[i]-tops[i+1]);
        }
        segments.pb(tops[tops.size()-1]);

        int ans = 0;
        if (segments.size()==1) {
            cout << ans << endl;
            continue;
        }
        if (segments[0]%2==0) ++ans;
        for (int i=1;i<((int)segments.size())-1;i+=2){
            if (segments[i+1]%2==1) ++ans;
        }
        if (segments.size()%2 ==1 && segments[segments.size()-1]%2) {
            ans= max(ans-1,0);
        }
        cout << ans << endl;
    }

    return 0;
}