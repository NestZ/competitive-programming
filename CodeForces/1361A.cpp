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

  int n, m;cin >> n >> m;
  vector<vector<int>> g(n + 1), order(n + 1);
  vector<int> num(n + 1);
  for(int i = 0;i < m;i++){
    int a, b;cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> ans;
  for(int i = 1;i <= n;i++){
    cin >> num[i];
    order[num[i]].push_back(i);
  }
  bool valid = true;
  vector<bool> vis(n + 1);
  for(int i = 1;i <= n;i++){
    for(auto u : order[i]){
      vis[u] = true;
      set<int> s;
      for(auto adj : g[u]){
        if(vis[adj]){
          s.insert(num[adj]);
          continue;
        }
      }
      if((int)s.size() != num[u] - 1 ||
        (s.size() && *(--s.end()) != num[u] - 1))
        valid = false;
      ans.push_back(u);
    }
  }
  for(int i = 1;i <= n;i++){
    if(!vis[i])valid = false;
  }
  if(valid){
    for(int i : ans)cout << i << ' ';
  }
  else cout << -1;
  cout << endl;
}
