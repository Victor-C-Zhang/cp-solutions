//
// Created by victor on 11/4/18.
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

    int n,m; //num riders, taxis
    cin >> n >> m;
    if (m==1) {
        cout << n;
        return 0;
    }
    int ppl[n+m];
    vi taxis; //indices of taxis
    for (int i = 0;i<n+m;i++){
        cin >> ppl[i];
    }
    for (int i=0;i<n+m;i++){
        int a;
        cin >> a;
        if (a==1) taxis.pb(i);
    }
    int furthest = 0;
    for (int i=0;i<m-1;i++){
        int a = taxis.at(i);
        int b = taxis.at(i+1);
        int mid = (ppl[a] + ppl[b])/2;
        int num = a-furthest;
        int j;
        for (j=a+1;ppl[j]<=mid;j++){
            num++;
        }
        furthest = j;
        cout << num << " ";
    }
    cout << n+m-furthest-1 << endl;

}


