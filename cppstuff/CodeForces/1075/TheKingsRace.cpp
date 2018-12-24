//
// Created by victor on 11/4/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
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



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a , b;
    cin >> n >> a >> b;
    int xa, xb, ya, yb;
    xa = a-1; xb = b-1;
    ya = n-a; yb = n-b;
    int xmoves = min(xa, xb);
    xmoves = xmoves + max(xa-xmoves,xb-xmoves);
    int ymoves = min(ya,yb);
    ymoves = ymoves + max(ya - ymoves, yb - ymoves);
    if (xmoves<=ymoves) cout<< "White" << endl;
    else cout << "Black" << endl;
}


