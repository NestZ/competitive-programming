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
vector<ll> fac(2000010);
vector<ll> inv_fac(2000010);

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
  if(k == 0)return 1;
  return fac[n] * inv_fac[n - k] % MOD * inv_fac[k] % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;cin >> n >> m;
  ll ans = 0;
  fac[0] = inv_fac[0] = 1;
  for(ll i = 1;i < 2000010;i++){
    fac[i] = i * fac[i - 1] % MOD;
    inv_fac[i] = bin_pow(fac[i], MOD - 2); 
  }
  for(ll i = 1;i <= m;i++){
    ll num = i, sum = 1;
    vector<ll> tmp;
    for(ll j = 2;j * j <= num;j++){
      ll cnt = 0;
      while(num % j == 0){
        num /= j;
        cnt++;
      }
      if(cnt)tmp.push_back(cnt);
    }
    if(num > 1)tmp.push_back(1);
    for(ll cnt : tmp)
      sum = sum * binom(n + cnt - 1, cnt) % MOD;
    ans = (ans + sum) % MOD;
  }
  cout << ans << endl;
}
