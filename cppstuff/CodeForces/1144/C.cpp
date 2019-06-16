//
// Created by victor on 6/14/19.
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

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    vi inc;
    stack<int> dec;
    int prev = arr[0]; bool flag = false;
    inc.pb(arr[0]);
    for (int i=1;i<n;i++){
        if (arr[i] == prev && flag) {
            cout << "NO" << endl; return 0;
        }
        else if (arr[i] == prev){
            flag = true;
            dec.p(arr[i]);
        }
        else {
            flag = false;
            prev = arr[i];
            inc.pb(arr[i]);
        }
    }
    cout << "YES" << endl;
    cout << inc.size() << endl;
    for (int i=0;i<inc.size(); i++) cout << inc[i] <<" ";
    cout << endl;
    cout << dec.size() << endl;
    while (!dec.empty()) {
        cout << dec.top() << " ";
        dec.pop();
    }
    cout << endl;
}
