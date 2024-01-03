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
  vector<ll> g(100500);
  vector<ll> v[100500];
  for (ll i = 1;i <= 100000;i++) {
    g[i] += i;
    for (ll j = i;j <= 100000;j+=i) {
      //i is factor of j
      v[j].push_back(i);
      if (j > i) {
        g[j] -= g[i];
      }
    }
  }

  ll t;cin >> t;
  while(t--) {
    ll n;cin >> n;
    ll res = 0;
    ll tmp = 0;
    vector<ll> f(100500);
    vector<ll> a(100500);
    for (ll i = 1;i <= n;i++)cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    for (ll i = 1;i < n;i++) {
      for (auto j : v[a[i]]) tmp += f[j] * g[j];
      res += tmp;
      //f store frequency of number
      for (auto j : v[a[i]]) f[j]++;
    }
    cout << res << endl;
  }
}
