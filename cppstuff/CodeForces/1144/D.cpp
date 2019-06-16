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
    int arr[n], sortarr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        sortarr[i] = arr[i];
    }
    sort(sortarr,sortarr+n);
    int maxnum = 1, num = 1, maxel = sortarr[0];
    for (int i=1;i<n;i++){
        if (sortarr[i]==sortarr[i-1]) num++;
        else {
            if (num>maxnum) {
                maxnum = num;
                maxel = sortarr[i-1];
            }
            num = 1;
        }
    }
    if (num>maxnum) {
        maxel = sortarr[n-1];
        maxnum = num;
    }
    int ptr = 0;
    while (arr[ptr]!=maxel) ptr++;
    cout << n - maxnum << endl;
    for (int i=ptr;i>0;i--) cout << ((arr[i-1]>arr[ptr]) ? 2 : 1 ) << " " << i << " " << i+1 << endl;
    for (int i = ptr+1;i<n;i++) if (arr[i]!=arr[ptr]) cout << ((arr[i] - arr[ptr]>0) ? 2 : 1) << " " << i+1 << " " << i << endl;
}
