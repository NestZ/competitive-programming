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
  while(t--) {
    ll n;cin >> n;
    vector<ll> arr(n);
    ll mx = INT64_MIN;
    set<ll> distinct;
    for (ll i = 0;i < n;i++) {
      cin >> arr[i];
      distinct.insert(arr[i]);
      mx = max(mx, arr[i]);
    }

    if (n == 1) {
      cout << 1 << endl;
      continue;
    }

    ll g = 0;
    vector<ll> diff;
    for (ll i = 0;i < n;i++) {
      diff.push_back(mx - arr[i]);
      if (i == 0) {
        g = diff[i];
      } else {
        g = gcd(g, diff[i]);
      }
    }

    ll chosen_down = -1;
    ll down_cost = 0;
    for (ll i = mx - g;;i -= g) {
      down_cost++;
      if (distinct.find(i) == distinct.end()) {
        chosen_down = i;
        break;
      }
    }

    ll chosen_up = -1;
    ll up_cost = 0;
    for (ll i = mx + g;;i += g) {
      up_cost += n;
      if (distinct.find(i) == distinct.end()) {
        chosen_up = i;
        break;
      }
    }

    ll chosen;
    if (down_cost < up_cost) chosen = chosen_down;
    else chosen = chosen_up;

    mx = max(chosen, mx);

    ll ans = 0;
    for (ll i = 0;i < n;i++) {
      ans += (mx - arr[i]) / g;
    }

    ans += (mx - chosen) / g;

    cout << ans << endl;
  }
}
