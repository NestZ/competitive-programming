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

  ll n, b;cin >> n >> b;
  ll ans = LLONG_MAX;
  vector<pair<ll, ll>> fac;
  for(ll i = 2;i * i <= b;i++){
    if(b % i == 0){
      ll cnt = 0;
      while(b % i == 0){
        b /= i;
        cnt++;
      }
      fac.push_back({i, cnt});
    }
  }
  if(b > 1)fac.push_back({b, 1});
  for(auto p : fac){
    ll tmp = 0, mul = 1;
    while(mul <= n / p.first){
      mul *= p.first;
      tmp += n / mul;
    }
    ans = min(ans, tmp / p.second);
  }
  cout << ans << endl;
}
