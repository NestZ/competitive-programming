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

vector<vector<ll>> g(200010);
vector<pair<ll, ll>> edge;
vector<ll> offset(200010, 0);
vector<ll> parent(200010, 0);
vector<ll> ans(200010, 0);

void dfs(ll n){
  for(int adj : g[n]){
    if(adj == parent[n])continue;
    parent[adj] = n;
    dfs(adj);
  }
}

void dfs2(ll n, ll cur){
  ans[n] += cur + offset[n];
  for(int adj : g[n]){
    if(adj == parent[n])continue;
    dfs2(adj, ans[n]);
  }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

  int n;cin >> n;
  for(int i = 0;i < n - 1;i++){
    ll a, b;cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
    edge.push_back({a, b});
  }
  dfs(1);
  int q;cin >> q;
  for(int i = 0;i < q;i++){
    ll t, e, x;cin >> t >> e >> x;
    e--;
    ll fst = edge[e].first;
    ll snd = edge[e].second;
    if(t == 1){
      if(parent[fst] == snd)offset[fst] += x;
      else{
        offset[1] += x;
        offset[snd] -= x;
      }
    }
    else{
      if(parent[fst] == snd){
        offset[1] += x;
        offset[fst] -= x;
      }
      else offset[snd] += x;
    }
  }
  dfs2(1, 0ll);
  for(int i = 1;i <= n;i++){
    cout << ans[i] << endl;
  }
}
