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

vector<vector<pair<ll, ll>>> g(100010);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;cin >> n >> m;
  for(ll i = 0;i < m;i++){
    ll a, b, c;cin >> a >> b >> c;
    g[a].push_back({b, c});
  }
  priority_queue<pair<ll, ll>> q;
  vector<ll> dist(100010, (ll)1e18);
  q.push({0, 1});
  dist[1] = 0;
  while(!q.empty()){
    ll cur = q.top().second;
    ll cur_dist = -q.top().first;
    q.pop();
    if(cur_dist > dist[cur])continue;
    for(auto adj : g[cur]){
      ll adj_dist = dist[adj.first];
      ll edge_dist = adj.second;
      if(cur_dist + edge_dist < adj_dist){
        dist[adj.first] = cur_dist + edge_dist;
        q.push({-dist[adj.first], adj.first});
      }
    }
  }
  for(ll i = 1;i <= n;i++){
    cout << dist[i] << ' ';
  }
  cout << endl;
}
