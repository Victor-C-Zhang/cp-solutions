#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
#define int long long int
#define mod 1000000000
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

ppi solve(string str) { // FIRST is W/E, SECOND is N/S ; ; ; pass the NEXT value
    pi retval = {0,0};
    int i=0;
    while (i < str.size()) {
        switch (str[i]) {
            case ')' : {
                // cout << i+1 << endl;
                return {retval,i+1};
            }
            case 'N': {
                retval.s = (retval.s+mod - 1)%mod;
                ++i;
                break;
            }
            case 'S': {
                retval.s = (retval.s+mod + 1)%mod;
                ++i;
                break;
            }
            case 'W': {
                retval.f = (retval.f+mod - 1)%mod;
                ++i;
                break;
            }
            case 'E': {
                retval.f = (retval.f+mod + 1)%mod;
                ++i;
                break;
            }
            default : {
                int times = str[i] - '0';
                string pass = str.substr(i+2,str.npos);
                ppi passed = solve(pass);
                passed.f.f = (passed.f.f*times)%mod;
                passed.f.s = (passed.f.s*times)%mod;
                retval.f = (retval.f + passed.f.f)%mod;
                retval.s = (retval.s+passed.f.s)%mod;
                i += passed.s + 2;
                break;
            }
        }
    }
    // cout << i << endl;
    return {retval,i};
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int ca = 1;ca <=t;++ca) {
        string str; cin >> str;
        ppi pp = solve(str);
        cout << "Case #" << ca << ": " << pp.f.f + 1 << " " << pp.f.s + 1 << endl;
    }

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */