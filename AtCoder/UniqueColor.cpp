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

vector<int> c(200010);
vector<vector<int>> g(200010);
vector<bool> vis(200010, false);
vector<int> used(200010, 0);
vector<int> ans;

void dfs(int n){
  vis[n] = true;
  if(used[c[n]] == 0)ans.push_back(n);
  used[c[n]]++;
  for(auto adj : g[n]){
    if(vis[adj])continue;
    dfs(adj);
  }
  used[c[n]]--;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  for(int i = 1;i <= n;i++)cin >> c[i];
  for(int i = 0;i < n - 1;i++){
    int a, b;cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  sort(ans.begin(), ans.end());
  for(int i : ans)cout << i << endl;
}
