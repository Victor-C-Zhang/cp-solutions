//
// Created by victor on 12/23/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
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

//    int x[3][2];
//    for (int i=0;i<3;i++){
//        cin >> x[i][0] >> x[i][1];
//    }
//    int min = 0;
//    int mindist = x[0][0]*x[0][0]+x[0][1]*x[0][1];
//    for (int i=1;i<3;i++){
//        if (x[i][0]*x[i][0]+x[i][1]*x[i][1]<mindist){
//            mindist = x[i][0]*x[i][0]+x[i][1]*x[i][1];
//            min = i;
//        }
//    }
//    int minx = INT_MAX,miny = INT_MAX;
//    int whichx, whichy;
//    for (int i=0;i<3;i++){
//        if (i!=min && x[i][0]<minx) {
//            minx = x[i][0];
//            whichx = i;
//        }
//        if (i!=min && x[i][1]<miny) {
//            miny = x[i][1];
//            whichy = i;
//        }
//    }
//    int tx = x[min][0], ty = x[min][1];
//    vector<pi> ans;
//    while (tx<minx && ty<miny){
//        tx++;
//        ans.pb({tx,ty});
//        ty++;
//        ans.pb({tx,ty});
//    }
//    if (whichx==whichy){
//        ans.erase(ans.begin()+ans.size()-1);
//        int chosen;
//        for (int i=0;i<3;i++){
//            if (i!=min && i!=whichx) chosen = i;
//        }
//        while (tx<x[chosen][] && ty<miny){
//            tx++;
//            ans.pb({tx,ty});
//            ty++;
//            ans.pb({tx,ty});
//        }
//    }
//    if (miny>minx){
//        for (ty;ty<=miny;ty++){
//            ans.pb({tx,ty});
//        }
//    }
//    else {
//        for (tx;tx<=minx;tx++){
//            ans.pb({tx,ty});
//        }
//    }
//    for (int i=tx+1;i<x[whichx][0];i++){
//        ans.pb({i,ty});
//    }
//    for (int i=ty+1;i<x[whichy][1];i++){
//        ans.pb({tx,i});
//    }
//    cout << ans.size() << endl;
//    for (pair p : ans){
//        cout << p.f << p.s << endl;
//    }


//    vector<pi> points;
//    for (int i=0;i<3;i++){
//        int a,b;
//        cin >> a >>b;
//        points.pb({a,b});
//    }
//    int a = points[0].f*points[0].f+points[0].s*points[0].s;
//    int b = points[1].f*points[1].f+points[1].s*points[1].s;
//    int c = points[2].f*points[2].f+points[2].s*points[2].s;
//    if (b<a) {
//        pair temp = points[0];
//        points[0] = points[1];
//        points[1] = temp;
//    }
//    if (c<a) {
//        pair temp = points[0];
//        points[0] = points[2];
//        points[2] = temp;
//    }
//    sort(points.begin()+1,points.end());
//    vector<pi> ans;
//    int x = points[0].f, y = points[0].s;
//    int collin =0;
//    if (points[0].f==points[1].f && points[0].f == points[2].f) collin = 1; //vert line
//    else if (points[0].s==points[1].s && points[0].s == points[2].s) collin = 2; //horiz line
//    else if (points[2].f>=points[1].f && points[2].s >=points[1].s) collin = 3;
//    if (collin==1) {
//        y++;
//        for (;y<points[2].s;y++){
//            if (y!=points[1].s) ans.pb({x,y});
//        }
//    }
//    else if (collin==2){
//        x++;
//        for (;x<points[2].f;x++){
//            if (x!=points[1].f) ans.pb({x,y});
//        }
//    }
//    else if (collin==3){
//        x++;
//        for (;x<=points[1].f;x++){
//            ans.pb({x,y});
//        }
//        x--;
//        if (y==points[0].s) y++;
//        for (;y<points[1].s;y++){
//            ans.pb({x,y});
//        }
//        x++;
//        for (;x<=points[2].f;x++){
//            ans.pb({x,y});
//        }
//        x--;
//        if (y==points[1].s) y++;
//        for (;y<points[2].s;y++){
//            ans.pb({x,y});
//        }
//    }
//    else {
//        while (x<points[1].f && y<points[2].s){
//            x++;
//            ans.pb({x,y});
//            y++;
//            ans.pb({x,y});
//        }
//        for (int i=y+1;i<points[1].s;i++){
//            ans.pb({x,i});
//        }
//        for (int i=x+1;i<points[2].f;i++){
//            ans.pb({i,y});
//        }
//    }
//    cout << ans.size() +3 << endl;
//    for (pair pa : ans){
//        cout << pa.f << " " << pa.s << endl;
//    }
//    for (pair pa : points){
//        cout << pa.f << " " << pa.s << endl;
//    }

    vector<pi> pts;
    for (int i=0;i<3;i++){
        int a,b;
        cin >> a >>b;
        pts.pb({a,b});
    }
    sort(pts.begin(),pts.end());
    vector<pi> ans;
    int x = pts[0].f, y = pts[0].s;
    ans.pb({x,y});
    if (pts[1].s>=pts[0].s && pts[2].s>=pts[1].s) {
        for (int i=x+1;i<=pts[1].f;i++){
            ans.pb({i,y});
        }
        for (int i=y+1;i<=pts[1].s;i++){
            ans.pb({pts[1].f,i});
        }
        x = pts[1].f, y = pts[1].s;
        for (int i=x+1;i<=pts[2].f;i++){
            ans.pb({i,y});
        }
        for (int i=y+1;i<=pts[2].s;i++){
            ans.pb({pts[2].f,i});
        }
    }
    else if (pts[1].s<=pts[0].s && pts[2].s<=pts[1].s){
        for (int i=x+1;i<=pts[1].f;i++){
            ans.pb({i,y});
        }
        for (int i=y-1;i>=pts[1].s;i--){
            ans.pb({pts[1].f,i});
        }
        x = pts[1].f, y = pts[1].s;
        for (int i=x+1;i<=pts[2].f;i++){
            ans.pb({i,y});
        }
        for (int i=y-1;i>=pts[2].s;i--){
            ans.pb({pts[2].f,i});
        }
    }
    else {
        for (int i=x+1;i<=pts[1].f;i++){
            ans.pb({i,y});
        }
        x = pts[1].f;
        if (pts[1].s>=pts[0].s && pts[2].s>=pts[0].s){
            for (int i = y+1;i<=pts[2].s;i++){
                ans.pb({x,i});
            }
            y = pts[2].s;
            for (int i=y+1;i<=pts[1].s;i++){
                ans.pb({x,i});
            }
            for (int i=x+1;i<=pts[2].f;i++){
                ans.pb({i,y});
            }
        }
        else if (pts[1].s<=pts[0].s && pts[2].s<=pts[0].s){
            for (int i = y-1;i>=pts[2].s;i--){
                ans.pb({x,i});
            }
            y = pts[2].s;
            for (int i=y-1;i>=pts[1].s;i--){
                ans.pb({x,i});
            }
            for (int i=x+1;i<=pts[2].f;i++){
                ans.pb({i,y});
            }
        }
        else {
            if (pts[1].s>=pts[0].s){
                for (int i=y+1;i<=pts[1].s;i++){
                    ans.pb({x,i});
                }
            }
            else {
                for (int i=y-1;i>=pts[1].s;i--){
                    ans.pb({x,i});
                }
            }
            for (int i=x+1;i<=pts[2].f;i++){
                ans.pb({i,y});
            }
            x = pts[2].f;
            for (int i=y+1;i<=pts[2].s;i++){
                ans.pb({x,i});
            }
        }
    }
    cout << ans.size() << endl;
    for (pair pa : ans){
        cout << pa.f << " " << pa.s << endl;
    }
}