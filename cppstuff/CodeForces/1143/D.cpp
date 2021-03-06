//
// Created by victor on 3/30/19.
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
#define vpi vector < pair < set <int>, int > >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > >
#define zp mp(0, 0)

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k; cin >> n >> k;
    int a,b; cin >> a >>b;
    int base = n*k;
    vi nums;
    int maxi = LONG_LONG_MIN, mini=LONG_LONG_MAX;
    for (int i=0;i<n;i++){
        nums.pb(abs(1+a-(i*k+1+b))%base);
        nums.pb(abs(1+a-((i+1)*k+1-b))%base);
        nums.pb(abs(k+1-a - (i*k+1+b))%base);
        nums.pb(abs(k+1-a- ((i+1)*k+1-b))%base);
    }
    for (int i: nums){
        int dd;
        if (i==0) dd = 1;
        else dd = base/gcd(base,i);
        if (dd>maxi) maxi = dd;
        if (dd<mini) mini = dd;
    }
    cout << mini << " " << maxi << endl;
}
