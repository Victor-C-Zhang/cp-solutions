//
// Created by victor on 12/18/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
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

    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        char c = s[0];
        bool tag = false;
        for (int i=1;i<s.length();i++){
            if (s[i]!=c){
                tag = true;
                break;
            }
        }
        if (!tag){
            cout << -1 << endl;
        }
        else {
            sort(s.begin(),s.end());
            cout << s << endl;
        }
    }
}