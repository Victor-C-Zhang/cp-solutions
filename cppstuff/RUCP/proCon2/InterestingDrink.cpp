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
#define zp mp(0, 0)

vector<int> arr;

int binsearch(int n){
    int l,r,mid = 0;
    l = 0;
    r = arr.size()-1;
    while (l<r){
        mid = (l+r)/2;
        if (arr.at(mid) == n) return mid+1;
        if (arr.at(mid)<n){
            l = mid+1;
        }
        else r = mid;
    }
    if (arr.at(mid)<=n) {
        try {
            if (arr.at(mid+1)<=n) return mid+2;
        }
        catch (...) {
        }
        return mid+1;
    }
    else return mid;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    for (int i=0;i<n;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    cin >> m;
    for (int i=0;i<m;i++){
        int temp;
        cin >> temp;
        cout << binsearch(temp) << endl;
    }
}
