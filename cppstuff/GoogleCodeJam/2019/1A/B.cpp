//
// Created by victor on 5/2/19.
//

#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
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

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

const int crt[7] = {16,3,5,7,11,13,17};
const int prod = 4084080;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,N,M,temp,a,b; cin >> T >> N >>M;
    while (T--){
        int ans = 0;
        for (int i=0;i<7;i++){
            for (int j=0;j<18;j++) cout << crt[i]<< " ";
            cout << endl;
            a=0;
            for (int j=0;j<18;j++) {
                cin >> temp;
                a+=temp;
            }
            a%=crt[i];
            b = prod/crt[i];
            while (b%crt[i]!=a){
                b+=prod/crt[i];
            }
            ans+=b;
            ans%=prod;
        }
        cout << ans << endl;
        cin >> temp;
        if (temp==-1) return 0;
    }
}

