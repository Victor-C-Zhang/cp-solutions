//created 12/27
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long int
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
#define zp mp(0, 0)

int arr[32];

int setBitNumber(int n)
{
    // Below steps set bits after
    // MSB (including MSB)

    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n >> 1;

    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n >> 2;

    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    // Increment n by 1 so that
    // there is only one set bit
    // which is just before original
    // MSB. n now becomes 1000000000
    n = n + 1;

    // Return original MSB after shifting.
    // n now becomes 100000000
    return (n>>1);
}
int solve(int n){
    int cnt = 0;
    while (n>0){
        int a = setBitNumber(n);
        arr[(int)log2(a)]++;
        n-=a;
        cnt++;
    }
    return cnt;
}
int ghostsolve(int n){
    int cnt = 0;
    while (n>0){
        int a = setBitNumber(n);
        n-=a;
        cnt++;
    }
    return cnt;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n>>k;

    if (k>n) {
        cout << "NO" << endl;
        return 0;
    }
    if (k==n) {
        cout <<"YES"<<endl;
        for (int i=0;i<n;i++){
            cout << 1<<" ";
        }
        cout << endl;
        return 0;
    }
    for (int i=0;i<32;i++){
        arr[i] = 0;
    }
    int th = ghostsolve(n);
    if (k==th) {
        cout << "YES" << endl;
        solve(n);
        for (int i=0;i<32;i++){
            for (int j=0;j<arr[i];j++){
                cout << (1<<i) << " ";
            }
        }
        cout << endl;
        return 0;
    }
    if (k<th){
        cout << "NO"<<endl;
        return 0;
    }

//    cout << "YES" << endl;
//    while (k>0){
//        int a = solve(n-k);
//        n = k;
//        k-=a;
//        if (n-k==1){
//            cout << 2 << " ";
//            for (int i=1;i<k;i++){
//                cout << 1 << " ";
//            }
//            cout << endl;
//            return 0;
//        }
//    }
//    cout << endl;

    k-=solve(n);
    int ptr = 32;
    for (int i=31;i>-1;i--){
        if (arr[i]!=0) {
            ptr = i;
            break;
        }
    }
    while (k>0){
        if (arr[ptr]>k){
            arr[ptr-1]+=2*k;
            arr[ptr]-=k;
            k = 0;
        }
        else {
            arr[ptr-1]+=2*arr[ptr];
            k-=arr[ptr];
            arr[ptr]=0;
            ptr--;

        }
    }
    cout << "YES" << endl;
    for (int i=0;i<32;i++){
        for (int j=0;j<arr[i];j++){
            cout << (1<<i) << " ";
        }
    }
    cout << endl;
    return 0;
}