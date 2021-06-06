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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll n;cin >> n;
    ll sum = 0;
    vector<ll> arr(n), arr_or(n), arr_and(n), bit_cnt(70);
    for(ll i = 0;i < n;i++){
      cin >> arr[i];
      sum = (sum + arr[i]) % MOD;
      ll tmp = arr[i];
      for(ll j = 0;j < 60;j++){
        if(tmp & 1)bit_cnt[j]++;
        tmp /= 2;
      }
    }
    for(ll i = 0;i < n;i++){
      arr_or[i] = sum;
      for(ll j = 0;j < 60;j++){
        if((1ll << j) & arr[i]){
          arr_or[i] += (n - bit_cnt[j]) * ((1ll << j) % MOD) % MOD;
          arr_or[i] %= MOD;
        }
      }
    }
    for(ll i = 0;i < n;i++){
      arr_and[i] = 0;
      for(ll j = 0;j < 60;j++){
        if((1ll << j) & arr[i]){
          arr_and[i] += ((1ll << j) % MOD * bit_cnt[j]) % MOD;
          arr_and[i] %= MOD;
        }
      }
    }
    ll ans = 0;
    for(ll i = 0;i < n;i++){
      ans += arr_or[i] * arr_and[i] % MOD;
      ans %= MOD;
    }
    cout << ans << endl;
  }
}
