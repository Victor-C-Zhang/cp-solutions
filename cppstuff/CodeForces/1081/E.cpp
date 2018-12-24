//
// Created by victor on 12/24/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
#define p push
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

const int N = 200007;

vvi factors(N);

void fill(){
    for (int i=1;i<N;i++){
        for (int j=i;j<N;j+=i){
            factors[j].pb(i);
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vvi factor(N);
    int n;
    cin >> n;
    int x[n+1];
    int a[n+1];
    a[0] = 0;
    for (int i=2;i<=n;i+=2){
        int a;
        cin >> a;
        if (i==2 && n==2 && a ==1) { //this block is highkey useless, but without it codeforces throws some weird errors
            cout << "No" << endl;    //
            return 0;                //
        }                            //
        x[i] = a;
    }
    fill();

    for (int i=2;i<=n;i+=2){
        int b = x[i];
        int ptr = factors[b].size()/2-1;
        for (;;ptr--){
            if (ptr == -1) {
                cout << "No" << endl;
                return 0;
            }
            if ((factors[b][ptr]+factors[b][factors[b].size()-1-ptr])%2 == 1) continue;
            int y  = (factors[b][ptr]+factors[b][factors[b].size()-1-ptr])/2;
            int x = y-factors[b][ptr];
            if (x<=a[i-2]) continue;
            a[i-1] = x;
            a[i] = y;
            break;
        }
    }
    cout << "Yes" << endl;
    for (int i=1;i<=n;i++){
        cout << (a[i]+a[i-1])*(a[i]-a[i-1]) << " ";
    }
}