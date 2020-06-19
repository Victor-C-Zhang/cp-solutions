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
        int n; cin >> n;
        int arr[n];
        cin >> arr[0];
        int idx = -1;
        for (int i=1;i<n;++i){
            cin >> arr[i];
            if (abs(arr[i]-arr[i-1])>=2) idx = i;
        }
        if (idx != -1) {
            cout << "YES" << endl << idx << " " << idx+1 << endl;

        }
        else cout << "NO" << endl;
    }

    return 0;
}