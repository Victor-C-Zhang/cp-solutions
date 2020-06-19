//
// Created by victor on 4/6/19.
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for (int t = 1;t<=N;t++){
        int n; string s;
        cin >> n >> s;
        n = 2*n-2;
        char ans[n];
        for (int i=0;i<n;i++){
            switch (s[i]) {
                case 'S': ans[i] = 'E';
                    break;
                case 'E': ans[i] = 'S';
                    break;
            }
        }
        cout << "Case #" << t << ": ";
        for (int i=0;i<n;i++) cout << ans[i];
        cout << endl;
    }
}