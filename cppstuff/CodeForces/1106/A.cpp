//
// Created by victor on 2/7/19.
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

int disc(char c){
    switch (c) {
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        default: return (c-'0');
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<string> arr;
    string s;
    for (int i=0;i<n;i++) {
        cin >> s;
        arr.pb(s);
    }
    int ans = 0;
    for (int i=1;i<n-1;i++){
        for (int j=1;j<n-1;j++){
            if (arr[i][j]=='X'){
                if (arr[i-1][j-1]=='X' && arr[i+1][j-1]=='X' && arr[i-1][j+1]=='X' && arr[i+1][j+1]=='X' ) ans++;
            }
        }
    }
    cout << ans << endl;
}
