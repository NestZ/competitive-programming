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

  ll x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
  ll x3, y3, x4, y4;cin >> x3 >> y3 >> x4 >> y4;
  ll x5, y5, x6, y6;cin >> x5 >> y5 >> x6 >> y6;
  ll w = x2 - x1;
  ll h = y2 - y1;
  ll wb1 = max(0ll, min(y2, y4) - max(y1, y3)) * max(0ll, min(x2, x4) - max(x1, x3));
  ll wb2 = max(0ll, min(y2, y6) - max(y1, y5)) * max(0ll, min(x2, x6) - max(x1, x5));
  ll bb = max(0ll, min(y4, y6) - max(y3, y5)) * max(0ll, min(x4, x6) - max(x3, x5));
  if(bb == 0){
    if(w * h - wb1 - wb2 == 0)cout << "NO";
    else cout << "YES";
  }
  else{
    ll nx1 = max(x3, x5);
    ll ny1 = max(y3, y5);
    ll nx2 = min(x4, x6);
    ll ny2 = min(y4, y6);
    ll bbw = max(0ll, min(nx2, x2) - max(nx1, x1)) * max(0ll, min(ny2, y2) - max(ny1, y1));
    if(w * h - wb1 - wb2 + bbw == 0)cout << "NO";
    else cout << "YES";
  }
  cout << endl;
}
