//
// Created by victor on 1/4/19.
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

const int N = 100;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[N];
    arr[1] = 1;
    for (int i=2;i<N;i++){
        arr[i] = (15%i + arr[i-1])%i;
        if (arr[i]==0) arr[i] = i;
    }
    int a,b;
    do {
        cin >> a >>b;

    } while (a!=0 && b!=0);
}