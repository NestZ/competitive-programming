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
    vector<int> arr;
    for (ll i = 0;i < n;i++) {
      ll a;cin >> a;
      arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    ll mx = n - 1;
    ll mn = 0;
    ll cur_sum = 0;
    ll ans = 0;

    while (mn < mx) {
      cur_sum += arr[mn];
      if (cur_sum > arr[mx]) {
        ans += arr[mx] + 1ll;
        arr[mn] = cur_sum - arr[mx];
        cur_sum = 0;
        mx--;
      } else {
        mn++;
      }
    }

    ll left = cur_sum + arr[mn];
    if (left <= 1ll) {
      ans += left;
    } else {
      ans += (left + 1ll) / 2ll + 1ll;
    }

    cout << ans << endl;
  }
}
