//
// Created by victor on 1/7/19.
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
#define vi vector <char>
#define vvi vector < vector <char> >
#define pi pair <int, int>
#define ppi pair < pair <int, int> , int >
#define pppi pair<ppi,int>




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;
    while (test--){
        int n,m;
        cin >> n >>m;
        int beg,end,cum = 0;
        string a,b;
        for (int i=0;i<n;i++){
            cin >> a >> b;
            beg = (a[0]-'0')*600+(a[1]-'0')*60+(a[3]-'0')*10+(a[4]-'0');
            end = (b[0]-'0')*600+(b[1]-'0')*60+(b[3]-'0')*10+(b[4]-'0');
            cum+=end-beg;
        }
        if (cum>=m*60) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}