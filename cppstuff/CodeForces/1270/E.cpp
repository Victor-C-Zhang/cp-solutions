//
// Created by victor on 1/17/20.
//

//WAs for some reason

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

    set<ppi> parity[2][2];
    int n; cin >> n;
    int a,b;
    for (int i=1;i<=n;++i){
        cin >> a >> b;
        parity[abs(a%2)][abs(b%2)].insert({{a,b},i});

    }
    bool only = true;
    while (only) {
        bool aux = false;
        pi quadrant;
        for (int i=0;i<2;++i)
            for (int j = 0;j<2;++j) {
                if (!aux && !parity[i][j].empty()) {
                    aux = true;
                    quadrant = {i,j};
                }
                else if (!parity[i][j].empty()) only = false;
            }

        if (only) {
            set<ppi> temp;
            for (auto po : parity[quadrant.f][quadrant.s]) {
                ppi newpo;
                if (po.f.f%2) newpo.f.f = po.f.f/2 + 1;
                else newpo.f.f = po.f.f/2;
                if (po.f.s%2) newpo.f.s = po.f.s/2 + 1;
                else newpo.f.s = po.f.s/2;
                newpo.s = po.s;
                if (quadrant.f== abs(newpo.f.f%2) && quadrant.s == abs(newpo.f.s%2)) temp.insert(newpo);
                else parity[abs(newpo.f.f%2)][abs(newpo.f.s%2)].insert(newpo);
            }
            parity[quadrant.f][quadrant.s].swap(temp);
        }
    }
    if ((!parity[0][0].empty() || !parity[1][1].empty()) && (!parity[0][1].empty() || !parity[1][0].empty())) {
        cout << parity[0][0].size() + parity[1][1].size() << endl;
        for (auto po : parity[0][0]) cout << po.s << " ";
        for (auto po : parity[1][1]) cout << po.s << " ";
        cout << endl;
    }
    else {
        if (!parity[0][0].empty()) {
            cout << parity[0][0].size() << endl;
            for (auto po : parity[0][0]) cout << po.s << " ";
        }
        else {
            cout << parity[0][1].size() << endl;
            for (auto po : parity[0][1]) cout << po.s << " ";
        }
    }

    return 0;
}