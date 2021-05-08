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

  ll n, m, q;cin >> n >> m >> q;
  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 1e18));
  for(ll i = 1;i <= n;i++)
    dist[i][i] = 0;
  for(ll i = 0;i < m;i++){
    ll a, b, c;cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
  }
  for(ll k = 1;k <= n;k++){
    for(ll i = 1;i <= n;i++){
      for(ll j = 1;j <= n;j++){
        if(i == j)continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for(ll i = 0;i < q;i++){
    ll a, b;cin >> a >> b;
    ll ans = dist[a][b];
    if(ans == 1e18)cout << -1;
    else cout << ans;
    cout << endl;
  }
}
