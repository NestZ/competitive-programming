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
vector<ll> fac(400010), fac_inv(400010);

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
  if(k > n)return 0;
  if(k == 0)return 1;
  return fac[n] * fac_inv[k] % MOD * fac_inv[n - k] % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;cin >> n >> k;
  fac[0] = fac_inv[0] = 1;
  for(int i = 1;i <= 2 * n;i++){
    fac[i] = fac[i - 1] * i % MOD;
    fac_inv[i] = bin_pow(fac[i], MOD - 2);
  }
  ll mx_empty = min(n, k);
  ll ans = 0;
  for(ll i = 0;i <= mx_empty;i++){
    ans = (ans + binom(n - 1, i) * binom(n, i) % MOD) % MOD;
  }
  cout << ans << endl;
}
