//
// Created by victor on 9/29/19.
//

//
// Created by victor on 9/4/19.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int unsigned long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
//#define s second
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

const int N = 8000;
bool prime[N];
vi vs;

void sieve()
{
    for(int i = 2; i < N; i++) prime[i] = 1;

    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            vs.pb(i);
            for(int j = i * i; j < N; j += i) prime[j] = 0;
        }
    }
}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    int t; cin >> t;
    for (int ca=1;ca<=t;++ca){
        int n,s; cin >>n>>s;
        int arr[n];
        int a,b,sum;
        for (int i=0;i<n;++i){
            cin >> a;
            sum =1;
            while (a--) {
                cin >> b;
                sum*=vs[b];
            }
            arr[i] = sum;
        }
        int ans = 0;
        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
                a = gcd(arr[i],arr[j]);
                if (arr[i]>a) ++ans;
                if (arr[j]>a) ++ans;
            }
        }
        cout << "Case #" << ca << ": " << ans << endl;
    }

}
