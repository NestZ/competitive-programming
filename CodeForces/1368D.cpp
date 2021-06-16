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
  vector<ll> arr(n), cnt(25);
  for(ll i = 0;i < n;i++)cin >> arr[i];
  for(ll i = 0;i < n;i++){
    for(ll j = 0;j <= 20;j++){
      if((1ll << j) & arr[i]){
        cnt[j]++;
      }
    }
  }
  bool flag = true;
  ll ans = 0;
  while(flag){
    flag = false;
    ll cur = 0;
    for(ll i = 0;i < 25;i++){
      if(cnt[i]){
        cur += (1ll << i);
        cnt[i]--;
        flag = true;
      }
    }
    ans += cur * cur;
  }
  cout << ans << endl;
}
