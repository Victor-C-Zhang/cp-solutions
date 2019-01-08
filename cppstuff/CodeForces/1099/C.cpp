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
    int n;
    cin >> s >> n;
    vi candy, snow;
    for (int i=0;i<s.size();i++){
        if (s[i]=='?') candy.pb(i);
        else if (s[i]=='*') snow.pb(i);
    }
    int ssize = s.size()-candy.size()-snow.size();
    if (ssize<n && snow.empty()) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (ssize-candy.size()-snow.size()>n){
        cout << "Impossible" << endl;
        return 0;
    }
    if (ssize<n) {
        int a = n-ssize;
        for (int i=0;i<s.size();i++){
            if (i==snow[0]){
                for (int j=0;j<a;j++){
                    cout << s[i-1];
                }
            }
            else if (s[i]!='?' && s[i]!='*') cout << s[i];
        }
        cout << endl;
    }
    else if (ssize>=n) {
        int a = ssize-n;
        for (int i=0;i<s.size()-1;i++){
            if ((s[i+1]=='?' ||s[i+1]=='*') && a>0){
                a--;
                i++;
            }
            else if (s[i]!='?' && s[i]!='*') cout << s[i];
        }
        if (s[s.size()-1]!='?' && s[s.size()-1]!='*') cout << s[s.size()-1] << endl;
    }
}