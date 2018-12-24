//
// Created by victor on 11/12/18.
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

    int n;
    cin >> n;
    string orig[3007], change[3007];
    string a, b;
    for (int i=0;i<n;i++){
        cin >> orig[i];
        //cin.ignore();
    }
    for (int i=0;i<n;i++){
        cin >> change[i];
        //cin.ignore();
    }
    int stop;
    for (int i=0;i<n;i++){
        if (orig[i].compare(change[i]) != 0) {
            stop = i;
            int start, end;
            for (int j=0;j<orig[i].size();j++){
                if (orig[i][j] != change[i][j]) {
                    start = j;
                    break;
                }
            }
            for (int j=orig[i].size()-1;j>=start;j--){
                if (orig[i][j] != change[i][j]) {
                    end = j;
                    break;
                }
            }
            a = orig[i].substr(start,end-start+1);
            b = change[i].substr(start,end-start+1);
            break;
        }
    }
    for (int i = stop+1;i<n;i++){
        int ind = orig[i].find(a);
        if (ind!=-1){
            string permute;
            if (ind ==0) permute = b + orig[i].substr(b.size());
            else try {
                    permute = orig[i].substr(0,ind) + b + orig[i].substr(ind+b.size());
                }
                catch (int e){
                    permute = orig[i].substr(0,ind) + b;
                }
            if (permute != change[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
        else if (orig[i] != change[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl << a << endl << b << endl;
}

