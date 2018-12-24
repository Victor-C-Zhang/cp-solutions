//
// Created by victor on 11/6/18.
//

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

int binsearch(int arr[], int size, int key){ //return # of elements <= key
    int l = 0,r = size-1, mid;
    while (l<r) {
        mid = (l+r)/2;
        if (key==arr[mid]) return mid+1;
        if (key>arr[mid]) l=mid+1;
        else r = mid;
    }
    if (key>=arr[l]) return l+1;
    return l;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int vert[n+1];
    for (int i = 0; i<n;i++){
        int temp;
        cin >> temp;
        vert[i] = temp;
    }
    vert[n] = 1000000000;
    sort(vert,vert+n+1);
    int horiz[n+1];
    for (int i=0;i<=n;i++){
        horiz[i] = 0;
    }
    for (int i = 0;i<m;i++){
        int start, end, y;
        cin >> start >> end >> y;
        if (start==1) {
            int len = binsearch(vert,n+1,end);
            if (len>0){
                horiz[0]++;
                horiz[len]--;
            }
        }
    }
    for (int i=1;i<=n;i++){
        horiz[i] = horiz[i] + horiz[i-1];
    }
    int min = 200007;
    for (int i = 0;i<=n;i++){
        if (i+horiz[i]<min){
            min = i+horiz[i];
        }
    }
    cout << min << endl;
}

