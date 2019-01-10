//
// Created by victor on 1/9/19.
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
    int arr[n];
    map<int,int> stret;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        stret[arr[i]] = i;
    }
    int num = -1;
    int ed = stret[arr[0]];
    for (int i=0;i<n;i++){
        ed = max(ed,stret[arr[i]]);
        if (ed==i) num++;
    }
    long long ans = 1;
    while (num>0){
        ans*=2;
        ans%=mod;
        num--;
    }
    cout << ans << endl;
}