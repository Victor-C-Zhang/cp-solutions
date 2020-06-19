#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
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

    int t, b; cin >> t >> b;
    while (t--) {
        int revcheck = -1;
        int rev;
        int compcheck = -1;
        int comp;

        vi ans(b+2, -1);

        int trash = 1;
        int n = 0;
        int p,v;
        bool flag = false;
        while (trash<=150) {
            // cout << "revcheck:" << revcheck << ", " << rev << endl;
            // cout << "compcheck:" << compcheck << ", " << comp << endl;

            if (revcheck != -1 && compcheck != -1) {
                cout << compcheck << endl;
                cin >> p;
                if (p!=comp) {
                    cout << revcheck << endl;
                    cin >> v;
                    if (v==rev) { // both
                        reverse(ans.begin(),ans.end());
                    }
                    for (int i=0;i<ans.size();++i) { //complementing
                        if (ans[i]==-1) continue;
                        ans[i] = !ans[i];
                    }
                }
                else {
                    cout << revcheck << endl;
                    cin >> v;
                    if (v != rev) reverse(ans.begin(),ans.end());
                }
                rev = v;
                comp = p;
                trash +=2;
            }
            else if (revcheck != -1) {
                cout << revcheck << endl;
                cin >> v;
                cout << revcheck << endl;
                cin >> v;
                if (v != rev) reverse(ans.begin(),ans.end());
                rev = v;
                trash+=2;
            }
            else if (compcheck != -1) {
                cout << compcheck << endl;
                cin >> p;
                cout << compcheck << endl;
                cin >> p;
                if (p!= comp) {
                    for (int i=0;i<ans.size();++i) { //complementing
                        if (ans[i]==-1) continue;
                        ans[i] = !ans[i];
                    }
                }
                comp = p;
                trash+=2;
            }
            if (flag) break;

            // cout<< "checks done" << endl;
            do {
                // cout << "reached this" << endl;
                cout << n/2 + 1 << endl;
                cin >> p;
                cout << b - n/2 << endl;
                cin >> v;
                if (revcheck == -1 && p!=v) {
                    revcheck = n/2 + 1;
                    rev = p;
                }
                if (compcheck == -1 && p==v) {
                    compcheck = n/2 + 1;
                    comp = p;
                }
                ans[n/2 + 1] = p;
                ans[b - n/2] = v;
                trash += 2;
                n+=2;
                if (n==b) {
                    flag = true;
                    break;
                }
            } while (trash%10 != 1);
            if (trash%10 != 1) break;
        }
        for (int i=1;i<=b;++i) cout << ans[i];
        cout << endl;
        string s; cin >> s;
        if (s[0] == 'N') return 0;
    }

    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */