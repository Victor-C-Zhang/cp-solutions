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

    int h,w;
    cin >> w >> h;

    int u1,d1,u2,d2;
    cin >> u1 >> d1 >> u2 >> d2;
    while (h>0){
        w+=h;
        if (h==d1){
            if (w<u1) w=0;
            else w-=u1;
        }
        else if (h==d2) {
            if (w<u2) w=0;
            else w-=u2;
        }
        h--;
    }
    cout << w << endl;
}