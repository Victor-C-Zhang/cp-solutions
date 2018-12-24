//
// Created by victor on 11/25/18.
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

int compare(const void* ap, const void* bp)
{
    // Typecasting
    const int* a = (int*)ap;
    const int* b = (int*)bp;

    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int n;
    cin >> n;
    int trams[n];

    bool cont[n];
    for (int i=0;i<n;i++){
        cont[i] = true;
    }

    for (int i=0;i<n;i++){
        cin >> trams[i];
    }
    sort(trams,trams+n);
    for (int i=1;i<N;i++){
        for (int j=0;j<n;j++){
            cont[i]=false;
        }
        int k;
        cin >> k;
        for (int j=0;j<k;j++){
            int tr;
            cin >> tr;
            if (bsearch(&tr,trams*,n,8)!= nullptr){
                cont[bsearch(&tr,trams*,sizeof(trams),sizeof(trams[0]),compare)]= true;
            }
            else trams[bsearch(tr,trams*,n,8)] = 0;
        }
        sort(trams,trams+n);
    }
    for (int i=0;i<n;i++){
        if (trams[i]!=0) cout << trams[i] << " ";
    }
    cout << endl;
}