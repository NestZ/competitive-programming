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

ll cnt_comma(ll n){
  string s = to_string(n);
  ll len = s.length();
  return (len + 2) / 3 - 1;
}

ll cnt_num(ll n){
  string s = to_string(n);
  ll len = s.length();
  ll m = pow(10ll, len - 1);
  return n % m + 1;
}

ll dec_num(ll n){
  string s = to_string(n);
  ll len = s.length();
  ll m = pow(10ll, len - 1);
  return n - (n % m + 1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;cin >> n;
  ll ans = 0;
  while(n > 0){
    ans += cnt_comma(n) * cnt_num(n);
    n = dec_num(n);
  }
  cout << ans << endl;
}
