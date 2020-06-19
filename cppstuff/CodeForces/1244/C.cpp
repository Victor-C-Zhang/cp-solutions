//
// Created by victor on 11/18/19.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
//#define p push
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

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,p,w,d; cin >> n >> p >> w >> d;
    int a=0,b=0;
    int x = p%w, y = p%d;
    while(a<d){
        if ((a*w)%d == y) break;
        ++a;
    }
    if (a==d) {
        cout << -1 << endl;
        return 0;
    }

    while(b<w){
        if ((b*d)%w == x) break;
        ++b;
    }
    if (b==w) {
        cout << -1 << endl;
        return 0;
    }
    int sum = a*w + b*d;
    if (sum>p) {
        cout << -1 << endl;
        return 0;
    }
    int ans = (p-sum)/w + a + b;
    if (ans>n) {
        cout << -1 << endl;
        return 0;
    }
    cout << (p-sum)/w + a << " " << b << " " << n-ans << endl;
    return 0;
}