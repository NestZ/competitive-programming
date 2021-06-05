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

ll find(ll x, vector<ll> &p){
  ll nx = x;
  while(p[nx] != nx)nx = p[nx];
  return p[x] = nx;
}

bool same(ll a, ll b, vector<ll> &p){
  return find(a, p) == find(b, p);
}

void unite(ll a, ll b, vector<ll> &p,
    vector<ll> &sz){
  a = find(a, p);
  b = find(b, p);
  if(sz[a] < sz[b])swap(a, b);
  p[b] = a;
  sz[a] += sz[b];
  sz[b] = 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll n, m, k;cin >> n >> m >> k;
    vector<ll> p(n + 1), sz(n + 1, 1);
    vector<tuple<ll, ll, ll>> edge;
    vector<bool> used(m);
    ll cnt = 0, sum = 0, mn = INT64_MAX;
    for(ll i = 1;i <= n;i++)p[i] = i;
    for(ll i = 0;i < m;i++){
      ll u, v, s;cin >> u >> v >> s;
      edge.push_back({s, u, v});
    }
    sort(edge.begin(), edge.end());
    for(ll i = 0;i < m;i++){
      ll fst = get<1>(edge[i]);
      ll snd = get<2>(edge[i]);
      ll w = get<0>(edge[i]);
      if(!same(fst, snd, p)){
        unite(fst, snd, p, sz);
        used[i] = true;
        if(w >= k)cnt++;
      }
    }
    if(cnt >= 1){
      for(ll i = 0;i < m;i++){
        if(!used[i])continue;
        ll w = get<0>(edge[i]);
        if(w <= k)continue;
        sum += w - k;
      }
      cout << sum;
    }
    else{
      for(ll i = 0;i < m;i++){
        ll w = get<0>(edge[i]);
        mn = min(mn, abs(w - k));
      }
      cout << mn;
    }
    cout << endl;
  }
}
