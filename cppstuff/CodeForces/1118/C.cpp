//
// Created by victor on 2/20/19.
//

//fix into 1s,2s,4s
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

    int n; cin >>n;
    vvi ans(n,vi(n));
    for (int i=0;i<n;i++) fill(ans[i].begin(),ans[i].end(),-1);
    vi nums(1001); fill(nums.begin(),nums.end(),0);
    for (int i=0;i<n*n;i++) {
        int a; cin >> a;
        nums[a]++;
    }
    int ptr = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (ans[i][j]==-1){
                while (!nums[ptr]) ptr++;

                nums[ptr]-=4;
                if (n%2 && j==n/2){
                    ans[i][j] = ptr;
                    ans[n-1-i][j] = ptr;
                    ans[j][i] = ptr;
                    ans[j][n-1-i] = ptr;
                }
                else {
                    ans[i][j] = ptr;
                    ans[i][n - 1 - j] = ptr;
                    ans[n - 1 - i][j] = ptr;
                    ans[n - 1 - i][n - 1 - j] = ptr;
                }
            }
        }
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

