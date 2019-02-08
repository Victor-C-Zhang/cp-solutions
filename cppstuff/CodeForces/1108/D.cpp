//
// Created by victor on 1/23/19.
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
//#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int> , int >
#define pppi pair<ppi,int>

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;
    vi c(n);
    int ans = 0;
    vector<char> arr = {'R', 'G', 'B'};
    for (int i=0;i<n;i++){
        switch (s[i]){
            case 'R': c[i] = 0;
                break;
            case 'G': c[i] = 1;
                break;
            case 'B': c[i] = 2;
                break;
        }
    }
    for (int i=1;i+1<n;i++){
        if (c[i]==c[i-1]){
            if (c[i]==c[i+1]) c[i] = (c[i]+1)%3;
            else if (c[i+1]==(c[i]+1)%3) c[i] = (c[i]+2)%3;
            else c[i] = (c[i]+1)%3;
            ans++;
        }
    }
    if (c[n-1]==c[n-2]) {
        c[n-1] = (c[n-1]+1)%3;
        ans++;
    }
    cout << ans << endl;
    for (int i=0;i<n;i++){
        cout << arr[c[i]];
    }
    cout << endl;
    return 0;
}