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

ll bin_pow(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1)res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;cin >> n;
  vector<ll> arr(n), suf(n + 2);
  for(ll i = 0;i < n;i++)cin >> arr[i];
  sort(arr.begin(), arr.end());
  for(ll i = n;i >= 1;i--){
    ll cur = bin_pow(2ll, max(0ll, i - 2)) * arr[i - 1] % MOD;
    suf[i] = (suf[i + 1] + cur) % MOD;
  }
  ll ans = 0;
  for(ll i = 1;i <= n;i++){
    ll cur_suf = suf[i + 1];
    if(i >= 2)cur_suf = cur_suf * bin_pow(bin_pow(2ll, max(0ll, i - 1)), MOD - 2) % MOD;
    ans = (ans + (cur_suf + arr[i - 1]) % MOD * arr[i - 1] % MOD) % MOD;
  }
  cout << ans << endl;
}
