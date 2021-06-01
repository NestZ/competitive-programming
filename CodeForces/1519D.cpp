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
  vector<ll> a(n), b(n), pre(n);
  for(ll i = 0;i < n;i++)cin >> a[i];
  for(ll i = 0;i < n;i++){
    cin >> b[i];
    pre[i] = b[i] * a[i];
    if(i > 0)pre[i] += pre[i - 1];
  }
  ll ans = pre[n - 1];
  for(ll i = 0;i < n;i++){
    ll l = i - 1, r = i + 1;
    ll sum = a[i] * b[i];
    while(l >= 0 && r <= n - 1){
      ll cur = pre[n - 1] - (pre[r] - (l > 0 ? pre[l - 1] : 0));
      sum += b[l] * a[r] + b[r] * a[l];
      debug() << imie(i) imie(l) imie(r) imie(cur) imie(sum);
      ans = max(ans, cur + sum);
      l--; r++;
    }
  }
  for(ll i1 = 0, i2 = 1;i2 < n;i1++, i2++){
    ll l = i1, r = i2;
    ll sum = 0;
    while(l >= 0 && r <= n - 1){
      ll cur = pre[n - 1] - (pre[r] - (l > 0 ? pre[l - 1] : 0));
      sum += b[l] * a[r] + b[r] * a[l];
      ans = max(ans, cur + sum);
      l--; r++;
    }
  }
  cout << ans << endl;
}
