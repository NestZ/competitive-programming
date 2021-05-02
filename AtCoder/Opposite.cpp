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

const double PI = acos(-1);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  double x0, y0, x2, y2;cin >> x0 >> y0 >> x2 >> y2;

  double radius = sqrt((x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2)) / 2;
  double cx = (x0 + x2) / 2.0;
  double cy = (y0 + y2) / 2.0;
  double azimuth = atan2(y0 - cy, x0 - cx);
  double a1 = azimuth + 2 * PI / n;
  double ans_x = cx + radius * cos(a1);
  double ans_y = cy + radius * sin(a1);
  printf("%.9lf %.9lf\n", ans_x, ans_y);
}
