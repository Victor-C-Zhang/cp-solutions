//
// Created by victor on 1/16/19.
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

    int n,m,a,b;
    cin >> n >> m;
    vvi out(n+1);
    vi in(n+1);
    fill(in.begin(),in.end(), 0);
    while (m--){
        cin >> a >>b;
        out[a].pb(b);
        in[b]++;
    }
    priority_queue<int, vi,greater<>> kahn;
    for (int i=1;i<=n;i++){
        if (in[i]==0) kahn.p(i);
    }
    vi ans;
    while (!kahn.empty()){
        a = kahn.top();
        kahn.pop();
        ans.pb(a);
        for (int i: out[a]) {
            in[i]--;
            if (in[i]==0) kahn.p(i);
        }
    }
    if (ans.size()!=n) cout << "Sandro fails." << endl;
    else {
        for (int i: ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}