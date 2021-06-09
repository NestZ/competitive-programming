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

const ll MOD = 998244353;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll n, k;cin >> n >> k;
    ll ans = 1;
    vector<ll> a(n), b(k);
    vector<ll> ind(n + 1, -1);
    vector<ll> cnt(n + 1, 1);
    for(ll i = 0;i < n;i++){
      cin >> a[i];
      ind[a[i]] = i;
    }
    for(ll i = 0;i < k;i++){
      cin >> b[i];
      cnt[ind[b[i]]] = 0;
    }
    for(ll i = 0;i < k;i++){
      ll cur_ind = ind[b[i]];
      ll cur_way = 0;
      assert(cur_ind != -1);
      if(cur_ind > 0){
        cur_way += cnt[cur_ind - 1];
      }
      if(cur_ind < n - 1){
        cur_way += cnt[cur_ind + 1];
      }
      ans = ans * cur_way % MOD;
      cnt[ind[b[i]]] = 1;
    }
    cout << ans << endl;
  }
}
