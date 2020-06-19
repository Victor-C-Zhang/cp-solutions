//
// Created by victor on 4/28/19.
//

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int ca=1;ca<=T;ca++){
        int p,q; cin >> p >> q;
        int n = q+2;
        int prex1[n], prey1[n], prex2[n], prey2[n];
        fill(prex1,prex1+n,0);
        fill(prey1,prey1+n,0);
        fill(prex2,prex2+n,0);
        fill(prey2,prey2+n,0);
        vi north, south,west,east;
        while (p--){
            int x,y; string s;
            cin >> x >>y >>s;
            switch (s[0]){
                case'N': north.pb(y);
                    break;
                case 'S': south.pb(y);
                    break;
                case'E': east.pb(x);
                    break;
                case 'W': west.pb(x);
                    break;
            }

        }
        for (int i: north){
            prey1[i+1]++;
            prey1[n-1]--;
        }
        for (int i=1;i<n;i++){
            prey1[i]=prey1[i]+prey1[i-1];
        }

        for (int i: south){
            prey2[0]++;
            prey2[i]--;
        }
        for (int i=1;i<n;i++){
            prey2[i]=prey2[i]+prey2[i-1];
        }

        for (int i: east){
            prex1[i+1]++;
            prex1[n-1]--;
        }
        for (int i=1;i<n;i++){
            prex1[i]=prex1[i]+prex1[i-1];
        }

        for (int i: west){
            prex2[0]++;
            prex2[i]--;
        }
        for (int i=1;i<n;i++){
            prex2[i]=prex2[i]+prex2[i-1];
        }

        int x = LONG_LONG_MAX, y = LONG_LONG_MAX, maxx = LONG_LONG_MIN, maxy = LONG_LONG_MIN;
        int prex[n], prey[n];
        fill(prex,prex+n,0); fill(prey,prey+n,0);
        for (int i=0;i<=q;i++){
            prex[i]=prex1[i]+prex2[i];
            prey[i]= prey1[i]+prey2[i];
            if (prey[i]>maxy) {
                y = i;
                maxy = prey[i];
            }
            if (prex[i]>maxx) {
                x = i;
                maxx = prex[i];
            }
        }
        cout << "Case #" << ca << ": "<< x << " "<<y << endl;
    }
}
