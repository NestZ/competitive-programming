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

const double pi = 2 * acos(0.0);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll n;cin >> n;
    vector<double> arr(n);
    map<ll, ll> m;
    for(int i = 0;i < n;i++){
      ll x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
      double angle = atan2(y2 - y1, x2 - x1) * 180 / pi;
      arr[i] = angle;
      ll conv = ll(angle * (ll)1e9);
      m[conv]++;
    }
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(ll i = 0;i < n;i++){
      double p = arr[i] + 180;
      double mi = arr[i] - 180;
      if(p > 360)p -= 360;
      if(mi < 360)mi += 360;
      ll conp = (ll)(p * (ll)1e9);
      ll conmi = (ll)(mi * (ll)1e9);
      ans += m[conp];
      ans += m[conmi];
    }
    cout << ans / 2 << endl;
  }
}
