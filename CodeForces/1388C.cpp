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

ll dfs_ppl(ll n, ll p, vector<ll> &ppl, vector<ll> &ppl_sz,
    vector<vector<ll>> &g){
  ll cur = ppl[n];
  for(int adj : g[n]){
    if(adj == p)continue;
    cur += dfs_ppl(adj, n, ppl, ppl_sz, g);
  }
  return ppl_sz[n] = cur;
}

bool dfs_check(ll n, ll p, vector<ll> &ppl_sz, vector<ll> &h,
    vector<vector<ll>> &g, vector<ll> &bad, vector<ll> &good){
  if((ppl_sz[n] - h[n]) % 2 == 1)return false;
  bad[n] = (ppl_sz[n] - h[n]) / 2;
  good[n] = ppl_sz[n] - bad[n];
  if(n != 1 && good[n] > good[p])return false;
  if(bad[n] < 0 || good[n] < 0)return false;
  if(good[n] - bad[n] != h[n] ||
    good[n] + bad[n] != ppl_sz[n])
    return false;
  ll sum_good = 0;
  for(int adj : g[n]){
    if(adj == p)continue;
    if(!dfs_check(adj, n, ppl_sz, h, g, bad, good))return false;
    sum_good += good[adj];
  }
  if(sum_good > good[n])return false;
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll t;cin >> t;
  while(t--){
    ll n, m;cin >> n >> m;
    vector<ll> h(n + 1), ppl(n + 1), ppl_sz(n + 1), bad(n + 1), good(n + 1);
    vector<vector<ll>> g(n + 1);
    for(ll i = 1;i <= n;i++)cin >> ppl[i];
    for(ll i = 1;i <= n;i++)cin >> h[i];
    for(ll i = 0;i < n - 1;i++){
      ll a, b;cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs_ppl(1, 0, ppl, ppl_sz, g);
    if(dfs_check(1, 0, ppl_sz, h, g, bad, good))cout << "YES";
    else cout << "NO";
    cout << endl;
  }
}
