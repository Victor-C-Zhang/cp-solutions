//
// Created by victor on 12/28/18.
//

//fix this crap, use kruskal or prims instead

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define double long double
#define mod 998244353
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int> , int >
#define pppi pair<ppi,int>
#define zp mp(0, 0)

const int N = 200007;

priority_queue<pppi, vector<pppi>, greater<pppi>> pq; //dis, src, node, closedis
vector<vector<pi>> graph(N); //node, closedis
vector<ppi> dist(N); //dis, closedis, src
unordered_set<int> touch;

vector<vector<pi>> mst(N); //node, closedis
queue<pi> q;
bool bfstouch[N];

void dijkstra(int dis, int src, int node, int closedis){
    touch.erase(node);
    if (dis<dist[node].f.f){
        dist[node].f.f = dis;
        dist[node].f.s = closedis;
        dist[node].s = src;
    }
    for (pi pa : graph[node]){
        if (touch.find(pa.f)!=touch.end()) pq.p({{{pa.s+dist[node].f.f,node},pa.f},pa.s});
    }

}

int bfs(int node, int dis){
    bfstouch[node] = true;
    for (pi i: mst[node]){
        if (!bfstouch[i.f]) q.p({i.f, i.s});
    }
    return dis;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int arr[n+1];
    int mini = 0;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        arr[i] = a;
        if (arr[i]<arr[mini]) mini = i;
    }
    int temp = arr[1];
    arr[1] = arr[mini];
    arr[mini] = temp;

    for (int i=2;i<=n;i++){
        graph[1].pb({i,arr[i]+arr[1]});
        graph[i].pb({1,arr[i]+arr[1]});
    }
    for (int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if (a==1) a = mini;
        else if (a==mini) a = 1;
        if (b==1) b = mini;
        else if (b==mini) b = 1;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }
    for (int i=0;i<N;i++){
        dist[i] = {{INT_MAX, 0},0};
    }
    for (int i=1;i<=n;i++){
        touch.insert(i);
    }
    dijkstra(0,0,1,0);
    while (!touch.empty()){
        int a = pq.top().f.f.f;
        int b = pq.top().f.f.s;
        int c = pq.top().f.s;
        int d = pq.top().s;
        pq.pop();
        dijkstra(a,b,c,d);
    }
    for (int i=2;i<=n;i++){
        int a = dist[i].s;
        mst[a].pb({i,dist[i].f.s});
        mst[i].pb({a,dist[i].f.s});
    }
    for (int i=0;i<N;i++){
        bfstouch[i] = false;
    }
    bfs(1,0);
    int ans=0;
    while (!q.empty()){
        int a = q.front().f;
        int b = q.front().s;
        q.pop();
        ans+=bfs(a,b);
    }
    cout << ans << endl;
}
