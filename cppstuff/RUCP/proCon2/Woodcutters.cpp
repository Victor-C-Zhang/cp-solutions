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


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> trees;
    for (int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        trees.pb(mp(a,b)); //location, height
    }
    int furthest = trees.at(0).f;
    int cnt = min(2,n);
    for (int i = 1;i<n-1;i++){
        if (trees.at(i).f - trees.at(i).s > furthest) {
            cnt++;
            furthest = trees.at(i).f;
        }
        else if (trees.at(i).f + trees.at(i).s < trees.at(i+1).f) {
            cnt++;
            furthest = trees.at(i).f + trees.at(i).s;
        }
        else furthest = trees.at(i).f;
    }
    cout << cnt;
}