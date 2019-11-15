//
// Created by victor on 9/29/19.
//

//
// Created by victor on 9/4/19.
//

#include <bits/stdc++.h>

using namespace std;

#define YES 0
#define ILL 1
#define NO 2
#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
//#define s second
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
vi arr(N);
vector<bool> touch(N);
vvi dp(3,vi(N));
vvi graph(N);

vi recur(int node){
    if (touch[node]) return {dp[YES][node],dp[ILL][node],dp[NO][node]};
    touch[node] = true;
    if (graph[node].size()==1 && node!=1) {
        dp[NO][node] = 0;
        dp[YES][node] = arr[node];
        return {dp[YES][node],dp[ILL][node],dp[NO][node]};
    }
    int no = 0, yes = arr[node], ill = arr[node], ptr = LONG_LONG_MIN;
    bool found = 0;
    for (int succ : graph[node]) {
        if (!touch[succ]) {
            vi temp = recur(succ);
            if (temp[ILL]==LONG_LONG_MIN){
                no+=temp[NO];
                yes+=max(temp[NO]+arr[succ],temp[YES]);
                if (temp[YES] > temp[NO]) {
                    ill+=temp[YES];
                    found = 1;
                }
                else {
                    ill+=temp[NO];
                    if (temp[YES]-temp[NO]>ptr) ptr = temp[YES]-temp[NO];
                }
            }
            else {
                int pret=max(temp[ILL],temp[NO]);
                no+=max(temp[ILL],temp[NO]);
                yes+=max(temp[YES],max(temp[ILL],temp[NO]+arr[succ]));
                if (temp[YES]>pret) {
                    found = 1;
                    ill+=temp[YES];
                }
                else {
                    ill+=pret;
                    if (temp[YES]-pret>ptr) ptr = temp[YES]-pret;
                }
            }
        }
    }
    if (!found) ill+=ptr;
    return {dp[YES][node]=yes,dp[ILL][node]=ill,dp[NO][node]=no};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int ca = 1;ca<=t;++ca){
        int n; cin >> n;
        for (int i=1;i<=n;++i) graph[i].clear();
        for (int i=0;i<3;++i){
            for (int j=0;j<N;++j) dp[i][j] = LONG_LONG_MIN;
        }
        for (int i=1;i<=n;++i) touch[i] = 0;
        for (int i=1;i<=n;++i) cin >> arr[i];
        int a,b;
        for (int i=1;i<n;++i) {
            cin >> a >>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        recur(1);
        cout << "Case #" << ca << ": " << max(dp[NO][1],max(dp[YES][1],dp[ILL][1])) << endl;
    }

}
