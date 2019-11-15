//
// Created by victor on 9/18/19.
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

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int arr[n][n];
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin >> arr[i][j];
    int a = arr[0][2], b = arr[1][2];
    int c = gcd(a,b);
    a/=c; b/=c;
    int dif = arr[0][1]/a/b;
    a*=(int)(sqrt(dif)); b*=(int)sqrt(dif);
    vi ans;
    ans.pb(a);
    ans.pb(b);
    for (int i=2;i<n;++i) ans.pb(arr[0][i]/a);
    for (int i=0;i<n;++i) cout << ans[i] << " ";
    cout << endl;
}
