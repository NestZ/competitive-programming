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

const ll MOD = 1e9 + 7;
vector<vector<pair<ll, ll>>> g(100010);
vector<ll> dist(100010, 1e16);
vector<ll> way(100010, 0), mnf(100010, 1e16), mxf(100010, 0);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;cin >> n >> m;
  for(ll i = 0;i < m;i++){
    ll a, b, c;cin >> a >> b >> c;
    g[a].push_back({b, c});
  }
  priority_queue<pair<ll, ll>> q;
  q.push({0, 1});
  dist[1] = 0;
  way[1] = 1;
  mnf[1] = mxf[1] = 0;
  while(!q.empty()){
    ll cur = q.top().second;
    ll d = -q.top().first;
    q.pop();
    for(auto adj : g[cur]){
      ll node = adj.first;
      ll edge = adj.second;
      if(dist[node] > edge + d){
        dist[node] = edge + d;
        way[node] = way[cur];
        mnf[node] = mnf[cur] + 1;
        mxf[node] = mxf[cur] + 1;
        q.push({-dist[node], node});
      }
      else if(dist[node] == edge + d){
        way[node] = (way[node] + way[cur]) % MOD;
        mxf[node] = max(mxf[node], mxf[cur] + 1);
        mnf[node] = min(mnf[node], mnf[cur] + 1);
      }
    }
  }
  cout << dist[n] << ' ' << way[n] << ' ' << mnf[n] << ' ' << mxf[n] << endl;
}
