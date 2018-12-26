//
// Created by victor on 12/24/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long int
#define mod 998244353
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int> , int >
#define zp mp(0, 0)

typedef long long ll;
typedef long double ld;

const int N = 100007;

priority_queue<pi, vector<pi>, greater<pi> > pq; // (distance, to where)
vector<vector<pi>> graph(N); // to where, weight
vector<int> dist; //distance
unordered_set<int> touch;
vi special;

void dijkstra(int dis, int node){
    touch.erase(node);
    if (dis < dist[node]) {
        dist[node] = dis;
    }

    for (auto i : graph[node]){
        if (touch.find(i.f)!=touch.end()) {
            pq.p({ max(dis, i.s), i.f});
        }
    }
}

//int dfs(int node){
//    if (!touch[node]) touch[node] = true;
//    if (graph[node].size()==1 && node != special[0]) return dist[]
//}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k;
    cin >> n >> m >>k;
    for (int i=0;i<k;i++){
        int a;
        cin >> a;
        special.pb(a);
    }
    for (int i=0;i<m;i++){
        int a,b,c;
        cin >> a >>b >>c;
        if (a==b) continue;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }
    for (int i=1;i<=n;i++){
        touch.insert(i);
    }
    for (int i=0;i<=n;i++){
        dist.pb(INT_MAX);
    }
    dijkstra(0,special[0]);
    while (touch.size()!=0){
        int a = pq.top().f;
        int b = pq.top().s;
        pq.pop();
        dijkstra(a,b);
    }
//    vvi mst(n+1);
//    for (int i=1;i<special.size();i++){
//        int a = dist[i].s;
//        mst[i].pb(a);
//        mst[a].pb(i);
//    }
//    for (int i=0;i<N;i++){
//        touch[i] = false;
//    }

    vi special_dist;
    for (auto i: special){
        special_dist.pb(dist[i]);
    }
    sort(special_dist.begin(),special_dist.end(), greater<>());
    for (int i=0;i<special.size();i++){
        cout << special_dist[0] << " ";
    }
    cout << endl;

}