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

  int t;cin >> t;
  while(t--){
    ll n, m;cin >> n >> m;
    ll mn = (max(n, m) - 1) * (max(n, m) - 1) + 1;
    ll mx = max(n, m) * max(n, m);
    if(n == m)cout << (mn + mx) / 2;
    else if(n < m) {
      if(m & 1ll) {
        cout << mx - (n - 1);
      } else {
        cout << mn + (n - 1);
      }
    } else if(m < n) {
      if(n & 1ll) {
        cout << mn + (m - 1);
      } else {
        cout << mx - (m - 1);
      }
    }
    cout << endl;
  }
}
