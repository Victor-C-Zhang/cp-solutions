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

    string string1;
    cin >> string1;
    vector<char> s;
    for (int i=0;i<string1.size();i++){
        s.pb(string1[i]);
    }
    int n=s.size();
    int ans = 0;
    for (int i=0;i<n-1;i++){
        if (s[i]==s[i+1]) {
            s.erase(s.begin()+i,s.begin()+i+2);
            i-=2;
            n-=2;
            ans++;
        }
    }
    if (ans%2) cout << "Yes" << endl;
    else cout << "No" << endl;

}