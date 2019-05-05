//
// Created by victor on 5/4/19.
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

    int T; cin >> T;
    for (int ca = 1; ca<=T;ca++){
        int n; cin >> n;
        string s;
        bool contains[3];
        vector<string> arr;
        for (int i=0;i<n;i++){
            cin >> s; arr.pb(s);
        }
        cout << "Case #" << ca <<": ";
        sort(arr.begin(),arr.end());
        int it = 0;
        string ans;
        bool flag = 0;
        while(it < 500 && arr.size()>0){
            int remove = 0;
            for (int j=0;j<3;j++)
                contains[j] = 0;
            for (int i=0;i<arr.size();i++) {
                switch (arr[i][it % arr[i].size()]) {
                    case 'R':
                        contains[0] = 1;
                        break;
                    case 'S':
                        contains[1] = 1;
                        break;
                    case 'P':
                        contains[2] = 1;
                        break;
                }
            }
            if (contains[0] && contains[1] && contains[2]) {
                cout << "IMPOSSIBLE" << endl;
                flag = 1;
                remove = 1; //just to not trigger end loop
                break;
            }
            if (contains[0] && contains[1]) {
                ans+="R";
                remove = 2;
                for (int i=0;i<arr.size();i++){
                    if (arr[i][it%arr[i].size()]=='S') {
                        arr.erase(arr.begin()+i,arr.begin()+i+1);
                        i--;
                    }
                }
            }
            if (contains[1] && contains[2]) {
                ans+="S";
                remove = 3;
                for (int i=0;i<arr.size();i++){
                    if (arr[i][it%arr[i].size()]=='P') {
                        arr.erase(arr.begin()+i,arr.begin()+i+1);
                        i--;
                    }
                }
            }
            if (contains[2] && contains[0]) {
                ans+="P";
                remove = 1;
                for (int i=0;i<arr.size();i++){
                    if (arr[i][it%arr[i].size()]=='R') {
                        arr.erase(arr.begin()+i,arr.begin()+i+1);
                        i--;
                    }
                }
            }
            if (remove==0){
                if (contains[0]) {
                    ans+="P";
                    for (int i=0;i<arr.size();i++){
                        if (arr[i][it%arr[i].size()]=='R') {
                            arr.erase(arr.begin()+i,arr.begin()+i+1);
                            i--;
                        }
                    }
                }
                if (contains[1]) {
                    ans+="R";
                    for (int i=0;i<arr.size();i++){
                        if (arr[i][it%arr[i].size()]=='S') {
                            arr.erase(arr.begin()+i,arr.begin()+i+1);
                            i--;
                        }
                    }
                }
                if (contains[2]) {
                    ans+="S";
                    for (int i=0;i<arr.size();i++){
                        if (arr[i][it%arr[i].size()]=='P') {
                            arr.erase(arr.begin()+i,arr.begin()+i+1);
                            i--;
                        }
                    }
                }
            }
            it++;
        }
        if (!flag){
            if (arr.size()==0) cout << ans << endl;
            else cout <<"IMPOSSIBLE" <<endl;
        }
    }
}
