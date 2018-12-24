//
// Created by victor on 11/12/18.
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
#define zp mp(0, 0)

//lmao wrong approach
queue<int> q;
bool touch[300007];
int depth[300007];
int maxdepth = 0;
void bfs(int node, vvi tree){
    if (touch[node]) return;
    touch[node] = true;
    for (int i: tree.at(node)){
        if (!touch[i]) {
            depth[i] = depth[node]+1;
            if (depth[i]>maxdepth) maxdepth = depth[i];
            q.p(i);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >>n;
    vvi tree = vvi(n+1,vi(0));
    memset(depth, 0, sizeof(depth));

    for (int i=1;i<n;i++){
        int a,b;
        cin >>a >>b;
        tree.at(a).pb(b);
        tree.at(b).pb(a);
    }
    bfs(1,tree);
    while (q.size()!=0){
        int i = q.front();
        q.pop();
        bfs(i,tree);

    }
    for (int i=1;i<=n;i++){
        cout << depth[i] << endl;
    }
    cout << endl;
}

