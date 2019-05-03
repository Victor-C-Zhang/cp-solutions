//
// Created by victor on 3/30/19.
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    bool respec[n+1];
    vvi graph(n+1);
    vi parent(n+1);
    bool leaf[n+1];
    int root;
    fill(leaf,leaf+n+1,1);
    for (int i=1;i<=n;i++){
        int a; bool b;
        cin >> a >> b;
        parent[i] = a;
        if (a==-1) root = i;
        else {
            graph[a].pb(i);
            graph[i].pb(a);
        }
        respec[i] = !b;
    }
    priority_queue<int,vi,greater<int>> bad;
    stack<int> stack1;
    bool touch[n+1];
    fill (touch,touch+n+1,false);
    stack1.p(root);
    touch[root] = 1;
    while (!stack1.empty()){
        int node = stack1.top();
        stack1.pop();
        touch[node] = true;
        bool yes = !respec[node];
        for (int i:graph[node]){
            if (!touch[i])
                if (respec[i]) yes = false;
        }
        if (yes) bad.p(node);
        for (int i:graph[node])
            if (!touch[i]) stack1.p(i);
    }
    if (bad.empty()) cout << -1 << endl;
    else {
        while (!bad.empty()){
            int node = bad.top();
            bad.pop();
            cout << node << " ";
        }
        cout << endl;
    }
}
