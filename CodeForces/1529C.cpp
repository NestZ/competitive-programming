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

ll dfs(ll n, ll p, vector<vector<ll>> &g,
    vector<ll> &mx_l, vector<ll> &mx_r,
    vector<ll> &l, vector<ll> &r,
    vector<vector<ll>> &dp,
    ll lst, ll cstate){
  //base case
  if(n != 1 && (ll)g[n].size() == 1){
    mx_l[n] = 0;
    mx_r[n] = 0;
    //debug() << imie(n) imie(mx_l[n]) imie(mx_r[n]);
    return dp[n][cstate] = max(mx_l[n] + abs(l[n] - lst), mx_r[n] + abs(r[n] - lst));
  }
  ll sum_l = 0, sum_r = 0;
  for(ll adj : g[n]){
    if(adj == p)continue;
    if(dp[adj][0] != -1)sum_l += dp[adj][0];
    else sum_l += dfs(adj, n, g, mx_l, mx_r, l, r, dp, l[n], 0);
  }
  for(ll adj : g[n]){
    if(adj == p)continue;
    if(dp[adj][1] != -1)sum_r += dp[adj][1];
    else sum_r += dfs(adj, n, g, mx_l, mx_r, l, r, dp, r[n], 1);
  }
  mx_l[n] = max(mx_l[n], sum_l);
  mx_r[n] = max(mx_l[n], sum_r);
  //debug() << imie(n) imie(mx_l[n]) imie(mx_r[n]);
  return dp[n][cstate] = max(sum_l + abs(l[n] - lst), sum_r + abs(r[n] - lst));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll n;cin >> n;
    vector<ll> l(n + 1), r(n + 1), mx_l(n + 1), mx_r(n + 1);
    vector<vector<ll>> g(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));
    for(ll i = 1;i <= n;i++){
      cin >> l[i] >> r[i];
    }
    for(ll i = 0;i < n - 1;i++){
      ll a, b;cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(1, 0, g, mx_l, mx_r, l, r, dp, 0, 0);
    cout << max(mx_l[1], mx_r[1]) << endl;
  }
}
