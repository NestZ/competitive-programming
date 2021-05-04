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

  ll n, x, m;cin >> n >> x >> m;
  map<ll, ll> idx;
  map<ll, ll> sum;
  ll cur = x;
  idx[x] = 1;
  sum[1] = x;
  ll cs = -1, ce = -1;
  for(ll i = 2;i <= n;i++){
    cur = cur * cur % m;
    if(idx[cur] > 0){
      cs = idx[cur], ce = i - 1;
      break;
    }
    sum[i] = cur;
    idx[cur] = i;
  }
  ll ans = 0;
  if(cs == -1){
    for(ll i = 1;i <= n;i++)ans += sum[i];
  }
  else{
    ll c_sum = 0;
    ll c_cnt = (n - cs + 1) / (ce - cs + 1);
    ll rem = n - (c_cnt * (ce - cs + 1));
    for(ll i = cs;i <= ce;i++)c_sum += sum[i];
    ans += c_cnt * c_sum;
    for(ll i = 1;i <= rem;i++){
      ans += sum[i];
    }
  }
  cout << ans << endl;
}
