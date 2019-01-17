//
// Created by victor on 1/16/19.
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

bool board[1000][1000];
pi king;

void movecenter(int x, int y){
    int a = 500-x;
    int b = 500-y;
    if (a==0) king.s += b/abs(b);
    else if (b==0) king.f+=a/abs(a);
    else {
        if (board[king.f+a/abs(a)][king.s+b/abs(b)]) king.f-=a/abs(a);
        king.s += b/abs(b);
        king.f+=a/abs(a);
    }
    cout << king.f << " " << king.s << endl;
}
void move(int x, int y, int num){
    int tarx = (num%2)*998+1;
    int tary = (num/2)*998+1;
    int a = tarx-x;
    int b = tary-y;
    if (a==0) king.s += b/abs(b);
    else if (b==0) king.f+=a/abs(a);
    else {
        if (board[king.f+a/abs(a)][king.s+b/abs(b)]) king.f-=a/abs(a);
        king.s += b/abs(b);
        king.f+=a/abs(a);
    }
    cout << king.f << " " << king.s << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x,y;
    cin >> x >>y;
    king = {x,y};
    int n = 666;
    vector<pi> rooks;
    rooks.pb({0,0});
    while (n--){
        cin >> x >>y;
        rooks.pb({x,y});
        board[x][y] = true;
    }
    int a=-2,b=-2,c=-2;
    while (king.f!=500 || king.s!=500){
        movecenter(king.f,king.s);
        cin >> a >> b >> c;
        if ((a==0 && b==0 && c==0) || (a==-1 && b==-1 && c==-1)) return 0;
        board[rooks[a].f][rooks[a].s] = false;
        board[b][c] = true;
        rooks[a] = {b,c};
    }
    int corners[4];
    fill(corners,corners+4,0); //DON'T FORGET TO FILL WITH ZEROES!!!
    // 2 3
    // 0 1
    for (int i=1;i<667;i++){
        x = rooks[i].f-500;
        y = rooks[i].s-500;
        x/=abs(x);
        y/=abs(y);
        x++;
        y++;
        corners[x+y*2]++;
    }
    int target = -1;
    int minim = INT_MAX;
    for (int i=0;i<4;i++){
        if (corners[i]<minim) {
            minim = corners[i];
            target = 3-i;
        }
    }
    while (!(king.f == (target%2)*998+1 && king.s == (target/2)*998+1)){
        move(king.f,king.s,target);
        cin >> a >> b >> c;
        if ((a==0 && b==0 && c==0) || (a==-1 && b==-1 && c==-1)) return 0;
        board[rooks[a].f][rooks[a].s] = false;
        board[b][c] = true;
        rooks[a] = {b,c};
    }


    while (king.f!=500 || king.s!=500){
        movecenter(king.f,king.s);
        cin >> a >> b >> c;
        if ((a==0 && b==0 && c==0) || (a==-1 && b==-1 && c==-1)) return 0;
        board[rooks[a].f][rooks[a].s] = false;
        board[b][c] = true;
        rooks[a] = {b,c};
    }
    fill(corners,corners+4,0);
    // 2 3
    // 0 1
    for (int i=1;i<667;i++){
        x = rooks[i].f-500;
        y = rooks[i].s-500;
        x/=abs(x);
        y/=abs(y);
        x++;
        y++;
        corners[x+y*2]++;
    }
    target = -1;
    minim = INT_MAX;
    for (int i=0;i<4;i++){
        if (corners[i]<minim) {
            minim = corners[i];
            target = 3-i;
        }
    }
    while (!(king.f == (target%2)*998+1 && king.s == (target/2)*998+1)){
        move(king.f,king.s,target);
        cin >> a >> b >> c;
        if ((a==0 && b==0 && c==0) || (a==-1 && b==-1 && c==-1)) return 0;
        board[rooks[a].f][rooks[a].s] = false;
        board[b][c] = true;
        rooks[a] = {b,c};
    }
    return 0;
}