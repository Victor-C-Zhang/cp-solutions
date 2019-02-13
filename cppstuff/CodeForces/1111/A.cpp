//
// Created by victor on 2/8/19.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define double long double
//#define mod 998244353
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

    string s,t;
    cin >> s >> t;
    set<char> vowel = {'a','e','i','o','u'};
    if (s.size()!=t.size()) {
        cout << "No" << endl;
        return 0;
    }
    for (int i=0;i<s.size();i++){
        if ((vowel.find(s[i])!=vowel.end() && vowel.find(t[i])==vowel.end()) ||
            (vowel.find(t[i])!=vowel.end() && vowel.find(s[i])==vowel.end())) {
            cout <<"No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
