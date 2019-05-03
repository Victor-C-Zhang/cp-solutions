//
// Created by victor on 4/24/19.
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

struct less_than_key
{
    inline bool operator() (const pi& struct1, const pi& struct2)
    {
        return (struct1.s < struct2.s);
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        pi arr[n];
        pi sorted[n];
        int post[n];
        for (int i=0;i<n;i++){
            int a,b; cin >> a >>b;
            arr[i] = {a,b};
            sorted[i] = {a,b};
        }
        sort(sorted, sorted+n, less_than_key());
        for (int i=0;i<n;i++) post[i] = sorted[i].f;
        for (int i=n-2;i>-1;i--) post[i] = min(post[i+1],post[i]);
        int right = -1;
        for (int i=0;i<n-1;i++) {
            if (sorted[i].s < post[i+1]) {
                right = sorted[i].s;
                break;
            }
        }
        if (right == -1) cout << -1 << endl;
        else {
            for (pi pair1: arr) cout << ((pair1.s>right) ? 2 : 1) << " ";
            cout << endl;
        }
    }
}
