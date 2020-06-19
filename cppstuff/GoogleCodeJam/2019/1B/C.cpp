//
// Created by victor on 5/2/19.
//

//TODO: code to binary search for endpoints for each position

#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
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

const int N = 2e5+7;
int segcharles[N];
int segdelila[N];

int fillcharles(int *arr, int n, int l, int r){ //fillcharles(arr,0,0,n-1)
    if (l==r) return segcharles[n] = arr[l];
    return segcharles[n] = max(fillcharles(arr,2*n,l,(l+r)/2),fillcharles(arr,2*n+1,(l+r)/2+1,r));
}
int filldelila(int *arr, int n, int l, int r){
    if (l==r) return segdelila[n] = arr[l];
    return segdelila[n] = max(filldelila(arr,2*n,l,(l+r)/2),filldelila(arr,2*n+1,(l+r)/2+1,r));
}

int maxcharles(int n, int l, int r, int left, int right){ //maxcharles(0,0,n-1,left,right)
    if (l==left && r == right) return segcharles[n];
    int mid = (l+r)/2;
    if (left>mid) return maxcharles(n*2+1,mid+1,r,left,right);
    else if (right<=mid) return maxcharles(2*n,l,mid,left,right);
    else return max(maxcharles(2*n,l,mid,left,mid),maxcharles(2*n+1,mid+1,r,mid+1,right));
}
int maxdelila(int n, int l, int r, int left, int right){ //maxdelila(0,0,n-1,left,right)
    if (l==left && r == right) return segdelila[n];
    int mid = (l+r)/2;
    if (left>mid) return maxdelila(n*2+1,mid+1,r,left,right);
    else if (right<=mid) return maxdelila(2*n,l,mid,left,right);
    else return max(maxdelila(2*n,l,mid,left,mid),maxdelila(2*n+1,mid+1,r,mid+1,right));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int ca=1;ca<=T;ca++){
        int ans = 0;
        int n,k; cin >> n >>k;
        int arrcharles[n], arrdelila[n];
        for (int i=0;i<n;i++) cin >> arrcharles[i];
        for (int i=0;i<n;i++) cin >> arrdelila[i];
        fillcharles(arrcharles,0,0,n-1);
        filldelila(arrdelila,0,0,n-1);

    }
}

