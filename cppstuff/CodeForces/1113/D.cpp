//
// Created by victor on 2/16/19.
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

bool checkPal(string s){
    int a=0,b=s.size()-1;
    while (a<=b){
        if (s[a]!=s[b]) return false;
        a++; b--;
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    int n = s.size();
    char c = s[0];
    bool imp = true;
    for (int i=0;i<s.size();i++){
        if (s[i]!=c) {
            imp = false;
            break;
        }
    }
    if (imp){
        cout << "Impossible" << endl;
        return 0;
    }
    string t = s;
    for (int i=0;i<n;i++){
        t = t.substr(1,n-1)+t[0];
        if (t==s) continue;
        if (checkPal(t)) {
            cout << 1 << endl;
            return 0;
        }
    }
    for (int i=0;i<(n-1)/2;i++){
        if (s[i]!=c) {
            cout << 2 << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
}
