//
// Created by victor on 2/13/19.
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
#define ppi pair < pair <int, int> , int >
#define pppi pair<ppi,int>

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin >> n>>m;
    vvi graph(n+1);
    for (int i=0;i<m;i++){
        int a,b; cin >> a >>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vvi depth(n+1);
    depth[1].pb(1);
    vi randdepth(n+1);
    fill(randdepth.begin(),randdepth.end(),0);
    bool touch[n+1];
    fill(touch,touch+n+1,false);
    queue<int> q;
    q.p(1);
    int ptr = -1;
    randdepth[1] = 1;
    while (!q.empty()){
        int a = q.front();
        q.pop();
        if (!touch[a]) touch[a] = true;
        else continue;
        vi temp;
        for (int i: graph[a]){
            if (!touch[i]) {
                q.p(i);
                if (randdepth[i]!=randdepth[a]) {
                    temp.pb(i);
                    randdepth[i] = randdepth[a] + 1;
                    depth[randdepth[a] + 1].pb(i);
                    ptr = randdepth[i];
                }
            }
        }
        graph[a] = temp;
    }
    fill(touch,touch+n+1,false);
    while (ptr--){
        for (int i: depth[ptr]){
            for (int j: graph[i]){
                if (!touch[j]) {
                    touch[i] = true;
                    break;
                }
            }
        }
    }
    cout << ((touch[1]) ? "Vladimir" : "Nikolay") << endl;
}
