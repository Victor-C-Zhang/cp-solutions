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

  int n,m,s; cin >> n >> m >> s;
  int a;
  set<int> MM;
  vector<int> M;
  for (int i = 0; i < m; ++i) {
    cin >> a;
    MM.insert(a);
  }
  for (auto &i : MM) M.push_back(i);
  sort(M.begin(), M.end());
  int ans = 0;
  for (int i = 0; i < M.size(); ++i) {
    int minst = (i==0) ? 1 : M[i-1]+1;
    if (i+m-s-1 >= M.size()) continue;
    minst = max(minst, M[i+m-s-1]-m+1);
    int maxst = min(M[i],n-m+1);
    if (minst > maxst) continue;
    ans += maxst-minst+1;
  }
  cout << ans << endl;
  return 0;
}

/* List of CP snippets:
 *
 * cp-header (standard header)
 */
