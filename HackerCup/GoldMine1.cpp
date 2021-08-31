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

void dfs(ll n, ll p, vector<vector<ll>> &g,
    vector<ll> &c, vector<vector<ll>> &dp){
  if(g[n].size() == 1 && n != 1){
    dp[n][0] = c[n];
    dp[n][1] = c[n];
  }
  else{
    ll nw_0 = c[n];
    for(ll adj : g[n]){
      if(adj == p)continue;
      dfs(adj, n, g, c, dp);
      nw_0 = max(nw_0, c[n] + dp[adj][0]);
    }
    ll nw_1 = nw_0;
    for(ll fst : g[n]){
      for(ll snd : g[n]){
        if(fst == p || snd == p || fst == snd)continue;
        nw_1 = max(nw_1, c[n] + dp[fst][0] + dp[snd][0]);
      }
    }
    dp[n][0] = nw_0;
    dp[n][1] = nw_1;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  for(ll q = 0;q < t;q++){
    ll n;cin >> n;
    vector<ll> c(n + 10);
    vector<vector<ll>> g(n + 10);
    vector<vector<ll>> dp(n + 10, vector<ll>(2));
    for(ll i = 1;i <= n;i++)cin >> c[i];
    for(ll i = 0;i < n - 1;i++){
      ll a, b;cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(1, 0, g, c, dp);
    cout << "Case #" << q + 1 << ": " << dp[1][1] << endl;
  }
}
