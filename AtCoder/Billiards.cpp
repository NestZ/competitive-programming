#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const double PI = 3.141592;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int sx, sy, gx, gy;cin >> sx >> sy >> gx >> gy;
  if(sx > sy){
    swap(sx, gx);
    swap(sy, gy);
  }
  double l = sx;
  double r = gx;
  double err = 1e-9;
  double mid = l + (r - l) / 2;
  while(fabs(l - r) >= err){
    mid = l + (r - l) / 2;
    double adj_s = fabs(mid - sx), adj_g = fabs(mid - gx);
    double hyp_s = sqrt(pow(sx - mid, 2) + pow(sy, 2));
    double hyp_g = sqrt(pow(gx - mid, 2) + pow(gy, 2));
    double an_s = acos(adj_s / hyp_s) * 180 / PI;
    double an_g = acos(adj_g / hyp_g) * 180 / PI;
    if(an_s < an_g)r = mid;
    else l = mid;
  }
  printf("%.9lf\n", mid);
}
