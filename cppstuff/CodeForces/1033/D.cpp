//
// Created by victor on 1/16/19.
//

//WA >:(((((
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define double long double
#define mod 998244353
//#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int> , int >
#define pppi pair<ppi,int>

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n;
    vi numbers;
    while (n--) {
        cin >> m;
        numbers.pb(m);
    }
    vector<int> pq;
    map<int,int> p;
    for (int i: numbers){
        int a = (int)sqrt(i);
        int b = (int)cbrt(i);
        if (a*a==i){
            if ((int)sqrt(a)*(int)sqrt(a)==a) p[sqrt(a)]+=4;
            else p[a]+=2;
        }
        else if (b*b*b==i) p[b]+=3;
        else pq.pb(i);
    }
    for (int i=0;i+1<pq.size();i++){
        for (int j=i+1;j<pq.size();j++){
            if (pq[i]==-1) continue;
            if (pq[j]==-1) continue;
            m = gcd(pq[i],pq[j]);
            if (m!=1 && m!=pq[i]){
                p[m]+=2;
                p[pq[i]/m]++;
                p[pq[j]/m]++;
                pq[i] = -1;
                pq[j] = -1;
            }
        }
    }
    vi pq1;
    for (auto i: pq){
        if (i!=-1) pq1.pb(i);
    }
    pq = pq1;
    bool flag = true;
    while (flag) {
        flag = false;
        for (auto const &x: p) {
            for (int i=0;i<pq.size();i++){
                if (pq[i]==-1) continue;
                if (pq[i]%x.f == 0) {
                    p[x.f]++;
                    p[pq[i]/x.f]++;
                    flag = true;
                    pq[i] = -1;
                }
            }
        }
        vi pq2;
        for (auto i: pq){
            if (i!=-1) pq2.pb(i);
        }
        pq = pq2;
    }
    int ans = 1;
    if (!pq.empty()) {
        sort(pq.begin(), pq.end());
        int num = 0;
        int same = pq[0];
        for (int i = 0; i < pq.size(); i++) {
            if (pq[i] == same) num++;
            else {
                ans *= (num + 1) * (num + 1);
                ans %= mod;
                num = 1;
                same = pq[i];
            }
        }
        ans *= (num + 1) * (num + 1);
        ans %= mod;
    }
    for (auto const& x : p){
        ans*=(x.s+1);
        ans%=mod;
    }
    cout << ans << endl;
}