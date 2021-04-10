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

vector<vector<pair<int, int>>> g(100010);
//0 = not vis
//1 = visiting
//2 = visited
vector<int> vis(100010, 0);
vector<int> dis(100010, INT_MAX);
stack<int> s;

bool dfs(int n, int d){
  vis[n] = 1;
  dis[n] = d;
  for(auto adj : g[n]){
    if(vis[adj.first] == 2)continue;
    if(vis[adj.first] == 1 && dis[n] + adj.second != dis[adj.first])
      return false;
    if(vis[adj.first] == 0)
      dfs(adj.first, d + adj.second);
  }
  vis[n] = 2;
  s.push(n);
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;cin >> n >> m;
  bool ans = true;
  for(int i = 0;i < m;i++){
    int l, r, d;cin >> l >> r >> d;
    g[l].push_back({r, d});
  }
  for(int i = 1;i <= n;i++){
    if(vis[i] == 2)continue;
    if(!dfs(i, 0))ans = false;
  }
  vector<int> node;
  while(!s.empty()){
    node.push_back(s.top());
    s.pop();
  }
  fill(dis.begin(), dis.end(), INT_MAX);
  for(int i : node){
    if(dis[i] == INT_MAX)dis[i] = 0;
    for(auto adj : g[i]){
      if(dis[adj.first] == INT_MAX)
        dis[adj.first] = dis[i] + adj.second;
      else if(dis[i] + adj.second != dis[adj.first])
        ans = false;
    }
  }
  if(ans)cout << "Yes";
  else cout << "No";
  cout << endl;
}
