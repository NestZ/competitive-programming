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
    ll ans = 0;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<pair<ll, ll>> ab;
    vector<pair<ll, ll>> ba;
    for (ll i = 0;i < n;i++) {
      cin >> a[i];
    }
    for (ll i = 0;i < n;i++) {
      cin >> b[i];
    }
    for (ll i = 0;i < n;i++) {
      ab.push_back({a[i], b[i]});
      ba.push_back({b[i], a[i]});
      ans += abs(a[i] - b[i]);
    }

    ll mn = INT64_MAX;
    ll mni = -1;
    for (ll i = 0;i < n;i++) {
      ll mx = max(ba[i].first, ba[i].second);
      if (mx < mn) {
        mn = mx;
        mni = i;
      }
    }

    ll maxsf = ans;
    for (ll i = 0;i < n;i++) {
      if (ab[i].first > mn && ab[i].second > mn) {
        ll tmp = ans + abs(ab[i].first - ba[mni].first) + abs(ab[i].second - ba[mni].second) - abs(ab[i].first - ab[i].second) - abs(ba[mni].first - ba[mni].second);
        maxsf = max(maxsf, tmp);
      }
    }
    cout << maxsf << endl;
  }
}
