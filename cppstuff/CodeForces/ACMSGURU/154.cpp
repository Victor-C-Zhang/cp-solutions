//
// Created by victor on 1/6/19.
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

    int n;
    cin >> n;
    if (n==0) {
        cout << 1 << endl;
        return 0;
    }
    int arr[15];
    arr[0] = 1;
    for (int i=1;i<15;i++){
        arr[i] = arr[i-1] + pow(5,i);
    }
    int ans = 0;
    for (int i=14;i>-1;i--){
        if (n>=arr[i]) {
            int a = n/arr[i];
            if (a==5) {
                cout << "No solution" << endl;
                return 0;
            }
            ans+=a*pow(5,i);
            n%=arr[i];
        }
    }
    cout << ans*5 << endl;
}