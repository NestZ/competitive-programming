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

  int n, u, v;cin >> n >> u >> v;
  vector<vector<int>> g(n + 1);
  vector<int> vis(n + 1, false);
  vector<int> disu(n + 1, INT_MAX);
  vector<int> disv(n + 1, INT_MAX);
  disu[u] = 0; disv[v] = 0;
  for(int i = 0;i < n - 1;i++){
    int a, b;cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  queue<pair<int, int>> q;
  q.push({u, 0});
  vis[u] = true;
  while(!q.empty()){
    int cur = q.front().first;
    int d = q.front().second; q.pop();
    for(auto adj : g[cur]){
      if(vis[adj])continue;
      vis[adj] = true;
      q.push({adj, d + 1});
      disu[adj] = d + 1;
    }
  }
  fill(vis.begin(), vis.end(), false);
  q.push({v, 0});
  vis[v] = true;
  while(!q.empty()){
    int cur = q.front().first;
    int d = q.front().second; q.pop();
    for(auto adj : g[cur]){
      if(vis[adj])continue;
      vis[adj] = true;
      q.push({adj, d + 1});
      disv[adj] = d + 1;
    }
  }
  int mx = 0;
  for(int i = 1;i <= n;i++){
    if(disu[i] < disv[i])
      mx = max(mx, disv[i]);
  }
  cout << mx - 1 << endl;
}
