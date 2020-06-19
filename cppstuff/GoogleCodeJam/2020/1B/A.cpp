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

bool solve0() {
    string s;
    int l = -1000000000, r = 0, m;
    int xstart, xend;
    int x,y;
    while (l <= r) { 
        m = l + (r - l) / 2;
        cout << m << " 0" << endl;
        cin >> s;
        switch (s) {
            case "MISS": l = m+1; break;
            case "HIT" : r = m-1; break;
            case "CENTER" : return true;
            case "WRONG" : return false;
        }
    }
    while (true) {
        cout << r << " " << endl;
        switch (s) {
            case "MISS": ++r; break;
            case "HIT" : break;
            case "CENTER" : return true;
            case "WRONG" : return false;
        }
    }
    xstart = r;

    l = 0, r = 1000000000;
    while (l <= r) { 
        m = l + (r - l) / 2;
        cout << m << " 0" << endl;
        cin >> s;
        switch (s) {
            case "HIT": l = m+1; break;
            case "MISS" : r = m-1; break;
            case "CENTER" : return true;
            case "WRONG" : return false;
        }
    }
    while (true) {
        cout << r << " " << endl;
        switch (s) {
            case "HIT": ++r; break;
            case "MISS" : break;
            case "CENTER" : return true;
            case "WRONG" : return false;
        }
    }
    xend = r - 1;
    x = xstart + (xend - xstart)/2;

    int ystart, yend;
    // Y-Finder
    l = -1000000000, r = 0;
    while (l <= r) { 
        m = l + (r - l) / 2;
        cout << x << " " << m << endl;
        cin >> s;
        switch (s) {
            case "MISS": l = m+1; break;
            case "HIT" : r = m-1; break;
            case "CENTER" : return true;
            case "WRONG" : return false;
        }
    }
    while (true) {
        cout << x << " " << r << endl;
        switch (s) {
            case "MISS": ++r; break;
            case "HIT" : break;
            case "CENTER" : return true;
            case "WRONG" : return false;
        }
    }
    ystart = r;

    l = 0, r = 1000000000;
    while (l <= r) { 
        m = l + (r - l) / 2;
        cout << x << " " << m << endl;
        cin >> s;
        switch (s) {
            case "HIT": l = m+1; break;
            case "MISS" : r = m-1; break;
            case "CENTER" : return true;
            case "WRONG" : return false;
        }
    }
    while (true) {
        cout << x << " " << r << endl;
        switch (s) {
            case "HIT": ++r; break;
            case "MISS" : break;
            case "CENTER" : return true;
            case "WRONG" : return false;
        }
    }
    yend = r - 1;
    y = ystart + (yend - ystart)/2;


    //target searcher

    for (int i= x - 3; i < x+ 4; ++i) {
        for (int j = y - 3; j < y + 4; ++j) {
            cout << i << " " << j;
            cin >> s;
            switch (s) {
                case "HIT": break;
                case "MISS" : break;
                case "CENTER" : return true;
                case "WRONG" : return false;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,a,b; cin >> t >> a >> b;
    while (t--) {
        string s;
        bool arr[5];
        cout << "0 0" << endl;
        cin >> s;
        switch (s) {
            case "MISS": arr[4] = 0; break;
            case "HIT" : arr[4] = 1; break;
            case "CENTER" : continue;
        }
        cout << "-500000000 0" << endl;
        cin >> s;
        switch (s) {
            case "MISS": arr[0] = 0; break;
            case "HIT" : arr[0] = 1; break;
            case "CENTER" : continue;
        }
        cout << "500000000 0" << endl;
        cin >> s;
        switch (s) {
            case "MISS": arr[1] = 0; break;
            case "HIT" : arr[1] = 1; break;
            case "CENTER" : continue;
        }
        cout << "0 -500000000" << endl;
        cin >> s;
        switch (s) {
            case "MISS": arr[2] = 0; break;
            case "HIT" : arr[2] = 1; break;
            case "CENTER" : continue;
        }
        cout << "0 500000000" << endl;
        cin >> s;
        switch (s) {
            case "MISS": arr[3] = 0; break;
            case "HIT" : arr[3] = 1; break;
            case "CENTER" : continue;
        }
        if (arr[4] && !arr[0] && !arr[1] && !arr[2] && !arr[3]) { //center case
            
        }
        else if (arr[0] && arr[1]) { // top
        }
        else if (arr[2] && arr[3]) { //bottom

        }
        else if (arr[0] && arr[2]) { //left

        }
        else { //right

        }
        
    }
    return 0;
}


/* List of CP snippets:
 *
 * cp-header (standard header)
 */