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
vector<int> way(100010, 0);
stack<int> s;
const ll MOD = 1e9 + 7;

void dfs(int n){
  vis[n] = true;
  for(int adj : g[n]){
    if(vis[adj])continue;
    dfs(adj);
  }
  s.push(n);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;cin >> n >> m;
  for(int i = 0;i < m;i++){
    int a, b;cin >> a >> b;
    g[a].push_back(b);
  }
  for(int i = 1;i <= n;i++){
    if(vis[i])continue;
    dfs(i);
  }
  vector<int> topo;
  while(!s.empty()){
    topo.push_back(s.top());
    s.pop();
  }
  way[1] = 1;
  for(int i : topo){
    for(auto adj : g[i]){
      way[adj] = (way[adj] + way[i]) % MOD;
    }
  }
  cout << way[n] << endl;
}
