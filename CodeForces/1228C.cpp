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

ll bin_pow(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1)res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

void f(ll x, ll n){
  ll ans = 1;
  vector<ll> prime;
  for(ll i = 2;i * i <= x;i++){
    if(x % i == 0){
      prime.push_back(i);
      while(x % i == 0)x /= i;
    }
  }
  if(x > 1)prime.push_back(x);
  for(ll p0 : prime){
    for(ll p = p0;p <= n;p *= p0){
      ans = ans * bin_pow(p0, n / p) % MOD;
      if(p > n / p0)break;
    }
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x, n;cin >> x >> n;
  f(x, n);
}
