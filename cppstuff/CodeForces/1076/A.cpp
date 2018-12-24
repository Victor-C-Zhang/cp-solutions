//
// Created by victor on 11/12/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
//#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    string s;
    cin >> s;
    int maxc = n-1;
    for (int i=1;i<n;i++){
        if (s[i]<s[i-1]) {
            maxc = i-1;
            break;
        }
    }
    for (int i=0;i<n;i++){
        if (i!=maxc) cout << s[i];
    }
    cout << endl;
}

