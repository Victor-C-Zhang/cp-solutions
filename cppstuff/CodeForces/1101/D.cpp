//
// Created by victor on 4/24/19.
//

//unfinished
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long int
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

const int N = 2e5+7;
bool prime[N];
vi vs;
vector<set<int>> facts(N);
void sieve()
{
    for(int i = 2; i < N; i++) prime[i] = 1;

    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            vs.pb(i);
            facts[i].insert(i);
            for(int j = i * i; j < N; j += i) {
                prime[j] = 0;
                facts[j].insert(i);
            }
        }
    }
}
int maxi = 0;
vvi graph(N+1);
vi verts;
bool touch[N];
int find(int node, int prime){
    touch[node] = 1;
    int maxi = 0;
    for (int i: graph[node]) if (!touch[node]) maxi = max(maxi,find(i,prime));
    if (facts[node].find())
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    int n;
    cin >> n;

    verts.pb(0);
    for (int i=1;i<=n;i++) {
        int a; cin >> a; verts.pb(a);
    }
    for (int i=1;i<n;i++){
        int a,b; cin >> a >>b;
        graph[a].pb(b); graph[b].pb(a);
    }
    int dp[n+1][vs.size()];

}