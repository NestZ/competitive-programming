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

  ll n, m, k;cin >> n >> m >> k;
  vector<vector<pair<ll, ll>>> g(n + 1);
  vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, 1e16));
  for(ll i = 0;i < m;i++){
    ll a, b, c;cin >> a >> b >> c;
    g[a].push_back({b, c});
  }
  priority_queue<pair<ll, ll>> q;
  q.push({0, 1});
  dist[1][0] = 0;
  while(!q.empty()){
    auto cur = q.top().second;
    auto d = -q.top().first;
    q.pop();
    if(d > dist[cur][k - 1])continue;
    for(auto adj : g[cur]){
      ll node = adj.first;
      ll edge = adj.second;
      if(d + edge < dist[node][k - 1]){
        dist[node][k - 1] = d + edge;
        q.push({-dist[node][k - 1], node});
        sort(dist[node].begin(), dist[node].end());
      }
    }
  }
  for(ll i = 0;i < k;i++){
    cout << dist[n][i] << ' ';
  }
  cout << endl;
}
