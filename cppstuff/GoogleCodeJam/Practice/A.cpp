//
// Created by victor on 4/6/19.
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

    int N; cin >> N;
    for (int t = 1;t<=N;t++){
        string s; cin >> s; string u = "";
        for (int i=0;i<s.size();i++){
            if (s[i]=='4') {
                s[i] = '3';
                u+='1';
            }
            else u+='0';
        }
        while (u[0]=='0') u = u.substr(1);
        cout << "Case #" << t << ": " << s << " " << u << endl;
    }
}