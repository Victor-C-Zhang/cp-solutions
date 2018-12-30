//
// Created by victor on 12/29/18.
//

//this is wrong
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
#define zp mp(0, 0)


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int cost[n];
    for (int i=0;i<n;i++){
        cin >> cost[i];
    }
    vvi hard(4);
    int lasth = INT_MIN, lasta = INT_MIN, lastr = INT_MIN, lastd = INT_MIN;
    int gar = -1;
    for (int i=0;i<n;i++){
        if (s[i]=='h') {
            gar= i;
            break;
        }
    }
    if (gar==-1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i=gar;i<n;i++){
        if (s[i] == 'h') {
            hard[0].pb(i);
            lasth = i;
        }
        if (s[i] == 'a') {
            hard[1].pb(i);
            lasta = i;
        }
        if (s[i] == 'r') {
            hard[2].pb(i);
            lastr = i;
        }
        if (s[i] == 'd') {
            hard[3].pb(i);
            lastd = i;
        }
    }
    if (lasth==INT_MIN || lasta==INT_MIN || lastr==INT_MIN || lastd==INT_MIN) {
        cout << 0 << endl;
        return 0;
    }
    for (int i=2;i>-1;i--){
        for (int j = hard[i].size()-1; j>-1;j--){
            if (hard[i][j]>hard[i+1][hard[i+1].size()-1]){
                hard[i].erase(hard[i].end()-1, hard[i].end());
            }
            else break;
        }
        if (hard[i].size()==0) {
            cout << 0 << endl;
            return 0;
        }
    }
    int pt[] = {hard[0][0], hard[1][0], hard[2][0], hard[3][0]};
    int ans = 0;
    while (pt[0]<hard[0].size() && pt[1]<hard[1].size() && pt[2]<hard[2].size() && pt[3]<hard[3].size()){
        for (int as = 0; as <4;as++){
            if (cost[pt[as]]<= cost[pt[0]] && cost[pt[as]]<= cost[pt[1]] && cost[pt[as]]<= cost[pt[2]] && cost[pt[as]]<= cost[pt[3]]){
                ans+=cost[hard[as][pt[as]]];
                pt[as]++;
                for (int i=0;i<as;i++){
                    if (i!=as){
                        while (pt[i]<hard[i].size() && hard[as][pt[as]]<hard[i][pt[i]]){
                            pt[i]++;
                        }
                        hard[i].erase(hard[i].begin(), hard[i].begin()+pt[i]);
                    }
                }
                for (int i=as+1;i<4;i++){
                    if (i!=as){
                        while (pt[i]<hard[i].size() && hard[as][pt[as]]>hard[i][pt[i]]){
                            pt[i]++;
                        }
                        hard[i].erase(hard[i].begin(), hard[i].begin()+pt[i]);
                    }
                }
                break;
            }
        }

    }
    cout << ans << endl;
}
