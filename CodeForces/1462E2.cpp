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
vector<ll> fac(200010), fac_inv(200010);

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
  for(ll i = 1;i < 200010;i++){
    fac[i] = i * fac[i - 1] % MOD;
    fac_inv[i] = bin_pow(fac[i], MOD - 2);
  }

  ll t;cin >> t;
  while(t--){
    ll n, m, k;cin >> n >> m >> k;
    ll ans = 0;
    vector<ll> arr(n);
    for(ll i = 0;i < n;i++)cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(ll i = 0;i < n;i++){
      ll l = i, r = n - 1;
      ll best = i;
      ll w = arr[i] + k;
      while(l <= r){
        ll mid = l + (r - l) / 2;
        if(arr[mid] <= w){
          best = max(best, mid);
          l = mid + 1;
        }
        else r = mid - 1;
      }
      if(best - i + 1 < m)continue;
      else ans = (ans + binom(best - i, m - 1)) % MOD;
    }
    cout << ans << endl;
  }
}
