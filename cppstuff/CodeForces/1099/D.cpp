//
// Created by victor on 1/7/19.
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

const int N = 100007;
vvi graph(N);
//bool touch[N];
int sum[N];
int sumcp[N];
int val[N];


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i=2;i<=n;i++){
        int a;
        cin >> a;
        //graph[i].pb(a);
        graph[a].pb(i);
    }
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        sumcp[i] = a;
        sum[i] = a;
    }

    queue<int> q;
    val[1] = sum[1];
    for (int i: graph[1]) {
        sum[i] = sum[1];
        q.p(i);
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        if (sumcp[node]!=-1) {
            if (sumcp[node]<sum[node]) {
                cout << -1 << endl;
                return 0;
            }
            val[node] = sumcp[node]-sum[node];
            sum[node] = sumcp[node];
            for (int i: graph[node]){
                sum[i] = sum[node];
                q.p(i);
            }
        }
        else {
            int a = INT_MAX;
            for (int i: graph[node]){
                a = min(a, sumcp[i]);
            }
            if (a<sum[node]) {
                cout << -1 << endl;
                return 0;
            }
            if (a==INT_MAX) {
                val[node] = 0;
                continue;
            }
            val[node] = a-sum[node];
            sum[node]=a;
            for (int i:graph[node]){
                sum[i] = sum[node];
                q.p(i);
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        ans+=val[i];
    }
    cout << ans << endl;
}