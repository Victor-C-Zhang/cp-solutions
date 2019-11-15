//
// Created by victor on 10/6/19.
//

//
// Created by victor on 9/4/19.
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

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    string a,b;
    while (n--){
        cin >> a >> b;
        bool arr1[26];
        bool arr2[26];
        fill(arr1,arr1+26,0);
        fill(arr2,arr2+26,0);
        for (char c: a) arr1[c-'a']= 1;
        for (char c: b) arr2[c-'a']= 1;
        bool flag = false;
        for (int i=0;i<26;++i){
            if (arr1[i] && arr2[i]) {
                flag = true;
                break;
            }
        }
        if (flag) cout <<"YES" << endl;
        else cout << "NO" << endl;
    }
}
