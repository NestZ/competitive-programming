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

ll clz(ll n) {
  ll pos = 0;
  while (n > 0) {
    pos++;
    n >>= 1;
  }
  return 64 - pos;
}

ll cal(ll n, ll want) {
  ll left = ((~n) & want);
  return want - (((1 << (64 - clz(want))) - 1) & n);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;cin >> n >> q;
  ll BITS = 63;
  vector<ll> arr(n);
  vector<vector<pair<ll, ll>>> cost(n, vector<pair<ll, ll>>(BITS, {INT64_MAX, INT64_MAX}));
  for (ll i = 0;i < n;i++) {
    cin >> arr[i];
  }

  while(q--) {
    ll k;cin >> k;
    ll ans = 0;
    vector<bool> filled(n);
    for (ll i = BITS - 1;i >= 0;i--) {
      ll sum = 0;
      bool valid = true;
      for (ll j = 0;j < n;j++) {
        if (filled[j]) {
          sum += (1ll << i);
        } else {
          if (((1ll << i) & arr[j]) == 0) {
            sum += cal(arr[j], 1ll << i);
          }
        }
        if (sum > k) {
          valid = false;
        }
      }

      if (valid) {
        k -= sum;
        for (ll j = 0;j < n;j++) {
          if ((arr[j] & (1ll << i)) == 0) {
            filled[j] = true;
          }
        }
        ans |= (1ll << i);
      }
    }
    cout << ans << endl;
  }
}
