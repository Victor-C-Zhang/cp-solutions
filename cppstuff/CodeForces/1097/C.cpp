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

const int N = (int) 5e5+7;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[N];
    vi candi;
    for (int i=0;i<N;i++){
        arr[i] = 0;
    }
    int a,b;
    string s;
    int ans = 0;
    for (int t=0;t<n;t++){
        a=0;
        b=0;
        cin >> s;
        for (int i=0;i<s.size();i++){
            if (s[i]=='(') b++;
            else if (s[i]==')'){
                b--;
                if (b<a) a = b;
            }
        }
        if (a==0) {
            if (b == 0) ans++;
            else arr[b]++;
        }
        else if (a==b) candi.pb(a);
    }
    ans/=2;
    for (int i : candi){
        if (arr[i*-1]>0) {
            ans++;
            arr[i*-1]--;
        }
    }
    cout << ans << endl;
}