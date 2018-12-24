//
// Created by victor on 11/25/18.
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

const int N = 100001;
const int big = 1000000;
bool touch[N];
int depth[N];
vvi tree;
int dfs(int node){
    touch[node] = true;
    if (tree.at(node).size()==1 && node!=1){
        return depth[node] = 1;
    }
    int ans = 0;
    for (auto i: tree.at(node)){
        if (!touch[i]) ans+=dfs(i);
    }
    return depth[node] = ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vi one, zero;
    tree.pb(zero);
    tree.pb(one);
    for (int i=0;i<N;i++){
        touch[i] = false;
    }
    int n;
    cin >> n;
    if (n==1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i=2;i<=n;i++){
        int a;
        cin >> a;
        tree.at(a).pb(i);
        vi ith;
        ith.pb(a);
        tree.pb(ith);
    }
    dfs(1);
    // debug
//    for (int i=1;i<=n;i++){
//        cout << depth[i] << endl;
//    }
    depth[0] = big;
    for (int i=n+1;i<N;i++){
        depth[i]= big;
    }
    sort(depth,depth+N);
    for (int i=0;i<n;i++){
        cout << depth[i] << " ";
    }
    cout << endl;
}