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

  ll n, t;cin >> n >> t;
  vector<ll> a(n), b{0}, c{0};
  for(int i = 0;i < n;i++)cin >> a[i];
  for(ll i : a){
    for(ll j = b.size();j--;)
      b.push_back(b[j] + i);
    swap(b, c);
  }
  sort(b.begin(), b.end(), greater());
  ll ans = 0;
  for(ll i : c){
    if(i > t)continue;
    i += *lower_bound(b.begin(), b.end(), t - i, greater());
    ans = max(ans, i);
  }
  cout << ans << endl;
}
