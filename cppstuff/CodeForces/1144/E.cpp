//
// Created by victor on 6/16/19.
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

    int k; cin >> k;
    string s,t; cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(),t.end());
    int add[k+1];
    int carry = 0;
    for (int i = 0;i<k;i++){
        int a = (int) (s[i]-'a') + (int) (t[i] - 'a');
        add[i] = (carry + a) % 26;
        carry = (carry + a)/26;
    }
    add[k] = carry;
    reverse(add,add+k+1);
    int divide[k];
    carry = add[0];
    for (int i=0;i<k;i++){
        carry=carry*26;
        divide[i] = (add[i+1]+carry)/2;
        carry = (add[i+1]+carry)%2;
    }
    for (int i: divide) cout << char(i+'a'); cout << endl;
}
