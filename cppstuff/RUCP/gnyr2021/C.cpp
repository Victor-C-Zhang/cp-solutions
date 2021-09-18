#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
#define mod 1000000007
#define vi vector <int>
#define vvi vector < vector <int> >
//#define pi pair <int, int>
//#define ppi pair < pair <int, int>, int>
#define vpi vector < pair < set <int>, int > >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > >
#define zp mp(0, 0)

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

typedef long double ld;
typedef complex<ld> pt;

struct circ { pt C; ld R; };

#define X real()
#define Y imag()
#define CRS(a, b) (conj(a) * (b)).Y //scalar cross product
#define DOT(a, b) (conj(a) * (b)).X //dot product
#define U(p) ((p) / abs(p)) //unit vector in direction of p (don't use if Z(p) == true)
#define Z(x) (abs(x) < EPS)
#define ZB(x) (abs(x) < EPSB)
#define A(a) (a).begin(), (a).end() //shortens sort(), upper_bound(), etc. for vectors

constexpr ld PI = 3.14159265358979323846264, INF = 1e30, EPS = 1e-12;
constexpr ld EPSB = 1e-6;
constexpr pt I = {0, 1}, INV = {INF, INF};

struct line {
  pt P, D;
  bool S;

  // Two points
  line (pt a, pt b, bool s=0) : P(a), D(b-a), S(s) {}

  // Point and angle
  line (pt a, ld theta) : P(a), D(polar(1.l, theta)), S(0) {}
};

//makes line l a full line (sets segment bool to false)
line ml(line l) { l.S=false; return l; }

//true if d1 and d2 parallel (zero vectors considered parallel to everything)
bool parallel(pt d1, pt d2) { return Z(d1) || Z(d2) || Z(CRS(U(d1), U(d2))); }

//"above" here means if l & p are rotated such that l.D points in the +x direction, then p is above l
bool above_line(pt p, line l) { return CRS(p - l.P, l.D) > 0; }

//true if p is on line l
bool on_line(pt p, line l) { return parallel(l.P - p, l.D) && (!l.S || DOT(l.P - p, l.P + l.D - p) <= 0); }

////intersection pt of l1 and l2, returns INV if they are nonintersecting / parallel / identical
//pt intsct(line l1, line l2) {
//  if(parallel(l1.D, l2.D)) return INV;
//  pt p = l1.P + l1.D * CRS(l2.D, l2.P - l1.P) / CRS(l2.D, l1.D);
//  return on_line(p, l1) && on_line(p, l2) ? p : INV;
//}

//closest pt on l to p
pt cl_pt_on_l(pt p, line l) {
  pt q = l.P + DOT(U(l.D), p - l.P) * U(l.D);
  if(on_line(q, l)) return q;
  return abs(p - l.P) < abs(p - l.P - l.D) ? l.P : l.P + l.D;
}


//p reflected over l
pt refl_pt(pt p, line l) { return (ld)2 * cl_pt_on_l(p, ml(l)) - p; }

//area of polygon, vertices in order (cw or ccw)
ld area(vector<pt>& poly) {
  ld ans = 0;
  pt lst = poly.back();
  for(pt p : poly) ans += CRS(lst, p), lst = p;
  return abs(ans / 2);
}

//vector of intersection pts of a line and a circ (up to 2)
vector<pt> intsct(circ c, line l) {
  pt p = cl_pt_on_l(c.C, l);
  ld h2 = c.R*c.R - norm(p);
  if (h2<0) return {};

  pt h = U(l.D)*sqrtl(h2);
  if (Z(h)) return {p};
  return {p-h, p+h};
}

//vector of intersection pts of two circs (up to 2) (if circles same, returns empty vector)
vector<pt> intsct_circ(circ c1, circ c2) {
  pt d = c2.C - c1.C;
  ld d2 = norm(d);
  if (Z(d2)) return {}; // concentric

  ld pd = (d2 + c1.R*c1.R - c2.R*c2.R)/2;
  ld h2 = c1.R*c1.R - pd*pd/d2;
  if (h2<0) return {};

  pt p = c1.C+d*pd/d2, h=d*I*sqrtl(h2/d2);
  if (Z(h)) return {p};
  return {p-h, p+h};
}

vector<circ> ans = {};
// returns 0 if too short, 1 if too long
bool place(ld D, ld O, int N, ld R) {
  ans.clear();
  circ first_circ = {(D/2.0 - (R-O))/2.0 + (R-O),(D/2.0 - (R-O))/2.0};
  ans.push_back(first_circ);
  bool should_center = (N%2 == 0);
  if (should_center) N = N/2-1;
  else N = N/2;
  ld prev_rad = (D/2.0 - (R-O))/2.0;
  pt prev_center = {(D/2.0 - (R-O))/2.0 + (R-O),0};
  ld max_rad = prev_rad;
  pt O_C = {-O,0};
  for (int i = 0; i < N; ++i) {
    ld l = 0, r = max_rad;
    ld mid;
    while (true) {
      mid = (l+r)/2.0;
      auto pot_centers = intsct_circ({O_C,R+mid},{prev_center,prev_rad+mid});
      // circles don't intersect, radius too big
      if (pot_centers.size() == 0) {
        r = mid; continue;
      }
      pt act_center;
      // find center
      ld arg0 = arg(pot_centers[0]-O_C), arg1 = arg(pot_centers[1]-O_C);
      ld argprev = arg(prev_center-O_C);
      if (argprev < PI/2.0) {
        if (arg0 > arg1) act_center = pot_centers[0];
        else act_center = pot_centers[1];
      } else {
        if (arg0 > 0 && arg1 > 0) act_center = (arg0 > arg1) ? pot_centers[0]
                                                             : pot_centers[1];
        else act_center = (arg0 < 0) ? pot_centers[0] : pot_centers[1];
      }
      auto ints = intsct_circ({0,D/2.0},{act_center,mid});
      // radius too small
      if (ints.empty()) l = mid;
        // radius just right
      else if (ints.size() == 1 || ZB(ints[0]-ints[1])) {
        prev_center = act_center;
        prev_rad = mid;
        ans.push_back({act_center,mid});
        break;
      }
        // radius too large
      else r = mid;
    }
    // check if we should continue putting circles
//    cout << arg(prev_center) << endl;
    if (arg(prev_center) < 0 && !(Z(arg(prev_center))))
      return true;
  }
  // final check
  if (should_center && arg(prev_center) < 0 && !(Z(arg(prev_center))))
    return true;
  if (should_center && arg(prev_center) < PI && !(Z(arg(prev_center)-PI)))
    return false;
  if (!should_center) {
    if (prev_center.Y-prev_rad > 0 && !(Z(prev_center.Y-prev_rad))) return false;
    if (prev_center.Y-prev_rad < 0 && !(Z(prev_center.Y-prev_rad))) return true;
  }
  // output answer
  printf("%.3Lf\n",R);
  for (int i=0;i<4;++i) {
    printf("%.3Lf %.3Lf %.3Lf\n", ans[i].C.X, ans[i].C.Y, ans[i].R);
  }
  exit(0);
}

signed bmain() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ld D,O; int N; cin >> D >> N >> O;

  ld l = 0.0, r = (D/2.0)-O;
  ld mid;
  while (!(Z(r-l))) {
    mid = (l+r)/2.0;
    if (place(D,O,N,mid) == true)  l = mid;
    else r = mid;
  }
  return 0;
}

signed main() {
  printf("%-4d%-4d%3d%5d\n", 1234,2,31,155);
}

/* List of CP snippets:
 *
 * cp-header (standard header)
 */
