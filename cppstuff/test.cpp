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
#define zp mp(0, 0)

bool touch[1000007];
int length[1000007];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

void dijkstra(vector<vector<pair<int,int>>> graph, int node, int len){
if (touch[node]) return;
touch[node] = true;
if (len<length[node]) length[node] = len;
for (pair<int,int> edge : graph.at(node)){
if (!touch[edge.s]) q.p(mp(edge.f+length[node], edge.s));
}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int te=0;te<t;te++){
        int v,k;
        cin >> v >> k;
        for (int i=0;i<=v;i++){
            touch[i] = false;
        }
        for (int i=0;i<=v;i++){
            length[i] = INT_MAX;
        }
        vector<vector<pair<int, int>>> graph =
                                        vector<vector<pair<int,int>>>(v+1,vector<pair<int,int>>(0)); //weight, node
        for (int i=0;i<k;i++){
            int a,b,c;
            cin >>a>>b>>c;
            graph.at(a).pb( mp(c,b));
        }
        int start, end;
        cin >> start >> end;
        length[start] = 0;
        dijkstra(graph,start,0);
        while (q.size()!=0){
            pair<int,int> ppp = q.top();
            q.pop();
            dijkstra(graph,ppp.s,ppp.f);
        }
        if (length[end]==INT_MAX) cout << "NO" <<endl;
        else cout << length[end] << endl;
    }

}