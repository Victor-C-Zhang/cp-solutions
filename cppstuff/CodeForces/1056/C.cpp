//
// Created by victor on 11/25/18.
//

//WA on pretest 7
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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    pair<int,int> power[2*n+1];
    int index[2*n+1];
    int pair[2*n+1];
    bool chosen[2*n+1];
    for (int i=0;i<=2*n;i++){
        chosen[i] = false;
    }
    for (int i=1;i<=2*n;i++){
        int k;
        cin >> k;
        power[i] = {k,i};
        index[i] = k;
    }
    for (int i=0;i<=2*n;i++){
        pair[i] = 0;
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        pair[a] = b;
        pair[b] = a;
    }
    sort(power,power+2*n+1, greater<>());
    int t;
    cin >> t;
    int w = n;
    int pnt = -1;
    if (t==1) {
        pnt = 0;
        for (int i=0;i<m;i++){
            while (true){
                if (!chosen[pnt+1] && pair[pnt+1]!=0) break;
                pnt++;
            }
            {
                int a = index[pnt+1];
                int b = index[pair[pnt+1]];
                chosen[pnt+1] = true;
                chosen[pair[pnt+1]]= true;
                if (a>b){
                    cout << pnt+2 << endl;
                    cout.flush();
                }
                else {
                    cout << pair[pnt+1] << endl;
                    cout.flush();
                }
                int garb;
                cin >> garb;
                if (garb==-1) return 0;
            }
        }
        w = n-m-1;
        if (w>=0){
            for (int i=0;i<=2*n;i++){
                if (!chosen[power[i].s]) {
                    pnt = i-1;
                    break;
                }
            }
            chosen[power[pnt+1].s] = true;
            cout << power[pnt+1].s << endl;
            cout.flush();
        }
    }
    for (int i=0;i<w;i++){
        int pick;
        cin >> pick;
        if (pick==-1) return 0;
        chosen[pick] = true;
        if (pair[pick]!=0 && !chosen[pair[pick]]) {
            chosen[pair[pick]] = true;
            cout << pair[pick] << endl;
            cout.flush();
        }
        else{
            for (int j=pnt+1;j<2*n+1;j++){
                if (!chosen[power[j].s]) {
                    pnt = j;
                    break;
                }
            }
            chosen[power[pnt].s] = true;
            cout << power[pnt].s << endl;
            cout.flush();
        }

    }

}