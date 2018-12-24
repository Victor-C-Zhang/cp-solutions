//
// Created by victor on 12/18/18.
//

//segfault :(((((

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
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
vi arr;
vector<bool> touch;
int counter[2];

int bfs(int node){
    if (!touch[node]) touch[node] = true;
    for (int i: graph[node]){
        if (touch[i]) {
            if (arr[node]==arr[i]) return -1;
        }
        else {
            arr[i] = !arr[node];
            counter[!arr[node]]++;
            q.p(i);
        }
    }
    return arr[node];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int pow2s[300007];
    pow2s[0] = 1;
    for (int i=1;i<300007;i++){
        pow2s[i] = (pow2s[i-1]*2) % mod;
    }

    int t;
    cin >> t;
    for (int ca = 0;ca <t;ca++){
        int n,m;
        cin >> n >> m;
        vvi graph1(n+1);
        for (int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            graph1[a].pb(b);
            graph1[b].pb(a);
        }
        vi arr1;
        for (int i=0;i<=n;i++){
            arr1.pb(-1);
        }
        vector<bool> touch1;
        for (int i=0;i<=n;i++){
            touch1.pb(false);
        }
        touch = touch1;
        arr = arr1;
        graph = graph1;
        int ans = 1;
        bool flag = false;
        for (int it = 1;it<=n;it++) {
            if (touch[it]) continue;
            counter[0] = 1;
            counter[1] = 0;
            int root = it;
            arr[root] = 0;
            bfs(root);
            while (q.size() != 0) {
                int i = bfs(q.front());
                q.pop();
                if (i == -1) {
                    cout << 0 << endl;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            int ba = 0;
            ba+=pow2s[counter[0]];
            if (counter[1]!=0) ba+=pow2s[counter[1]];
            ba %=mod;
            ans*= ba;
            ans%=mod;
        }
        if (!flag) cout << ans << endl;
    }
}