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

    int n,m; cin >> n >> m;
    int arr[m][5];
    char c;
    for (int i=0;i<m;++i)
        for (int j=0;j<5;++j) arr[i][j] = 0;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            cin >> c;
            arr[j][c-'A']++;
        }
    }
    for (int i=0;i<m;++i) sort(arr[i],arr[i]+5);
    int ans = 0, k;
    for (int i=0;i<m;++i){
        cin >> k;
        ans+=k*arr[i][4];
    }
    cout << ans << endl;
}
