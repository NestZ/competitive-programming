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

const ll MOD = 1e9 + 7;

ll f(ll n){
  if(n == 0)return 0;
  ll pow = 1;
  ll odd = 1;
  ll even = 0;
  bool is_odd = false;
  while((odd + (is_odd ? (1ll << pow) : 0)) +
      (even + (is_odd ? 0 : (1ll << pow))) < n){
    if(is_odd)odd += (1ll << pow);
    else even += (1ll << pow);
    is_odd = !is_odd;
    pow++;
  }
  ll w = n - (odd + even);
  if(is_odd)odd += w;
  else even += w;
  return ((odd % MOD) * (odd % MOD) + even % MOD + (even % MOD) * (even % MOD)) % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll l, r;cin >> l >> r;
  cout << (f(r) - f(l - 1) + MOD) % MOD << endl;
}
