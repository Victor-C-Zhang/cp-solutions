//
// Created by victor on 4/28/19.
//

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



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, w;
    cin >> T >> w;
    while(T--){
        int arr[7];
        fill(arr,arr+7,0);
        int a,b;
        cout << 200 << endl;
        cin >> a;
        if (a==-1) return 0;
        cout << 50 << endl;
        cin >> b;
        if (b==-1) return 0;
        arr[6] = (a%((int)pow(2,40)))/(int)pow(2,33);
        a-=a%((int)pow(2,40));
        arr[5] = (a%((int) pow(2,50)))/(int)pow(2,40);
        a-=a%((int) pow(2,50));
        arr[4] = (a/((int)pow(2,50)));

        b-= arr[4]*((int)pow(2,12))+arr[5]*((int)pow(2,10))+arr[6]*((int)pow(2,8));
        arr[3] = (b%((int)pow(2,25)))/(int)pow(2,16);
        b-=b%((int)pow(2,25));
        arr[2] = (b%((int) pow(2,50)))/(int)pow(2,25);
        b-=b%((int) pow(2,50));
        arr[1] = (b/((int)pow(2,50)));
        for (int i=1;i<=6;i++) cout << arr[i] << " ";
        cout << endl;
        cin >> a;
        if (a==-1) return 0;
    }
}

