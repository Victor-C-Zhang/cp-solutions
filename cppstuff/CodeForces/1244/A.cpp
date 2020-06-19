//
// Created by victor on 11/18/19.
//

//
// Created by victor on 9/4/19.
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

    int t; cin >> t;
    while (t--){
        int a,b,c,d,k; cin >> a >>b >> c >> d >> k;
        int x,y;
        x = (a%c) ? a/c+1 : a/c;
        y = (b%d) ? b/d + 1 : b/d;
        if (x+y>k) cout << -1 << endl;
        else cout << x << " " << y << endl;
    }

    return 0;
}