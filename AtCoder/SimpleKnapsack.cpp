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

  ll n, w;cin >> n >> w;
  ll ans = 0;
  vector<ll> a, b, c, d;
  ll u, v;cin >> u >> v;
  ll fst = u;
  a.push_back(v);
  for(ll i = 0;i < n - 1;i++){
    cin >> u >> v;
    if(u - fst == 0)a.push_back(v);
    else if(u - fst == 1)b.push_back(v);
    else if(u - fst == 2)c.push_back(v);
    else d.push_back(v);
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  sort(d.rbegin(), d.rend());
  for(ll i = 1;i < (ll)a.size();i++)
    a[i] += a[i - 1];
  for(ll i = 1;i < (ll)b.size();i++)
    b[i] += b[i - 1];
  for(ll i = 1;i < (ll)c.size();i++)
    c[i] += c[i - 1];
  for(ll i = 1;i < (ll)d.size();i++)
    d[i] += d[i - 1];
  for(ll i = 0;i <= n;i++){
    ll wa = 0;
    if(a.size() && i > 0)wa = a[min(i - 1, (ll)a.size() - 1)];
    for(ll j = 0;j <= n;j++){
      ll wb = 0;
      if(b.size() && j > 0)wb = b[min(j - 1, (ll)b.size() - 1)];
      for(ll k = 0;k <= n;k++){
        ll wc = 0;
        if(c.size() && k > 0)wc = c[min(k - 1, (ll)c.size() - 1)];
        for(ll l = 0;l <= n;l++){
          ll wd = 0;
          if(d.size() && l > 0)wd = d[min(l - 1, (ll)d.size() - 1)];
          if(i * fst + j * (fst + 1) +
              k * (fst + 2) + l * (fst + 3) <= w){
            ans = max(ans, wa + wb + wc + wd);
          }
        }
      }
    }
  }
  cout << ans << endl;
}
