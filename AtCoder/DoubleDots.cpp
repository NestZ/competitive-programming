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
  vector<vector<int>> g(100010);
  vector<bool> vis(100010);
  vector<int> ans(100010, -1);
  for(int i = 0;i < m;i++){
    int a, b;cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  queue<pair<int, int>> q;
  vis[1] = true;
  q.push({1, 0});
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    ans[cur.first] = cur.second;
    for(auto adj : g[cur.first]){
      if(vis[adj])continue;
      vis[adj] = true;
      q.push({adj, cur.first});
    }
  }
  if(all_of(ans.begin() + 1, ans.begin() + n, [](int cur){return cur != -1;})){
    cout << "Yes\n";
    for(int i = 2;i <= n;i++)
      cout << ans[i] << endl;
  }
  else cout << "No\n";
}
