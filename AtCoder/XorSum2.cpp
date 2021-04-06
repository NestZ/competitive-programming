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

  ll n;cin >> n;
  ll ans = 0;
  vector<ll> arr(n);
  vector<ll> pre_sum(n + 1);
  vector<ll> pre_xor(n + 1);
  for(ll i = 0;i < n;i++){
    cin >> arr[i];
    pre_sum[i + 1] = arr[i] + pre_sum[i];
    pre_xor[i + 1] ^= arr[i] ^ pre_xor[i];
  }
  for(ll i = 0;i < n;i++){
    ll l = i;
    ll r = n - 1;
    ll res = 0;
    while(l <= r){
      ll mid = l + (r - l) / 2;
      ll sum = pre_sum[mid + 1] - pre_sum[i];
      ll xo = pre_xor[mid + 1] ^ pre_xor[i];
      if(sum == xo){
        res = max(res, mid);
        l = mid + 1;
      }
      else r = mid - 1;
    }
    ans += res - i + 1;
  }
  cout << ans << endl;
}
