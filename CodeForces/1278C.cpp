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
    map<ll, ll> m;
    vector<ll> l(n), r(n);
    for(int i = 0;i < n;i++)cin >> l[i];
    for(int i = 0;i < n;i++)cin >> r[i];
    ll ans = INT64_MAX;
    ll r_two = count(r.begin(), r.end(), 2);
    ll r_one = n - r_two;
    ll l_two = count(l.begin(), l.end(), 2);
    ll l_one = n - l_two;
    ll ct = 0, co = 0;
    m[r_two - r_one] = 0;
    for(ll i = 1;i <= n;i++){
      if(r[i - 1] == 1)co++;
      else ct++;
      ll rem_o = r_one - co;
      ll rem_t = r_two - ct;
      if(!m.count(rem_t - rem_o)){
        m[rem_t - rem_o] = i;
      }
    }
    ct = 0, co = 0;
    if(m.count(l_one - l_two)){
      ans = min(ans, m[l_one - l_two]);
    }
    for(ll i = n;i >= 1;i--){
      if(l[i - 1] == 1)co++;
      else ct++;
      ll rem_o = l_one - co;
      ll rem_t = l_two - ct;
      if(m.count(rem_o - rem_t)){
        ans = min(ans, (n - i + 1) + m[rem_o - rem_t]);
      }
    }
    cout << ans << endl;
  }
}
