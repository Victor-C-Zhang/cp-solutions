//
// Created by victor on 12/27/18.
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
#define zp mp(0, 0)


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int left[n];
    string s;
    cin >> s;
    for (int i=0;i<n;i++){
        if (s[i]=='(') left[i] = 1;
        else left[i] = -1;
    }
    int height[n];
    int minim[n];
    height[0] = left[0];
    for (int i=1;i<n;i++){
        height[i] = height[i-1]+left[i];
    }
    int mini = INT_MAX;
    for (int i=0;i<n;i++){
        mini = min(mini,height[n-1-i]);
        minim[n-i-1] = mini;
    }
    int neg = n-1;
    for (int i=0;i<n;i++){
        if (height[i]<0) {
            neg = i;
            break;
        }
    }

//    for (int i=0;i<n;i++){
//        cout << minim[i] << " ";
//    }
    int cnt = 0;

    for (int i=0;i<=neg;i++){
        if (left[i] == 1){
            if (minim[i]-2>=0 && height[n-1]==2) cnt++;
        }
        if (left[i] == -1){
            if (minim[i]+2>=0 && height[n-1]==-2) cnt++;
        }
    }
    cout << cnt << endl;
}
