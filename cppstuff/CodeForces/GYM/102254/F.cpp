//
// Created by victor on 3/7/20.
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

const int N = 100007;
int lk[N], sz[N]; // lk initialized to i, sz initialized to 1
//
//int find(int idx) {
//    int comp = idx;
//    while(idx != lk[idx]) idx = lk[idx];
//    lk[comp] = idx;
//    return idx;
//}

int find(int v) {
    if (v == lk[v])
        return v;
    return lk[v] = find(lk[v]);
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
    a = find(a), b = find(b);
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    lk[b] = a;
}

map<string,int> names;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n; int m; cin >> m;
    for (int i=0;i<N;++i) {
        lk[i] = i;
        sz[i] = 1;
    }

    for (int i=1;i<=n;++i){
        string s; cin >> s;
        names.insert({s,i});
    }

    while (m--){
        int a; string s,t;
        cin >> a >> s >> t;
        if (a==1) unite(names[s],names[t]);
        else {
            if (same(names[s],names[t])) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }

    return 0;
}