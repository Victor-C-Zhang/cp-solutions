//
// Created by victor on 1/5/20.
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

    int ca; cin >> ca;
    while (ca--){
        int n,b,c; cin >> n >> b >> c;
        int x,y;
        while (b--) {
            cin >> x;
            if (x==n) cout << "YES" << endl;
        }
        while (c--) {
            cin >> y;
            if (y==n) cout << "NO" << endl;
        }
    }

    return 0;
}