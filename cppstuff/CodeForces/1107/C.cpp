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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    vi arr;
    for (int i=0;i<n;i++){
        int a; cin >> a;
        arr.pb(a);
    }
    string s;
    cin >> s;
    s+='0';
    int ans = 0;
    char c = s[0];
    int pta = 0, ptb = pta;
    for (int i=1;i<=n;i++){
        if (s[i]==c) ptb=i;
        else {
            c = s[i];
            sort(arr.begin()+pta, arr.begin()+ptb+1, greater<>());
            if (k>=ptb+1-pta) {
                for (int j=pta; j<=ptb;j++){
                    ans+=arr[j];
                }
            }
            else {
                for (int j=pta; j<pta+k;j++){
                    ans+=arr[j];
                }
            }
            pta = ptb+1;
            ptb = pta;
        }
    }
    cout << ans << endl;
}
