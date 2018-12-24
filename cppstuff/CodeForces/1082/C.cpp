//
// Created by victor on 11/28/18.
//

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

typedef long long ll;
typedef long double ld;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    int arr[m+1];
    for (int i=0;i<=m;i++){
        arr[i] = 0;
    }
    vvi input = vvi(m+1);
    for (int i=0;i<n;i++){
        int a,b;
        cin >>a >>b;
        if (b==0) continue;
        arr[a]++;
        input.at(a).pb(b);
    }
    int biggest = 0;
    for (int i=0;i<=m;i++){
        if (arr[i]>biggest) biggest = arr[i];
    }

    int skill[m][biggest];
    for (int i=0;i<m;i++){
        for (int j=0;j<biggest;j++){
            skill[i][j] = 0;
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=0;j<input.at(i).size();j++){
            skill[i-1][j] = input.at(i).at(j);
        }
    }
    for (int i=0;i<m;i++){
        sort(skill[i],skill[i]+biggest, greater<>());
    }
    for (int i=0;i<m;i++){
        for (int j=1;j<biggest;j++){
            if (skill[i][j]!=0) skill[i][j] += skill[i][j-1];
        }
    }
    int ans = 0;
    for (int j=0;j<biggest;j++){
        int temp = 0;
        for (int i=0;i<m;i++){
            if (skill[i][j]>0){ // :(((
                temp+=skill[i][j];
            }
        }
        if (temp>ans) ans= temp;
    }
    cout << ans << endl;
}