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

  ll a, b, c, d;cin >> a >> b >> c >> d;
  //all possible a + b
  vector<ll> pre(1000010);
  for(ll x = a;x <= b;x++){
    pre[x + b]++;
    pre[x + c + 1]--;
  }
  for(ll i = 2;i < 1000010;i++){
    pre[i] += pre[i - 1];
  }
  for(ll i = 2;i < 1000010;i++){
    pre[i] += pre[i - 1];
  }
  ll ans = 0;
  for(ll z = c;z <= d;z++){
    ans += pre[1000000] - pre[z];
  }
  cout << ans << endl;
}
