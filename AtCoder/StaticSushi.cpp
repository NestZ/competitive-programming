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

  ll n, c;cin >> n >> c;
  ll ans = 0;
  vector<ll> cw(n), ccw(n), best_cw(n), best_ccw(n);
  vector<pair<ll, ll>> sushi;
  for(int i = 0;i < n;i++){
    ll x, v;cin >> x >> v;
    sushi.push_back({x, v});
  }
  sort(sushi.begin(), sushi.end());
  ll use = 0, rec = 0;
  for(int i = 0;i < n;i++){
    ll lst = 0;
    if(i > 0)lst = sushi[i - 1].first;
    use += sushi[i].first - lst;
    rec += sushi[i].second;
    cw[i] = rec - use;
    best_cw[i] = cw[i];
    if(i > 0)
      best_cw[i] = max(best_cw[i - 1], best_cw[i]);
    ans = max(ans, cw[i]);
  }
  use = 0, rec = 0;
  for(int i = n - 1;i >= 0;i--){
    ll lst = c;
    if(i < n - 1)lst = sushi[i + 1].first;
    use += lst - sushi[i].first;
    rec += sushi[i].second;
    ccw[i] = rec - use;
    best_ccw[i] = ccw[i];
    if(i < n - 1)
      best_ccw[i] = max(best_ccw[i], best_ccw[i + 1]);
    ans = max(ans, ccw[i]);
  }
  for(int i = 0;i < n - 1;i++){
    ll cur = cw[i];
    ll rev = best_ccw[i + 1];
    ans = max(ans, cur + rev - sushi[i].first);
  }
  for(int i = n - 1;i >= 1;i--){
    ll cur = ccw[i];
    ll rev = best_cw[i - 1];
    ans = max(ans, cur + rev - (c - sushi[i].first));
  }
  cout << ans << endl;
}
