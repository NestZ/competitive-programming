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

  ll n, m, x;cin >> n >> m >> x;
  vector<vector<ll>> arr(n, vector<ll>(m));
  vector<ll> cost(n);
  for(ll i = 0;i < n;i++){
    ll t;cin >> t;
    cost[i] = t;
    for(int j = 0;j < m;j++)
      cin >> arr[i][j];
  }
  ll ans = INT64_MAX;
  for(ll i = 0;i < (1 << n);i++){
    vector<ll> s(m);
    ll sum = 0;
    for(ll j = 0;j < n;j++){
      if((1ll << j) & i){
        sum += cost[j];
        for(ll k = 0;k < m;k++){
          s[k] += arr[j][k];
        }
      }
    }
    bool valid = true;
    for(ll j = 0;j < m;j++){
      if(s[j] < x)valid = false;
    }
    if(valid)ans = min(ans, sum);
  }
  if(ans == INT64_MAX)cout << -1;
  else cout << ans;
  cout << endl;
}
