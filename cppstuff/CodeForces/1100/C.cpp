//
// Created by victor on 1/13/19.
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

    double PI = 3.14159265358979;
    int n,r;
    cin >> n >>r;
    double k = 1-cos(2*PI/n);
    double a=2-k,b=-1*2*r*k,c=-1*r*r*k;
    double ans = (-1*b+sqrt(b*b-4*a*c))/(2*a);
    cout << setprecision(17)<< ans << endl;
}
