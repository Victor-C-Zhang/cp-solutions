//
// Created by victor on 12/28/18.
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
#define zp mp(0, 0)

int twos(int n){
    int t = 1;
    int ans = 0;
    for (int i=0;i<n;i++){
        ans+=t;
        ans%=mod;
        t*=2;
        t%=mod;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = false;
    for (int i=0;i<n;i++){
        if (s[0]!=s[i]) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << twos(n) << endl;
        return 0;
    }
    int ptrl = 0;
    while (s[ptrl]==s[0]) ptrl ++;
    int ptrr = n-1;
    while (s[n-1]==s[ptrr]) ptrr--;
    if (s[0]==s[n-1]){
        int dis = ptrr-ptrl+1;
        int l = ptrl + 1;
        int r = n-ptrr;
        cout << (l*r)%mod << endl;
        return 0;
    }
    int ans = ptrl + n - ptrr;
    ans%=mod;
    cout << ans << endl;
}
