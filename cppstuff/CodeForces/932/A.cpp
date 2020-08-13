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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    int f = 0, b = s.size()-1;
    string output = "";
    while (f <= b) {
        if (s[f] == s[b]) output+=s[f];
        else {
            output+=s[f];
            output+=s[b];
        }
        ++f; --b;
    }
    cout << output;
    reverse(output.begin(),output.end());
    cout << output << endl;

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */