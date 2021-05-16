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

int c1, c2, mn = 1e9;

void dfs(int n, int p, int num, vector<int> &parent, vector<int> &sz, vector<vector<int>> &g){
  sz[n] = 1;
  int mx = 0;
  parent[n] = p;
  for(auto adj : g[n]){
    if(adj == p)continue;
    dfs(adj, n, num, parent, sz, g);
    sz[n] += sz[adj];
    mx = max(mx, sz[adj]);
  }
  mx = max(mx, num - sz[n]);
  if(mx < mn){
    mn = mx;
    c1 = n;
    c2 = 0;
  }
  else if(mx == mn)c2 = n;
}

int leaf;
void dfs_leaf(int n, int p, vector<vector<int>> &g){
  if(g[n].size() == 1){
    leaf = n;
    return;
  }
  for(auto adj : g[n]){
    if(adj == p)continue;
    dfs_leaf(adj, n, g);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    c1 = c2 = 0;
    mn = 1e9;
    vector<vector<int>> g(n + 1);
    vector<int> sz(n + 1), parent(n + 1);
    for(int i = 0;i < n - 1;i++){
      int a, b;cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(1, 0, n, parent, sz, g);
    if(c2 == 0){
      cout << 1 << ' ' << g[1][0] << endl;
      cout << 1 << ' ' << g[1][0] << endl;
    }
    else{
      if(parent[c1] != c2)swap(c1, c2);
        dfs_leaf(c1, c2, g);
        cout << leaf << ' ' << parent[leaf] << endl;
        cout << leaf << ' ' << c2 << endl;
    }
  }
}
