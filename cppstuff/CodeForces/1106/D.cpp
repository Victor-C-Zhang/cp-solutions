//
// Created by victor on 2/8/19.
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

    int n,m;
    cin >> n >>m;
    vvi graph(n+1);
    while (m--){
        int a,b;
        cin >> a >>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bool touch[n+1];
    fill (touch,touch+n+1,false);
    priority_queue<int, vi, greater<>> pq;
    touch[1] = true;
    cout << 1;
    for (int i: graph[1]) if (!touch[i]) pq.p(i);
    n--;
    while (n>0){
        int a = pq.top();
        pq.pop();
        if (!touch[a]){
            n--;
            touch[a] = true;
            cout << " " << a;
            for (int i: graph[a]) if (!touch[i]) pq.p(i);
        }
    }
    cout << endl;
}
