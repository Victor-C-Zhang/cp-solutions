//
// Created by victor on 11/12/18.
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
//#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout.precision(17);
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        int n;
        cin >> n;
        if (n==1 || n==2 || n==3) cout << "N" << endl;
        else {
            cout << "Y ";
            double a = ((n-2)-sqrt((n-2)*(n-2)-4))/2.0;
            cout << n-1-a <<" " << 1+a << endl;
        }
    }
//    cout.precision(17);
//
//    for (int i=0;i<1000;i++){
//        cout << i << " ";
//        if (i==1) cout << "true" << endl;
//        else {
//            double a = ((i-2)-sqrt((i-2)*(i-2)-4))/2.0;
//            if (abs(i-1-a+1+a-i)<0.000001 && abs((i-1-a)*(1+a)-i)<0.000001) {
//                cout << "true" << endl;
//            }
//            else cout << "false" << endl;
//        }
//    }
}

