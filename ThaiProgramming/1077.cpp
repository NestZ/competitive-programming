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

  vector<vector<ll>> arr(1010, vector<ll>(1010, 0));
  ll n, m;cin >> n >> m;
  for (ll i = 0;i < n;i++) {
    ll x, y;cin >> x >> y;
    arr[x][y]++;
  }
  for (ll i = 0;i <= 1000;i++) {
    for (ll j = 0;j <= 1000;j++) {
      ll up = (i == 0 ? 0 : arr[i - 1][j]);
      ll left = (j == 0 ? 0 : arr[i][j - 1]);
      ll up_left = (i == 0 || j == 0 ? 0 : arr[i - 1][j - 1]);
      arr[i][j] += up + left - up_left;
    }
  }
  for (ll i = 0;i < m;i++) {
    ll x, y, k;cin >> x >> y >> k;
    cout << arr[min(x + k, 1000ll)][min(y + k, 1000ll)]
          - (y - k - 1 >= 0 ? arr[min(x + k, 1000ll)][y - k - 1] : 0)
          - (x - k - 1 >= 0 ? arr[x - k - 1][min(y + k, 1000ll)] : 0)
          + (x - k - 1 >= 0 && y - k - 1 >= 0 ? arr[x - k - 1][y - k - 1] : 0) << endl;
  }
}
