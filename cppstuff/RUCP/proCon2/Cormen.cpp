#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long int
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tar, cnt = 0;
    cin >> n >> tar;
    int arr[n];
    for (int i=0; i<n;i++){
        cin >> arr[i];
    }
    for (int i=1;i<n;i++){
        int c = tar - arr[i] - arr[i-1];
        if (c>0){
            arr[i]+=c;
            cnt+=c;
        }
    }
    cout<< cnt << endl;
    for (int i: arr){
        cout << i << " ";
    }
    cout <<endl;
}