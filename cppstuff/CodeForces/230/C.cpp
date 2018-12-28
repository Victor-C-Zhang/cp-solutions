//
// Created by victor on 12/26/18.
//

#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
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
#define zp mp(0, 0)

const int N = 107;
vvi dp(N);

int binsearch(int row, int col){
    int l=0,r=dp[row].size()-1,mid;
    while (l<r){
        mid = (l+r)/2;
        if (dp[row][mid] == col) return col;
        if (dp[row][mid]>col) r = mid;
        else l = mid + 1;
    }
    if (col - dp[row][l-1] > dp[row][l] - col) return dp[row][l];
    else return dp[row][l-1];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        for (int j=0;j<s.size();j++){
            if (s[j]=='1') dp[i].pb(j-s.size());
        }
        for (int j=0;j<s.size();j++){
            if (s[j]=='1') dp[i].pb(j);
        }
        for (int j=0;j<s.size();j++){
            if (s[j]=='1') dp[i].pb(j+s.size());
        }
    }
    for (int i=0;i<n;i++){
        if (dp[i].size()==0) {
            cout << -1 << endl;
            return 0;
        }
    }
//    for (int i=0;i<n;i++){
//        for (auto j: dp[i]) cout << j << " ";
//        cout << endl;
//    }
//    for (int i=0;i<10;i++){
//        int row, col;
//        cin >> row >> col;
//        cout << binsearch(row,col) << endl;
//    }

    int mini = INT_MAX;
    for (int i=0;i<m;i++){
        int ans = 0;
        for (int j=0;j<n;j++){
            ans+=abs(i-binsearch(j,i));
        }
        mini = min(mini,ans);
    }
    cout << mini << endl;

}