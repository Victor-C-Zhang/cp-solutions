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

priority_queue<ppi> pq; //
vector<vector<pi>> graph(N);
vi dist(N);
vector<bool> touch(N);
unordered_set<int> special;

void dijkstra(int dis, int node){
    if (!touch[node]) touch[node] = true;
    for (auto i : graph[node]){
        if (!touch[i.f]) {
            pi temp1 = {(int) max(dis,i.s), i};
            ppi temp = {temp1, node};
            pq.p();
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k;
    cin >> n >> m >>k;
    for (int i=0;i<k;i++){
        int a;
        cin >> a;
        special.insert(a);
    }
    for (int i=0;i<m;i++){
        int a,b,c;
        cin >> a >>b >>c;
        if (a==b) continue;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }
    for (int i=0;i<N;i++){
        touch[i] = false;
    }
    for (int i=0;i<N;i++){
        dist[i] = INT_MIN;
    }


}