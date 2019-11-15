//
// Created by victor on 8/5/19.
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

    int n,k;
    cin >> n >> k;
    int arr[n], pre[n];
    for (int i=0;i<n;++i) cin >> arr[i];
    int ptr = 0, curr = arr[n/2];
    sort(arr,arr+n);
    pre[n/2] = 0;
    for (int i=n/2+1;i<n;++i){
        pre[i] = pre[i-1]+(i-n/2)*(arr[i]-arr[i-1]);
    }
    if (pre[n-1]<k) {
        cout << arr[n-1] + (k-pre[n-1])/(n/2+1) << endl;
        return 0;
    }
    int l=n/2,r=n-1,mid = (l+r)/2;
    while (l<r){
        mid = l + (r-l)/2;
        if (pre[mid]==k) break;
        if (pre[mid]>k) r = mid;
        else l = mid + 1;
    }
    while (pre[mid]>-1 && pre[mid]>k) mid--;
    cout << arr[mid] + (k-pre[mid])/(mid+1-n/2) << endl;
}
