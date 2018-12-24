//
// Created by victor on 12/15/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
//#define p push
#define pb push_back
#define f first
#define s second
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
    while (n!=0){
        int x0, y0;
        cin >> x0 >> y0;
        for (int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            if (a==x0 || b == y0) cout << "divisa" << endl;
            else if (a>x0) {
                if (b> y0) cout << "NE" << endl;
                else cout << "SE" << endl;
            }
            else {
                if (b> y0) cout << "NO" << endl;
                else cout << "SO" << endl;
            }
        }
        cin >> n;
    }
}