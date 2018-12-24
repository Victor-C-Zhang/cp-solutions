//
// Created by victor on 11/6/18.
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



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[207];
    for (int i = 0;i<207;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for (int i = 2; i<=100; i++){
        int carry = 0;
        for (int j = 0;j<207;j++){
            if (arr[j]!=0) {
                carry = arr[j]*i + carry;
                arr[j] = carry%10;
                carry = carry/10;
            }
            else if (arr[j]==0){
                arr[j] = carry%10;
                carry /=10;
                //end of line carrying
            }
        }
    }
    int ans = 0;
    for (int i=0;i<207;i++){
        ans+=arr[i];
    }
    cout << ans << endl;
}

