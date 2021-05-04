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

  ll n, m;cin >> n >> m;
  vector<ll> h(n), w(m), l(n + 1), r(n + 1);
  for(ll i = 0;i < n;i++)cin >> h[i];
  for(ll i = 0;i < m;i++)cin >> w[i];
  sort(h.begin(), h.end());
  for(ll i = 1;i < n;i += 2){
    l[i] = h[i] - h[i - 1];
    if(i > 1)l[i] += l[i - 2];
  }
  for(ll i = n - 2;i >= 0;i -= 2){
    r[i] = h[i + 1] - h[i];
    if(i < n - 2)r[i] += r[i + 2];
  }
  ll ans = INT64_MAX;
  for(int i = 0;i < m;i++){
    ll pos = lower_bound(h.begin(), h.end(), w[i]) - h.begin();
    if(pos & 1)pos--;
    if(pos == 0){
      ans = min(ans, r[pos + 1] + abs(w[i] - h[pos]));
    }
    else if(pos == n - 1){
      ans = min(ans, l[pos - 1] + abs(w[i] - h[pos]));
    }
    else{
      ans = min(ans, l[pos - 1] + abs(w[i] - h[pos]) + r[pos + 1]);
    }
  }
  cout << ans << endl;
}
