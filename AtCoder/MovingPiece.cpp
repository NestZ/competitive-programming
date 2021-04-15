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

vector<vector<ll>> g(5010);
vector<bool> vis(5010, false);
vector<ll> csz(5010, -1);
vector<ll> cpoint(5010, 0);

ll dfs(ll n, stack<ll> &s){
  vis[n] = true;
  s.push(n);
  for(auto adj : g[n]){
    if(vis[adj])return adj;
    return dfs(adj, s);
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n, k;cin >> n >> k;
  ll ans = INT64_MIN;
  vector<ll> p(n + 1), c(n + 1);
  for(int i = 1;i <= n;i++){
    cin >> p[i];
    g[i].push_back(p[i]);
  }
  for(int i = 1;i <= n;i++)cin >> c[i];
  for(int start = 1;start <= n;start++){
    if(vis[start])continue;
    stack<ll> s;
    vector<ll> tmp;
    tmp.push_back(start);
    ll curp = c[start];
    ll cs = dfs(start, s);
    while(s.top() != cs){
      curp += c[s.top()];
      tmp.push_back(s.top());
      s.pop();
    }
    ll sz = tmp.size();
    for(ll i : tmp){
      cpoint[i] = curp;
      csz[i] = sz;
    }
  }
  for(int i = 1;i <= n;i++){
    ll rem = k - 1;
    ll cur = p[i];
    ll curp = c[cur];
    ll mx = curp;
    ll walk = 0;
    if(cpoint[cur] > 0){
      curp += cpoint[cur] * (rem / csz[cur]);
      mx = max(mx, curp);
      walk = rem % csz[cur];
    }
    else walk = min(rem, csz[cur]);
    for(ll j = 0;j < walk;j++){
      cur = p[cur];
      curp += c[cur];
      mx = max(mx, curp);
    }
    ans = max(ans, mx);
  }
  cout << ans << endl;
}
