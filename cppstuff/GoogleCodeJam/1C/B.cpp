//
// Created by victor on 5/4/19.
//

#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,F; cin >> T >> F;
    string A;
    int master[5] = {24,6,2,1};
    for (int ca = 1; ca<=T;ca++){
        int freq[5][5];
        for (int i=0;i<5;i++){
            for (int j=0;j<5;j++)
                freq[i][j] = 0;
        }
        vector<vvi> arr(5, vvi(5));
        for (int i=0;i<119;i++) arr[0][0].pb(i);
        int targ = 0;
        int ans[4];
        for (int j=0;j<4;j++){
            for (int i: arr[j][targ]){
                cout << i*5+j+1 << endl;
                cin >> A;
                arr[j+1][(int)(A[0])-'A'].pb(i);
                freq[j][(int)(A[0])-'A']++;
            }
            for (int i=0;i<5;i++){
                if (freq[j][i]<master[j]) {
                    targ = i; break;
                }
            }
            for (int i=j+1;i<5;i++) freq[i][targ] = INT_MAX;
            ans[j] = targ;
        }
        for (int i=0;i<4;i++){
            cout << (char)('A'+ans[i]);
        }
        int one = 120;
        for (int i: ans) one/=i+1;
        cout << (char)('A'+one-1) << endl;
        cin >> A;
        if (A[0]=='N') return 0;
    }
}

