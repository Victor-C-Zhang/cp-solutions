//
// Created by victor on 1/5/20.
//

#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
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

    map<int,int> counter;
    int n,k; cin >> n >> k;
    int x,y;
    for (int i=1;i<=k+1;++i) {
        cout << "?";
        for (int j=1;j<=k+1;++j) {
            if (j==i) continue;
            cout << " " << j;
        }
        cout << endl;
        cin >> x >> y;
        counter[y]++;
    }
    for (auto pa : counter) {
        x = pa.s;
    }
    cout << "! " << x << endl;
    return 0;
}