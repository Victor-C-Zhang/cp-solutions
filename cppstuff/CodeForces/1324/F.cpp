#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
// #define int long long int
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

vvi tree(200003);
bool color[200003];
int diff[200003];
int ans[200003];
// bool touch[200003];

int prop(int node, int parent  = -1) {
    int ans = (color[node]) ? 1 : -1;
    for (int child: tree[node]) {
        if (child==parent) continue;
        ans+=max(prop(child,node),0);
    }
    return diff[node] = ans;
}

void prop2(int node, int parent = -1) {
    ans[node] = diff[node];
    for (int child: tree[node]){
        if (child==parent) continue;
        diff[node]-= max(0,diff[child]);
        diff[child]+=max(0,diff[node]);
        prop2(child,node);
        diff[child]-=max(0,diff[node]);
        diff[node]+= max(0,diff[child]);
    }
}

signed main(){
    
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> color[i];
    int a,b;
    for (int i=1;i<n;++i) {
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    prop(1);
    prop2(1);

    for (int i=1;i<=n;++i) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */