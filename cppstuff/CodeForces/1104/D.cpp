//
// Created by victor on 1/22/19.
//

//UNFINISHED

#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
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

    string s,t;
    cin >> s;
    int l,left,r,mid;
    while (s=="start"){
        l = 1;
        cout << "? 0 " << l << endl;
        cin >> t;
        if (t=="end") return 0;
        if (t=="e") return 0;
        if (t=="mistake") return 0;
        if (t=="x") {
            cout << "! 1" << endl;
            cin >> s;
            continue;
        }
        while (t!="x") {
            cout << "? "<<l << " " <<l*2 << endl;
            l*=2;
            cin >> t;
            if (t=="end") return 0;
            if (t=="e") return 0;
            if (t=="mistake") return 0;
        }
        cout << "? 0 " << l << endl;
        cin >> t;
        if (t=="end") return 0;
        if (t=="e") return 0;
        if (t=="mistake") return 0;
        if (t=="x") {
            cout << "! " << l << endl;
            cin >> s;
            continue;
        }
        r = l;
        l/=2;
        left = l;
        mid = l;
        while (left<r){
            mid = (left+r)/2;
            cout << "? " << l << " " << mid<< endl;
            cin >> t;
            if (t=="end") return 0;
            if (t=="e") return 0;
            if (t=="mistake") return 0;
            if (t=="y") left=mid+1;
            else r=mid;
        }
        //cout << check if y is 0 mod
        cout << "? 0 " << mid << endl;
        cin >> t;
        if (t=="end") return 0;
        if (t=="e") return 0;
        if (t=="mistake") return 0;
        if (t=="x") {
            cout << "! " << mid << endl;
        }
        else cout << "! "<<mid+1 << endl;
        cin >> s;
    }
}