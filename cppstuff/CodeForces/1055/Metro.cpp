//
// Created by victor on 11/10/18.
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
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,s;
    cin >> n >> s;
    int go[n+1], come[n+1];
    for (int i=1;i<=n;i++){
        cin >> go[i];
    }
    for (int i=1;i<=n;i++){
        cin >> come[i];
    }
    if (go[1] == 0) {
        cout << "NO" << endl;
        return 0;
    }
    if (go[s] == 1) {
        cout << "YES" << endl;
        return 0;
    }
    if (come[s]==1) {
        for (int i=s+1;i<=n;i++){
            if (go[i]==1 && come[i] == 1) {
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

