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
vector<int> a(200010), b(200010);
vector<bool> vis(200010, false);

void dfs(ll n, pair<ll, ll> &p){
  vis[n] = true;
  p.first += a[n];
  p.second += b[n];
  for(auto adj : g[n]){
    if(vis[adj])continue;
    dfs(adj, p);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;cin >> n >> m;
  for(ll i = 1;i <= n;i++)cin >> a[i];
  for(ll i = 1;i <= n;i++)cin >> b[i];
  for(ll i = 0;i < m;i++){
    ll c, d;cin >> c >> d;
    g[c].push_back(d);
    g[d].push_back(c);
  }
  bool ans = true;
  for(ll i = 1;i <= n;i++){
    if(vis[i])continue;
    auto p = make_pair(0ll, 0ll);
    dfs(i, p);
    if(p.first != p.second)ans = false;
  }
  if(ans)cout << "Yes";
  else cout << "No";
  cout << endl;
}
