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

const int N = 200010;
int n;
vector<int> p(N);
vector<int> sz(N, 1);
vector<int> ans(N, -1);
vector<bool> vis(N, false);
vector<vector<pair<int, int>>> g(N);

void dfs(int u){
  vis[u] = true;
  for(auto adj : g[u]){
    int v = adj.first;
    if(vis[v])continue;
    int c = adj.second;
    if(ans[u] == -1){
      ans[u] = c;
      if(c == n)ans[v] = c - 1;
      else ans[v] = c + 1;
    }
    else{
      if(ans[u] == c){
        if(c == n)ans[v] = c - 1;
        else ans[v] = c + 1;
      }
      else{
        ans[v] = c;
      }
    }
    dfs(v);
  }
}

int find(int x){
  while(x != p[x])x = p[x];
  return x;
}

bool same(int a, int b){
  return find(a) == find(b);
}

void unite(int a, int b){
  a = find(a);
  b = find(b);
  if(sz[a] < sz[b])swap(a, b);
  sz[a] += sz[b];
  sz[b] = 0;
  p[b] = a;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;cin >> n >> m;
  vector<tuple<int, int, int>> edge;
  vector<int> keep(m, false);
  for(int i = 1;i <= n;i++)p[i] = i;
  for(int i = 0;i < m;i++){
    int u, v, c;cin >> u >> v >> c;
    edge.emplace_back(u, v, c);
  }
  for(int i = 0;i < m;i++){
    auto cur = edge[i];
    if(same(get<0>(cur), get<1>(cur)))continue;
    unite(get<0>(cur), get<1>(cur));
    keep[i] = true;
  }
  for(int i = 0;i < m;i++){
    if(!keep[i])continue;
    int u = get<0>(edge[i]);
    int v = get<1>(edge[i]);
    int c = get<2>(edge[i]);
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  dfs(1);
  for(int i = 1;i <= n;i++){
    cout << ans[i] << endl;
  }
}
