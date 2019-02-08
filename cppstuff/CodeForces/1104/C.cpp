//
// Created by victor on 1/22/19.
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

    string s;
    cin >> s;
    int a=1,b=1;
    for (int i=0;i<s.size();i++){
        if (s[i]=='0'){
            cout << a << " 1" << endl;
            if (a==1) a=3;
            else a=1;
        }
        if (s[i]=='1') {
            cout << b << " 3" << endl;
            if (b==4) b=1;
            else b++;
        }
    }
}