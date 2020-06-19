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

    int n; cin >> n;
    vi segments;
    int curr, len = 1;
    char c;
    cin >> c;
    if (c=='A') curr = 0;
    else curr = 1;
    for (int i=1;i<n;++i){
        cin >> c;
        int temp = (c=='A') ? 0 : 1;
        if (temp==curr) ++len;
        else {
            segments.pb(len);
            curr = temp;
            len = 1;
        }
    }
    segments.pb(len);
    int ans = 0;
    for (int i=0;i<segments.size()-1;++i){
        ans+=segments[i]+segments[i+1]-1;
    }
    cout << n*(n-1)/2 - ans << endl;

    return 0;
}