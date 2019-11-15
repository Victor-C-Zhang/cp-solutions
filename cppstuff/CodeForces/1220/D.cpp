//
// Created by victor on 9/18/19.
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

int count(int a){
    int ans = 0;
    while (a%2==0) {
        ans++;
        a/=2;
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int a;
    int twos[64];
    fill(twos,twos+64,0);
    vvi lists(64);
    for (int i=0;i<n;++i) {
        cin >> a;
        int ba = count(a);
        twos[ba]++;
        lists[ba].pb(a);
    }
    int ptr = -1, cn = -1;
    for (int i=0;i<64;++i){
        if (twos[i]>cn) {
            cn = twos[i];
            ptr = i;
        }
    }
    cout << n-lists[ptr].size() << endl;
    for (int i=0;i<64;++i){
        if (i==ptr) continue;
        for (int j: lists[i]) cout << j << " ";
    }
    cout << endl;
}
