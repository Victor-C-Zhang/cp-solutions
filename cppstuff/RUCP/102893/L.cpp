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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ca; cin >> ca;
    while (ca--) {
      int n,w; cin >> n >> w;
      int a,b;
      int arrc[n];
      int arrw[n];
      pair<double,int> cpw[n]; // cost per weight
      for (int i = 0; i < n; ++i) {
        cin >> arrw[i] >> arrc[i];
        cpw[i] = {(double)arrc[i]/arrw[i], i};
      }
      sort(cpw,cpw+n,greater<pair<double,int>>());
      vector<int> ans;
      int currw = 0;
      for (int i = 0; i < n; ++i) {
        if (currw + arrw[cpw[i].second] > w*3/2) continue;
        currw += arrw[cpw[i].second];
        ans.push_back(cpw[i].second);
      }
      sort(ans.begin(),ans.end());
      cout << ans.size() << endl;
      for (auto& i : ans) cout << i+1 << " ";
      cout << endl;
    }  
    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */