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

const ll MOD = 998244353;
vector<ll> fac(600010), fac_inv(600010);

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
  if(k > n || k < 0)return 0;
  return fac[n] * fac_inv[n - k] % MOD * fac_inv[k] % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fac[0] = fac_inv[0] = 1;
  for(ll i = 1;i < 600010;i++){
    fac[i] = i * fac[i - 1] % MOD;
    fac_inv[i] = bin_pow(fac[i], MOD - 2);
  }

  ll n, k;cin >> n >> k;
  map<ll, ll> ind;
  vector<pair<ll, ll>> arr;
  vector<ll> inc(600010), dec(600010);
  for(ll i = 0;i < n;i++){
    ll l, r;cin >> l >> r;
    arr.push_back({l, r});
    ind[l] = 0;
    ind[r + 1] = 0;
  }
  ll tmp = 1;
  for(auto &p : ind){
    p.second = tmp++;
  }
  for(auto p : arr){
    inc[ind[p.first]]++;
    dec[ind[p.second + 1]]++;
  }
  ll cur = 0, ans = 0;
  for(ll i = 1;i < 600010;i++){
    cur += inc[i] - dec[i];
    if(cur >= k){
      if(inc[i] == 0)continue;
      ans += binom(cur, k) - binom(cur - inc[i], k) + MOD;
    }
    ans %= MOD;
  }
  cout << ans << endl;
}
