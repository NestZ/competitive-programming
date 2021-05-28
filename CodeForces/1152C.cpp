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

  ll a, b;cin >> a >> b;
  if(b < a)swap(a, b);
  if(a == b){
    cout << 0 << endl;
    return 0;
  }
  ll diff = b - a;
  vector<ll> fac;
  for(ll i = 1;i * i <= diff;i++){
    if(diff % i == 0){
      ll fst = i;
      ll snd = diff / i;
      fac.push_back(fst);
      if(snd != fst)fac.push_back(snd);
    }
  }
  debug() << imie(fac);
  pair<ll, ll> ans = make_pair(LLONG_MAX, LLONG_MAX);
  for(ll q : fac){
    ll k = (q - a % q) % q;
    auto nw = make_pair((a + k) * (b + k) / __gcd(a + k, b + k), k);
    ans = min(ans, nw);
  }
  cout << ans.second << endl;
}
