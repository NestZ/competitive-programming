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

vector<vector<int>> g(200010);
vector<pair<int, int>> edge;
map<pair<int, int>, int> ans;
int cur = 0;
bool filled = false;

void dfs(int n, int p){
  if((int)g[n].size() >= 3 && !filled){
    filled = true;
    for(auto adj : g[n]){
      int fst = min(adj, n);
      int snd = max(adj, n);
      auto e = make_pair(fst, snd);
      ans[e] = cur++;
    }
  }
  else{
    for(int adj : g[n]){
      if(adj == p)continue;
      dfs(adj, n);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  for(int i = 0;i < n - 1;i++){
    int a, b;cin >> a >> b;
    if(b < a)swap(a, b);
    auto p = make_pair(a, b);
    ans[p] = -1;
    edge.push_back(p);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 0);
  for(auto p : edge){
    if(ans[p] == -1)ans[p] = cur++;
    cout << ans[p] << endl;
  }
}
