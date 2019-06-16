//
// Created by victor on 6/16/19.
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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,a,b; cin >>n >>m;
    vvi graph(n+1);
    vector<pi> ans;
    while (m--) {
        cin >> a >> b;
        ans.pb({a,b});
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int arr[n+1];
    fill(arr,arr+n+1, -1); //0 == sink, 1 == source;
    queue<int> q;
    bool touch[n+1];
    fill(touch,touch+n+1,0);
    q.p(1);
    arr[1] = 0;
    touch[1] = 0;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        if (touch[node]) continue;
        touch[node] = 1;
        for (int i: graph[node]){
            if (arr[i]==arr[node]) {
                cout << "NO" << endl;
                return 0;
            }
            arr[i] = !arr[node];
            if (!touch[i]) q.p(i);
        }
    }
    cout << "YES" << endl;
    for (pi pa: ans){
        if (arr[pa.f]>arr[pa.s]) cout << 1;
        else if (arr[pa.f]<arr[pa.s]) cout << 0;
        else cout << -1;
    }
    cout << endl;
}
