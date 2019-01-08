//
// Created by victor on 1/7/19.
//

//TLE, make this more bruteforcey
//use next_permutation()

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define double long double
#define mod 998244353
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <char>
#define vvi vector < vector <char> >
#define pi pair <int, int>
#define ppi pair < pair <int, int> , int >
#define pppi pair<ppi,int>




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    bool flopped = false;
    cin >> row >> col;
    vector<vvi> arr;
    if (col<row) flopped = true;
    if (!flopped) {
        vector<vvi> arr1(25,vvi(row,vi(col)));
        arr = arr1;
    }
    else {
        vector<vvi> arr1(25,vvi(row,vi(col)));
        arr = arr1;
    }
    if (!flopped){
        for (int i=0;i<row;i++){
            string s;
            cin >> s;
            for (int j=0;j<s.size();j++){
                arr[0][i][j] = s[j];
            }
        }
    }
    else {
        for (int i=0;i<row;i++){
            string s;
            cin >> s;
            for (int j=0;j<s.size();j++){
                arr[0][j][i] = s[j];
            }
        }
    }
    string master = "AGCT";
    int a=0,g=1,t=2,c=3,i = 1;
    for (a=0;a<4;a++){
        for (g=0;g<4;g++){
            if (g==a) continue;
            for (t=0;t<4;t++){
                if (!(t!=g && t!=a)) continue;
                for (c=0;c<4;c++){
                    if (!(c!=t && c!=g && c!=a)) continue;
                    arr[i][a/2][a%2] = 'A';
                    arr[i][g/2][g%2] = 'G';
                    arr[i][c/2][c%2] = 'C';
                    arr[i][t/2][t%2] = 'T';
                    i++;
                }
            }
        }
    }
    int score[25];
    fill(score,score+25,0);
    for (int i=1;i<25;i++){
        for (int j=2;j<row;j++){
            arr[i][j][0] = arr[i][j%2][0];
            arr[i][j][1] = arr[i][j%2][1];
        }
        for (int k=2;k<row;k++){
            for (int j = 0;j<row;j++){
                arr[i][j][k] = arr[i][j][k-2];
            }
        }
        for (int j=0;j<row;j++){
            for (int k=0;k<row;k++){
                if (arr[i][j][k]==arr[0][j][k]) score[i]++;
            }
        }
        for (int k=row;k<col;k++){
            int up=0,down=0;
            for (int j=0;j<row;j+=2){
                if (arr[0][j][k]==arr[i][0][k%2]) up++;
                if (arr[0][j][k]==arr[i][1][k%2]) down++;
            }
            for (int j=1;j<row;j+=2){
                if (arr[0][j][k]==arr[i][1][k%2]) up++;
                if (arr[0][j][k]==arr[i][0][k%2]) down++;
            }
            if (up>down){
                score[i]+=up;
                for (int j=0;j<row;j++){
                    arr[i][j][k] = arr[i][j][k%2];
                }
            }
            else {
                score[i]+=down;
                arr[i][0][k] = arr[i][1][k%2];
                for (int j=1;j<row;j++){
                    arr[i][j][k] = arr[i][j-1][k%2];

                }
            }
        }
    }
    int ptr = -1;
    int maxim = INT_MIN;
    for (int i=1;i<25;i++){
        if (score[i]>maxim) {
            maxim = score[i];
            ptr = i;
        }
    }
    if (!flopped){
        for (int j=0;j<row;j++){
            for (int k=0;k<col;k++){
                cout << arr[ptr][j][k];
            }
            cout << endl;
        }
    }
    else {
        for (int j=0;j<col;j++){
            for (int k=0;k<row;k++){
                cout << arr[ptr][k][j];
            }
            cout << endl;
        }
    }
}