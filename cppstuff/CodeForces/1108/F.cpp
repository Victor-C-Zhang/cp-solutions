//
// Created by victor on 1/23/19.
//


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
#define ppi pair < int,pair <int, int>  >
#define pppi pair<ppi,int>

const int N = 200007;
vector<vector<pi>> graph(N); //cost, connection
vi parent(N);
vi rnk(N);

int findparent(int node){
    int a = node;
    while (parent[a]!=a) a = parent[a];
    parent[node] = a;
    return a;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    int a,b,c;
    priority_queue<ppi, vector<ppi>,greater<>> edges;
    while (m--){
        cin >> a >> b >>c;
        graph[a].pb({c,b});
        graph[b].pb({c,a});
        edges.p({c,{a,b}});
    }
    int ans = 0;
    fill(rnk.begin(), rnk.end(),1);
    for (int i=0;i<N;i++){
        parent[i] = i;
    }
    int last = -1;
    while (!edges.empty()){
        ppi fill = edges.top();
        vi edge = {fill.f,fill.s.f,fill.s.s};
        edges.pop();
        int para = findparent(edge[1]);
        int parb = findparent(edge[2]);
        if (para !=parb){
            if (rnk[para]>rnk[parb]){
                parent[parb] = para;
                rnk[para]++;
            }
            else {
                parent[para] = parb;
                rnk[parb]++;
            }
            last = edge[0];
        }
        else if (last == edge[0]) {
            ans++;
            edges.p({edge[0]+1,{edge[1],edge[2]}});
        }
    }
    cout << ans << endl;
}