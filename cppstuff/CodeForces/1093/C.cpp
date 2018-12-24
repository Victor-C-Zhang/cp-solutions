//
// Created by victor on 12/18/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define f first
//#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)

typedef long long ll;
typedef long double ld;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    int b;
    cin >> b;
    arr[0] = 0;
    arr[n-1] = b;
    for (int i=1;i<n/2;i++){
        cin >> b;
        arr[i] = arr[i-1];
        arr[n-i-1] = b - arr[i];
        if (arr[n-1-i]>arr[n-i]){
            arr[i]+=arr[n-1-i]-arr[n-i];
            arr[n-1-i] = arr[n-i];
        }
    }
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}