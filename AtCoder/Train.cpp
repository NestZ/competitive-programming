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

vector<vector<pair<ll, pair<ll, ll>>>> g(200010);
vector<bool> vis(200010, false);
vector<ll> dist(200010, 1e15);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, x, y;cin >> n >> m >> x >> y;
  for(ll i = 0;i < m;i++){
    ll a, b, t, k;cin >> a >> b >> t >> k;
    g[a].push_back({b, {t, k}});
    g[b].push_back({a, {t, k}});
  }
  priority_queue<pair<ll, ll>> q;
  q.push({0, x});
  dist[x] = 0;
  while(!q.empty()){
    auto cur = q.top(); q.pop();
    ll cur_dist = dist[cur.second];
    vis[cur.second] = true;
    if(cur.second == 2)debug() << imie(cur_dist);
    if(cur.second == y){
      cout << cur_dist << endl;
      return 0;
    }
    for(auto adj : g[cur.second]){
      if(vis[adj.first])continue;
      ll interval = adj.second.second;
      ll adj_dist = adj.second.first;
      ll nearest = cur_dist + (interval - (cur_dist % interval)) % interval;
      ll new_dist = nearest + adj_dist;
      if(new_dist < dist[adj.first]){
        dist[adj.first] = new_dist;
        q.push({-new_dist, adj.first});
      }
    }
  }
  cout << -1 << endl;
}
