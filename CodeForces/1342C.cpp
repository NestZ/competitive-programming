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

ll len;
vector<ll> pre(40010, 0);

void build(ll a, ll b){
  len = a * b;
  pre[0] = 0;
  for(ll i = 1;i <= len;i++){
    pre[i] = pre[i - 1];
    if(i % a % b != i % b % a)
      pre[i]++;
  }
}

ll query(ll n){
  ll cnt = n / len;
  ll rem = n % len;
  return pre[len] * cnt + pre[rem];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll a, b, q;cin >> a >> b >> q;
    build(a, b);
    for(ll i = 0;i < q;i++){
      ll l, r;cin >> l >> r;
      cout << query(r) - query(l - 1) << ' ';
    }
    cout << endl;
  }
}
