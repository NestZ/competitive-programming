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

ll gcd(ll a, ll b, ll &x, ll &y){
  if(b == 0){
    x = 1, y = 0;
    return a;
  }
  ll x1, y1;
  ll d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    ll n, s, k;cin >> n >> s >> k;
    ll x, y, g;
    g = gcd(n, k, y, x);
    if(s % g != 0)cout << -1;
    else{
      ll x0 = -x * (s / g);
      if(x0 < 0){
        x0 += (abs(x0) + (n / g) - 1) / (n / g) * (n / g);
      }
      cout << x0 % (n / g);
    }
    cout << endl;
  }
}
