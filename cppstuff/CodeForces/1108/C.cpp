//
// Created by victor on 1/23/19.
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

    int n; cin >> n;
    string c;
    cin >> c;
    int arr[3][3]; //R,G,B
    for (int i=0;i<3;i++){
        fill(arr[i],arr[i]+3,0);
    }
    for (int i=0;i<n;i++){
        if (c[i]=='R') arr[i%3][0]++;
        if (c[i]=='G') arr[i%3][1]++;
        if (c[i]=='B') arr[i%3][2]++;
    }
    int ans = -1;
    int pt = 0;
    int ptr = -1;
    vi ones = {0,1,2};
    vi answ = {-1,-1,-1};
    do {
        if (arr[0][ones[0]]+arr[1][ones[1]]+arr[2][ones[2]]>ans){
            answ = {ones[0],ones[1],ones[2]};
            ans = arr[0][ones[0]]+arr[1][ones[1]]+arr[2][ones[2]];
        }
    }
    while (next_permutation(ones.begin(),ones.end()));
    char answer[n];
    for (int i=0;i<n;i++){
        char a;
        switch (answ[i%3]){
            case 0: a = 'R';
                break;
            case 1: a = 'G';
                break;
            case 2: a = 'B';
                break;
        }
        answer[i] = a;
    }
    int cnt = 0;
    for (int i=0;i<n;i++){
        if (c[i]!=answer[i]) cnt++;
    }
    cout << cnt << endl;
    for (int i=0;i<n;i++){
        cout << answer[i];
    }
    cout << endl;
}