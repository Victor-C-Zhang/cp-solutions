//
// Created by victor on 3/30/19.
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
#define vpi vector < pair < set <int>, int > >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > >
#define zp mp(0, 0)

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N; cin >> N;
    int digits = N.length();
    int num[digits];
    int n=0;
    for (int i=digits-1;i>-1;i--){
        char c = N[i];
        n+=(int)pow(10,digits-1-i)*(c-'0');
    }
    int ans=1;
    for (int i=0;i<digits;i++){
        num[i] = n%10;
        ans*=num[i];
        n/=10;
    }
    int comp[digits+1];
    fill(comp,comp+digits+1,0);
    comp[digits] = ans;
    if (digits==1) {
        cout << num[0] << endl;
        return 0;
    }
    int give = (int) pow(9,digits-1);
    if (num[digits]!=1) give*=num[digits-1]-1;
    comp[digits-1] = give;
    for (int i=0;i<digits-1;i++){
        int a = 0;
        for (int j=0;j<digits;j++) a+=num[j]*(int)pow(10,j);
        if (num[i]!=9) {
            a-= (int)pow(10,i)*(10+num[i]-9);
        }
        digits = (int) (log(a)/log(10))+1;
        for (int j=0;j<digits;j++){
            num[j] = a%10;
            a/=10;
        }
        int aa = 1;
        for (int j=0;j<digits;j++) aa*=num[j];
        comp[i] = aa;
    }
    for (int i: comp) give = max(give,i);
    cout << give << endl;
}