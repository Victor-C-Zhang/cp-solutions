//
// Created by victor on 2/22/19.
//

//incorrect way; what if one is dominated by the other

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

    int n;
    cin >> n;
    vi color(n + 1);
    color[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> color[i + 1];
    }
    vvi graph(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int maxdepth = -1;
    vector<pi> depth(n + 1);
    depth[1] = {0,1};
    bool touch[n + 1];
    fill(touch, touch + n + 1, 0);
    queue<int> q;
    q.p(1);
    touch[1] = true;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int i: graph[a]) {
            if (!touch[i]) {
                touch[i] = true;
                depth[i] = {depth[a].f + 1, i};
                if (depth[i].f>maxdepth) maxdepth = depth[i].f;
                q.p(i);
            }
        }
    }
    vi ograph(n+1);
    int redparent, blueparent;
    for (int i=1;i<=n;i++){
        for (int j: graph[i]) if (depth[j]<depth[i]) ograph[i]=j;
    }
    sort(depth.begin(),depth.end(), greater<>());
    int ptr = 0;
    fill(touch,touch+n+1, 0);
    for (int i = maxdepth; i>-1;i--){
        while (ptr<n && depth[ptr].f==i){
            if (color[depth[ptr].s]==1) q.p(depth[ptr].s);
            ptr++;
        }
        if (q.size()==1) {
            redparent = q.front();
            q.pop();
            break;
        }
        while (!q.empty()){
            int a = q.front();
            q.pop();
            if (color[ograph[a]]==2) {
                cout << 0 << endl;
                return 0;
            }
            color[ograph[a]] = 1;
            if (!touch[ograph[a]]) {
                q.p(ograph[a]);
                touch[ograph[a]] = true;
            }
        }
    }
    ptr = 0;
    fill(touch,touch+n+1, 0);
    for (int i = maxdepth; i>-1;i--){
        while (ptr < n && depth[ptr].f==i){
            if (color[depth[ptr].s]==2) q.p(depth[ptr].s);
            ptr++;
        }
        if (q.size()==1) {
            blueparent = q.front();
            q.pop();
            break;
        }
        while (!q.empty()){
            int a = q.front();
            q.pop();
            if (color[ograph[a]]==1) {
                cout << 0 << endl;
                return 0;
            }
            color[ograph[a]] = 2;
            if (!touch[ograph[a]]) {
                q.p(ograph[a]);
                touch[ograph[a]] = true;
            }
        }
    }
    int ans = 0;
    while (redparent!=1) {
        redparent = ograph[redparent];
        ans++;
    }
    while (blueparent!=1) {
        blueparent = ograph[blueparent];
        ans++;
    }
    cout << ans << endl;
}
