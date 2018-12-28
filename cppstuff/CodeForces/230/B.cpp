//
// Created by victor on 12/25/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int unsigned long long int
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
#define zp mp(0, 0)

const int N = 1000007;
bool prime[N];
vi vs;
unordered_set<int> vsq;

void sieve()
{
    for(int i = 2; i < N; i++) prime[i] = 1;

    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            vs.pb(i);
            for(int j = i * i; j < N; j += i) prime[j] = 0;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    for (int i: vs) vsq.insert(i*i);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        if (vsq.find(a)!=vsq.end()) cout << "YES" << endl;
        else cout<< "NO" << endl;
    }
}