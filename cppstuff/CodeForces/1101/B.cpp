//
// Created by victor on 4/24/19.
//

//next time, read the problem you dumbass
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

    string s; cin >> s;
    int n = s.size();
    int a = 0;
    int pt1 = -1;
    int pt2 = n;
    int ptr = pt1;
    bool flag = 0;
    for (int i=0;i<n;i++){
        if (!flag && s[i] == '[') flag = 1;
        if (flag && s[i] == ':') {
            ptr = i; break;
        }
    }
    if (ptr == pt1) {
        cout << -1 << endl; return 0;
    }
    pt1 = ptr;
    flag = 0;
    for (int i = n-1;i>pt1 ;i--){
        if (!flag && s[i] == ']') flag = 1;
        if (flag && s[i] == ':') {
            ptr = i; break;
        }
    }
    if (ptr == pt1){
        cout << -1 << endl; return 0;
    }
    pt2 = ptr;
    a+=pt1-1;
    a+=n-pt2-2;
    for (int i=pt1+1;i<pt2;i++) if (s[i]!='|') a++;
    cout << n-a << endl;
}