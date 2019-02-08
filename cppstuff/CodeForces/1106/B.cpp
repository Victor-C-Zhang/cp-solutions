//
// Created by victor on 2/7/19.
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

int disc(char c){
    switch (c) {
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        default: return (c-'0');
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; cin >> n >> m;
    vi arr, prix;
    vector<pi> sortprix;
    arr.pb(0);
    prix.pb(0);
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        arr.pb(a);
    }
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        prix.pb(a);
        sortprix.pb({a,i});
    }
    sort(sortprix.begin(),sortprix.end());
    int ptr = 0;
    while (m--){
        int ans = 0, d,t;
        cin >> t >> d;
        if (d<=arr[t]) {
            arr[t]-=d;
            cout << prix[t]*d << endl;
        }
        else {
            ans +=arr[t]*prix[t];
            d-=arr[t];
            arr[t] = 0;
            while (d>0){
                if (ptr==n) {
                    cout << 0 << endl;
                    break;
                }
                if (d<=arr[sortprix[ptr].s]) {
                    arr[sortprix[ptr].s]-=d;
                    cout << d*prix[sortprix[ptr].s]+ans << endl;
                    break;
                }
                else {
                    ans+=arr[sortprix[ptr].s]*prix[sortprix[ptr].s];
                    d-=arr[sortprix[ptr].s];
                    arr[sortprix[ptr].s] = 0;
                    ptr++;
                }
            }
        }
    }
}
