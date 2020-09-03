// WA
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

void prop(vvi& graph, int node, bool* touch, int* dp) {
    touch[node] = 1;
    dp[node] = 1;
    for(auto child: graph[node]) {
        if (!touch[child]) {
            prop(graph, child, touch, dp);
            dp[node]+=dp[child];
        }
    }
}

void traverse(vvi& graph, int node, bool* touch, int* dp, vi& edges, int n) {
    touch[node] = 1;
    for(auto child: graph[node]) {
        if (!touch[child]) {
            edges.pb((dp[child]*(n-dp[child]))%mod);
            traverse(graph, child, touch, dp, edges, n);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vvi graph(n+1);
        int dp[n+1];
        bool touch[n+1];
        fill(touch, touch + n + 1, 0);
        for (int i=1;i<n;++i) {
            int a,b; cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        int m; cin >> m;
        int nums[m];
        for (int i=0;i<m;++i) cin >> nums[i];
        prop(graph, 1, touch, dp);
        fill(touch, touch + n + 1, 0);
        vi edges;
        traverse(graph, 1, touch, dp, edges, n);
        sort(edges.begin(), edges.end(), greater<int>());
        sort(nums, nums+m, greater<int>());
        int ans = 0;
        if (m > n - 1) {
            int squeeze = m-(n-1);
            vi pressed;
            pressed.pb(1);
            for (int i=0;i<=squeeze;++i) {
                pressed[0]*=nums[i];
                pressed[0]%=mod;
            }
            for (int i=1;i<n-1;++i) {
                pressed.pb(nums[i+squeeze]);
            }
            for (int i=0;i<n-1;++i) {
                ans += pressed[i]*edges[i];
                ans %= mod;
            }
        } else {
            int j = 0;
            for (;j<m;++j) {
                ans += edges[j]*nums[j];
                ans%=mod;
            }
            for (;j<n-1;++j) {
                ans += edges[j];
                ans%=mod;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

/* List of CP snippets:
 *
 * cp-header (standard header)
 */
