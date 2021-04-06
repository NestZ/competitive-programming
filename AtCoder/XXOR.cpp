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

ll mx_bit(ll n){
  ll cnt = 0;
  while(n > 0){
    cnt++;
    n >>= 1;
  }
  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;cin >> n >> k;
  ll mxb = mx_bit(k);
  ll xo = 0;
  ll ans = 0;
  vector<ll> arr(n);
  for(int i = 0;i < n;i++){
    cin >> arr[i];
    mxb = max(mxb, mx_bit(arr[i]));
  }
  if(mxb > 0){
    vector<ll> cnt(mxb);
    for(int i = 0;i < n;i++){
      for(int j = 0;j < mxb;j++){
        if((1ll << j) & arr[i])
          cnt[j]++;
      }
    }
    for(int i = mxb - 1;i >= 0;i--){
      if((n - cnt[i]) > n / 2){
        if((xo | (1ll << i)) <= k)
          xo |= (1ll << i);
      }
    }
  }
  for(int i = 0;i < n;i++){
    ans += xo ^ arr[i];
  }
  cout << ans << endl;
}
