//
// Created by victor on 1/13/19.
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

    int n,k;
    cin >> n >> k;
    int arr[n];
    int e=0,s=0;
    for (int i = 0; i <n ; ++i) {
        cin >> arr[i];
        if (arr[i]==1) e++;
        else s++;
    }
    int ans[k];
    int sum;
    for (int i=0;i<k;i++){
        int e1 = e, s1 = s;
        for (int j=i;j<n;j+=k){
            if (arr[j]==1) e1--;
            else s1--;
        }
        ans[i] = abs(e1-s1);
    }
    int outer = INT_MIN;
    for (int i:ans){
        if (i>outer) outer = i;
    }
    cout << outer << endl;
}