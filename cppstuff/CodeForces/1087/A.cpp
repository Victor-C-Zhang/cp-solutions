//
// Created by victor on 12/23/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
#define p push
#define pb push_back
#define f first
//#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)

typedef long long ll;
typedef long double ld;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    string t = "";
    int pnt = 0;
    int pt = s.size()-1;
    if (s.size()%2==1){
        t+= s[0];
        pnt++;
    }
    while (pt>pnt){
        t+= s[pt];
        t+= s[pnt];
        pt--;
        pnt++;
    }
    for (int i=0;i<t.size();i++){
        cout << t[t.size()-1-i];
    }
    cout << endl;
}