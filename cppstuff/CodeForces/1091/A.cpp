//
// Created by victor on 1/5/19.
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

    int a,b,c,ans=0;
    cin >> a >>b >>c;
    b-=1;
    c-=2;
    int mini = min(a,min(b,c));
    if (mini ==a){
        cout << a*3+3 << endl;
    }
    else if (mini==b){
        cout << b*3+3<<endl;
    }
    else cout << c*3+3 << endl;
}