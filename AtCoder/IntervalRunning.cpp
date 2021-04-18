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

  ll t1, t2;cin >> t1 >> t2;
  pair<ll, ll> a, b;
  cin >> a.first >> a.second;
  cin >> b.first >> b.second;
  a.first = t1 * a.first;
  b.first = t1 * b.first;
  a.second = t2 * a.second + a.first;
  b.second = t2 * b.second + b.first;
  assert(a.first != b.first);
  if(a.first > b.first)
    swap(a, b);
  ll up = b.first - a.first, down = a.second - b.second;
  debug() << imie(up) imie(down);
  if(down == 0)cout << "infinity";
  else{
    if(down < 0)cout << 0;
    else{
      ll ans = (up + down - 1) / down * 2 - 1;
      if(up % down == 0)ans++;
      cout << ans << endl;
    }
  }
  cout << endl;
}
