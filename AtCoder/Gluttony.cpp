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

  ll n, k;cin >> n >> k;
  ll ans = INT64_MAX;
  vector<ll> a(n);
  vector<ll> f(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  for(int i = 0;i < n;i++)cin >> f[i];
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());
  ll l = 0, r = 1e12;
  while(l <= r){
    ll mid = l + (r - l) / 2;
    ll curk = k;
    bool valid = true;
    for(int i = 0;i < n;i++){
      if(a[i] * f[i] <= mid)continue;
      ll w = mid / f[i];
      curk -= a[i] - w;
      if(curk < 0){
        valid = false;
        break;
      }
    }
    if(valid){
      r = mid - 1;
      ans = min(ans, mid);
    }
    else l = mid + 1;
  }
  cout << ans << endl;
}
