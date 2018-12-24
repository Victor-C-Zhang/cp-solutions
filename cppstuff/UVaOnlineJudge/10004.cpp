//
// Created by victor on 12/22/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define f first
//#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)

typedef long long ll;
typedef long double ld;

queue<int> q;
vvi graph;
vector<bool> touch;
vi color;

bool bfs(int node){
    if (!touch[node]) touch[node] = true;
    for (auto i : graph[node]){
        if (!touch[i]){
            color[i] = !color[node];
            q.p(i);
        }
        else {
            if (color[node] == color[i]) return false;
        }
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n;
    while (n!=0){
        cin >> l;
        vvi graf(n,vi(0));
        for (int i=0;i<l;i++){
            int a,b;
            cin >> a>>b;
            graf[a].pb(b);
            graf[b].pb(a);
        }
        graph = graf;
        vector<bool> tuch(n,false);
        touch = tuch;
        vi culur(n,-1);
        color = culur;
        color[0] = 1;
        bool sent=true;
        bfs(0);
        while (q.size()!=0){
            if(! bfs(q.front())){
                sent = false;
                break;
            }
            q.pop();
        }
        if (sent) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
        cin >> n;
    }
}