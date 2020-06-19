//
// Created by victor on 11/18/19.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
//#define p push
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
    vvi colors(3,vi(n));
    for (int i=0;i<n;++i){
        cin >> colors[0][i];
    }
    for (int i=0;i<n;++i){
        cin >> colors[1][i];
    }
    for (int i=0;i<n;++i){
        cin >> colors[2][i];
    }
    vvi graph(n+1,vi());
    int a,b;
    for (int i=1;i<n;++i){
        cin >> a >>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int head = -1, tail = -1;
    for (int i=1;i<=n;++i)
        if (graph[i].size()==1) {
            if (head==-1) head = i;
            else if (tail == -1) tail = i;
            else {
                cout << -1 << endl;
                return 0;
            }
        }

    vector<pair<int,int> > order;
    int node;
    order.pb({head,0});
    node = graph[head][0];
    while(true) {
        order.pb({node,0});
        if (node == tail) break;
        if (graph[node][0]==order[order.size()-2].f) node = graph[node][1];
        else node = graph[node][0];
    }
    int ans = LONG_LONG_MAX;
    int best = -1;
    vvi permut = {
            {0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}
    };
    for (int ca=0;ca<6;++ca){
        int temp = 0;
        for (int i=0;i<n;++i){
            temp+=colors[permut[ca][i%3]][order[i].f-1];
        }
        if (temp<ans){
            ans = temp;
            best = ca;
        }
    }
    cout << ans << endl;
    for (int i=0;i<n;++i){
        order[i].s = permut[best][i%3];
    }
    sort(order.begin(),order.end());
    for (int i=0;i<n;++i)
        cout << order[i].s+1 << " ";
    cout << endl;
    return 0;
}