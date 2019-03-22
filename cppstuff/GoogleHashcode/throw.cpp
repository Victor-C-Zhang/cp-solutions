//
// Created by victor on 2/28/19.
//

#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
#define int long long int
#define double long double
#define mod 998244353
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int> , int >
#define pppi pair<ppi,int>

const int arr[12] = {1,4,5,5,8,10,10,10,10,11,15,19,};
int bs(int x){
    int l=0,r=11,mid;
    while (l<=r){
        mid = (l+r)/2;
        if (x==arr[mid]) return mid;
        if (x>arr[mid]) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

int lbs(int x){
    int l = 0, r = 11, mid;
    while (l<r){
        mid = (l+r)/2;
        if (x>arr[mid]) l = mid+1;
        else r = mid;
    }
    if (arr[l] == x) return l;
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=-5;i<=22;i++){
        cout << i << ": " << bs(i) << " " << lbs(i) << endl;
    }


}
