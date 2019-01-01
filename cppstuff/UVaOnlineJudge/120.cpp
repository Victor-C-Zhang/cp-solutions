//
// Created by victor on 12/30/18.
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

    string s;
    while (getline(cin, s)){
        istringstream iss(s);
        vi arr((istream_iterator<int>(iss)), istream_iterator<int>());

        int n = arr.size();
        cout << arr[0];
        for (int i=1;i<n;i++){
            cout << " " << arr[i];
        }
        cout << endl;
        reverse(arr.begin(),arr.end());
        for (int i=0;i<n;i++){
            int maxim = INT_MIN;
            int maxind = -1;
            for (int j=i;j<n;j++){
                if (arr[j]>maxim){
                    maxind = j;
                    maxim = arr[j];
                }
            }
            if (maxind == i) continue;
            if (maxind +1 != n) {
                cout << maxind + 1 << " ";
                reverse(arr.begin() + maxind, arr.end());
            }
            cout << i+1 << " ";
            reverse(arr.begin()+i, arr.end());

        }
        cout << 0 << endl;
    }
}