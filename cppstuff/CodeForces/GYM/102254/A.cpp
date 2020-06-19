//
// Created by victor on 3/6/20.
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

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

const int N = 2007;
vvi graph(N,vi());

bool touch[N];
queue<pi> q;

int ans = -1;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b; cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    for (int i=1;i<=n;++i) {
        memset(touch,0,N*sizeof(bool));
        q.push({i,0});
        touch[i] = true;
        while (!q.empty()) {
            pi tr = q.front();
            q.pop();
            if (tr.second > ans) ans = tr.second;
            for(int node: graph[tr.first]) {
                if (!touch[node]) {
                    touch[node] = true;
                    q.push({node, tr.second + 1});
                }
            }
        }
        for (int j=1;j<=n;++j)
            if (!touch[j]) {
                cout << "=[" << endl;
                return 0;
            }
    }

    cout << "=] " << ans << endl;

    return 0;
}