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

ll binom(ll n, ll k){
  if(k < 0 || k > n)return 0;
  k = min(k, n - k);
  ll up = 1, down = 1;
  for(ll i = n;i > n - k;i--){
    up = up * i % MOD;
  }
  for(ll i = 2;i <= k;i++){
    down = down * i % MOD;
  }
  return up * bin_pow(down, MOD - 2) % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;cin >> n >> m;
  ll ans = 0;
  for(ll be = 1;be <= n;be++){
    ll b_cnt = binom(n - be + m - 1, m - 1);
    ll a_cnt = 0;
    for(ll ae = 1;ae <= be;ae++){
      a_cnt = (a_cnt + binom(ae + m - 2, m - 1)) % MOD;
    }
    ans = (ans + b_cnt * a_cnt % MOD) % MOD;
  }
  cout << ans << endl;
}
