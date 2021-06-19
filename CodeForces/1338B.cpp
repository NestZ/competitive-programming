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
 
int mxN = 3e5 + 10;
vector<bool> vis(mxN, false);
vector<vector<int>> g(mxN);
vector<int> deg(mxN, 0);
bool odd_path = false;
 
int dfs(int n){
  vis[n] = true;
  int cnt = 1;
  for(auto adj : g[n]){
    if(vis[adj])continue;
    cnt += dfs(adj);
  }
  return cnt;
}
 
void dfs2(int n, int d){
  vis[n] = true;
  if(deg[n] == 1 && d > 1 && d % 2 == 1)
    odd_path = true;
  for(auto adj : g[n]){
    if(vis[adj])continue;
    dfs2(adj, d + 1);
  }
}
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  int mx = 0, mn = 1;
  for(int i = 0;i < n - 1;i++){
    int a, b;cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
    deg[a]++; deg[b]++;
  }
  for(int i = 1;i <= n;i++){
    int cnt = 0;
    for(auto adj : g[i]){
      if(deg[adj] == 1){
        vis[adj] = true;
        cnt = 1;
      }
    }
    mx += cnt;
  }
  for(int i = 1;i <= n;i++){
    if(vis[i])continue;
    mx += dfs(i) - 1;
  }
  fill(vis.begin(), vis.end(), false);
  for(int i = 1;i <= n;i++){
    if(vis[i] || deg[i] > 1)continue;
    dfs2(i, 0);
  }
  if(odd_path)mn = 3;
  cout << mn << ' ' << mx << endl;
}
