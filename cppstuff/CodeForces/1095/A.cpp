//
// Created by victor on 12/27/18.
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
#define zp mp(0, 0)


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;
    cin >> n>> s;
    int ptr = 0;
    for (int i=1;i<=10&&ptr<n;i++){
        cout << s[ptr];
        ptr+=i;
    }
    cout << endl;
}