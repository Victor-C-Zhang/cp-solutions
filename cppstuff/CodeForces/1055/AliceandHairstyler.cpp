//
// Created by victor on 11/10/18.
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



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,l;
    cin >> n >> m >> l;
    int hairs[n+1], start[n+2], end[n+2];
    int cnt = 0;
    for (int i=0;i<n+2;i++){
        start[i] = 0;
        end[i] = 0;
    }
    for (int i = 1;i<=n;i++){
        int temp;
        cin >> temp;
        hairs[i] = temp;
        if (temp>l) {
            if (end[i-1] == 1 && start[i+1] == 1) {
                cnt--;
                end[i-1] = 0;
                start[i+1] = 0;
            }
            else if (end[i-1] == 1) {
                end[i] = 1;
                end[i-1] = 0;
            }
            else if (start[i+1] == 1) {
                start[i+1] = 0;
                start[i] = 1;
            }
            else {
                cnt++;
                end[i] = 1;
                start[i] = 1;
            }
        }
    }
    for (int j=0;j<m;j++){
        int type;
        cin >> type;
        if (type == 0) cout << cnt <<endl;
        else if (type == 1) {
            int i,len;
            cin >> i >> len;
            hairs[i] +=len;
            if (hairs[i] > l && hairs[i] - len <=l){
                if (end[i-1] == 1 && start[i+1] == 1) {
                    cnt--;
                    end[i-1] = 0;
                    start[i+1] = 0;
                }
                else if (end[i-1] == 1) {
                    end[i] = 1;
                    end[i-1] = 0;
                }
                else if (start[i+1] == 1) {
                    start[i+1] = 0;
                    start[i] = 1;
                }
                else {
                    cnt++;
                    end[i] = 1;
                    start[i] = 1;
                }
            }
        }
    }
}

