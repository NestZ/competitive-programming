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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d, h;cin >> n >> d >> h;
  vector<pair<int, int>> arr;
  for(int i = 0;i < n;i++){
    int cd, ch;cin >> cd >> ch;
    arr.push_back({cd, ch});
  }
  double l = 0, r = 1000;
  double ans = 2000;
  while(fabs(l - r) >= 1e-9){
    double mid = l + (r - l) / 2.0;
    double cur_slope = (double(h) - mid) / (double)d;
    bool valid = true;
    for(int i = 0;i < n;i++){
      double slope = ((double)arr[i].second - (double)mid) / (double)arr[i].first;
      if(slope > cur_slope)valid = false;
    }
    if(valid){
      ans = min(ans, mid);
      r = mid;
    }
    else l = mid;
  }
  printf("%.9lf\n", ans);
}
