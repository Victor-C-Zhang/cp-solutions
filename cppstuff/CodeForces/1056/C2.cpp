//
// Created by victor on 11/26/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long int
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

set<int> pairset;
bool touch[2001];
void dopairs(){
    for (int i: pairset){
        cout << i << endl;
        cout.flush();
        int ans;
        cin >> ans;
        if (ans==-1) exit(0);
    }
}
template <typename K, typename V>
bool comparePairs(const pair<K,V>& lhs, const pair<K,V>& rhs) {
    return lhs.s > rhs.s;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0;i<2001;i++){
        touch[i] = false;
    }
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> power;
    for (int i=1;i<=2*n;i++){
        int c;
        cin >> c;
        power.pb({i,c});
    }
    int pairs[2*n+1];
    for (int i=0;i<=2*n;i++){
        pairs[i] = -1;
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >>b;
        pairs[a] = b;
        touch[a] = true;
        pairs[b] = a;
        touch[b] = true;
        if (power.at(a-1).s>power.at(b-1).s) pairset.insert(a);
        else pairset.insert(b);
    }
    sort(power.begin(),power.end(),[] (const auto& lhs, const auto& rhs) {
        return lhs.s > rhs.s;
    });
    int t;
    cin >> t;
    int w = n;
    bool dopairscalled = false;
    if (t==1){
        dopairs();
        dopairscalled = true;
        w = n-m;
        if (w<=0) return 0;
        for (int i=0;i<2*n;i++){
            if (pairs[power.at(i).f]==-1){
                touch[power.at(i).f]= true;
                cout << power.at(i).f << endl;
                cout.flush();
                w--;
                break;
            }
        }
    }
    for (int i=0;i<w;i++){
        int c;
        cin >> c;
        if (c==-1) return 0;
        touch[c] = true;
        if (pairs[c]!=-1) {
            touch[pairs[c]] = true;
            pairset.erase(c);
            pairset.erase(pairs[c]);
            cout << pairs[c] << endl;
            cout.flush();
        }
        else if (!dopairscalled){
            dopairs();
            dopairscalled=true;
            i+=m;
            for (int j=0;j<2*n;j++){
                if (pairs[power.at(j).f]==-1 && !touch[power.at(j).f]){
                    touch[power.at(j).f]= true;
                    cout << power.at(j).f << endl;
                    cout.flush();
                    break;
                }
            }
        }
        else {
            for (int j=0;j<2*n;j++){
                if (pairs[power.at(j).f]==-1 && !touch[power.at(j).f]){
                    touch[power.at(j).f]= true;
                    cout << power.at(j).f << endl;
                    cout.flush();
                    break;
                }
            }
        }
    }
}