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

  ll t;cin >> t;
  while(t--){
    ll n;cin >> n;
    vector<ll> arr(n);
    for(ll i = 0;i < n;i++)cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll z = 0, minus = 0, plus = 0;
    ll mnd = 3e9;
    for(ll i = 0;i < n;i++){
      if(arr[i] == 0)z++;
      else if(arr[i] < 0)minus++;
      else plus++;
      if(i > 0 && arr[i] <= 0){
        mnd = min(mnd, arr[i] - arr[i - 1]);
      }
    }
    bool have = false;
    for(ll i = 0;i < n;i++){
      if(arr[i] <= mnd && arr[i] > 0)have = true;
    }
    ll ans = 1;
    if(minus == 0){
      ans = max(z, min(z, 1ll) + min(plus, 1ll));
    }
    else{
      ans = max(ans, minus);
      ans = max(ans, minus + z);
      if(have)
        ans = max(ans, minus + min(1ll, z) + 1);
    }
    cout << ans << endl;
  }
}
