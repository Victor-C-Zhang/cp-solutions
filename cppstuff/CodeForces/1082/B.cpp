//
// Created by victor on 11/28/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >>n;
    vi nums, sep1;

    bool gold =false;
    bool sep = false;
    int len=0;
    for (int i=0;i<n;i++){
        char a;
        cin >> a;
        if (a=='G'){
            if (gold){
                len++;
            }
            else {
                nums.pb(len);
                gold = true;
                len = 1;
            }
        }
        else {
            if (gold){
                nums.pb(len);
                gold = false;
                len = 1;
            }
            else {
                len++;
            }
        }
    }
    if (len!=0) nums.pb(len);
    if (nums.size()<4){
        try {
            cout << nums.at(1) <<endl;
        }
        catch (exception e){
            cout << 0 << endl;
        }
        return 0;
    }
    if (nums.size()<=5){
        if (nums.at(2)==1){
            cout << nums.at(1)+ nums.at(3) << endl;
        }
        else {
            cout << max(nums.at(1),nums.at(3)) << endl;
        }
        return 0;
    }
    vi ans;
    for (int i=2;i<nums.size()-1;i+=2){
        if (nums.at(i)==1) ans.pb(nums.at(i-1)+nums.at(i+1)+1);
    }
    sort(ans.begin(),ans.end());
    cout << ans.at(ans.size()-1) << endl;
}