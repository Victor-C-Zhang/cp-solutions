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

typedef struct _node {
    int num = -1;
    bool print = false;
    vector<*node> children;
} node;

string s;
void build(node *root, int pos) {
    if (pos = s.length()) return;
    if (s[pos] - '0' == root->num+1) {
        node *child = malloc(sizeof(node));
        child->
    }
}

signed main(){
    int t; cin >> t;
    for (int ca = 1; ca<=t; ++ca){
        node *root = malloc(sizeof(node));
        cin >> s;

    }
    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */