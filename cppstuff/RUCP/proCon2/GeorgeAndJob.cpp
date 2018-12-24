//
// Created by victor on 11/4/18.
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
#define zp mp(0, 0)

int arr[5007];
int dp[5007][5007];
int m;

int recur(int n, int k){
    if (n<=0 || k==0) return 0;
    if (n==1 && k==1) return dp[n][k] = arr[1];
    if (dp[n][k]!=0) return dp[n][k];
    return dp[n][k] = max(recur(n-1,k),recur(n-m,k-1) + arr[n] );
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> m >> k;
    int orig[n];
    orig[0] = 0;
    for (int i=1;i<=n;i++){
        cin >> orig[i];
    }
    for (int i=1;i<=n-m+1;i++){
        int temp = 0;
        for (int j=0;j<m;j++){
            temp+=orig[i+j];
        }
        arr[i] = temp;
    }
//    for (int i =1;i<n-m+1;i++){
//        cout << arr[i] << " ";
//    }
    cout << recur(n-m+1,k) << endl;
}


