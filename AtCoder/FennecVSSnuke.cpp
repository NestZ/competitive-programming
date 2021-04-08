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

vector<vector<int>> g(100010);
vector<bool> vis(100010, false);
vector<int> path;
int n;

bool dfs(int cur){
  vis[cur] = true;
  if(cur == n)return true;
  for(auto adj : g[cur]){
    if(vis[adj])continue;
    path.push_back(adj);
    if(!dfs(adj))path.pop_back();
    else return true;
  }
  return false;
}

int dfs2(int cur){
  int cur_sz = 1;
  vis[cur] = true;
  for(auto adj : g[cur]){
    if(vis[adj])continue;
    cur_sz += dfs2(adj);
  }
  return cur_sz;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  int cnt_f = 0;
  int cnt_s = 0;
  for(int i = 0;i < n - 1;i++){
    int a, b;cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  path.push_back(1);
  dfs(1);
  int len = path.size();
  fill(vis.begin(), vis.end(), false);
  for(int i = 0;i < len;i++)vis[path[i]] = true;
  for(int i = 0;i < len;i++){
    if(i < (len + 1) / 2)cnt_f += dfs2(path[i]);
    else cnt_s += dfs2(path[i]);
  }
  if(cnt_f > cnt_s)cout << "Fennec";
  else cout << "Snuke";
  cout << endl;
}
