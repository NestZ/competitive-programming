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

vector<bool> vis(3000, false);
vector<vector<pair<ll, ll>>> g(3000);

bool dfs(ll cur, ll n){
  vis[cur] = true;
  if(cur == n)return true;
  bool res = false;
  for(auto adj : g[cur]){
    if(vis[adj.first])continue;
    res |= dfs(adj.first, n);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;cin >> n >> m;
  vector<ll> dist(3000, 1e17);
  for(ll i = 0;i < m;i++){
    ll a, b, c;cin >> a >> b >> c;
    g[a].push_back({b, -c});
  }
  dist[1] = 0;
  for(ll i = 0;i < n - 1;i++){
    for(ll j = 1;j <= n;j++){
      for(auto adj : g[j]){
        dist[adj.first] = min(dist[adj.first], dist[j] + adj.second);
      }
    }
  }
  vector<ll> upd;
  for(ll i = 1;i <= n;i++){
    for(auto adj : g[i]){
      if(dist[adj.first] > dist[i] + adj.second){
        upd.push_back(adj.first);
      }
      dist[adj.first] = min(dist[adj.first], dist[i] + adj.second);
    }
  }
  vector<ll> toN;
  for(ll i : upd){
    if(dfs(i, n))toN.push_back(i);
    fill(vis.begin(), vis.end(), false);
  }
  bool valid = true;
  for(ll i : toN){
    if(dfs(1, i))valid = false;
    fill(vis.begin(), vis.end(), false);
  }
  if(valid)cout << -dist[n];
  else cout << -1;
  cout << endl;
}
