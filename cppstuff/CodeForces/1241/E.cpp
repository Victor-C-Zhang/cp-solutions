//
// Created by victor on 10/6/19.
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

bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    return (a.f>=b.f);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--){
//        int n; cin >> n;
//        int arr[n];
//        for (int i=0;i<n;++i) cin >> arr[i];
//        int x,y,a,b; cin >> x >> a >> y >> b;
//        sort(arr,arr+n,greater());
        int n,k; cin >> n >> k;
        vector<int> nodes(n+1);
        for (int i=0;i<=n;++i) nodes[i] = k;
        int a,b,c;
        vector<pair<int,pair<int,int> > > edges;
        for (int i=1;i<n;++i){
            cin >> a >> b >> c;
            edges.pb({c,{a,b}});
        }
        sort(edges.begin(),edges.end(),comp);
        int ans = 0;
        for (int i=0;i<n-1;++i){
            if (nodes[edges[i].s.f] > 0 && nodes[edges[i].s.s]>0) {
                ans+=edges[i].f;
                --nodes[edges[i].s.f];
                --nodes[edges[i].s.s];
            }
        }
        cout << ans << endl;
    }
}
