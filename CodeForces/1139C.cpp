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

const ll MOD = 1e9 + 7;
vector<ll> p(100010), sz(100010, 1);

ll bin_pow(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1)res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

ll find(ll x){
  ll nx = x;
  while(nx != p[nx])nx = p[nx];
  return p[x] = nx;
}

bool same(ll a, ll b){
  return find(a) == find(b);
}

void unite(ll a, ll b){
  a = find(a);
  b = find(b);
  if(sz[a] < sz[b])swap(a, b);
  sz[a] += sz[b];
  sz[b] = 0;
  p[b] = a;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;cin >> n >> k;
  p.resize(n + 1);
  sz.resize(n + 1);
  sz[0] = 0;
  ll ans = bin_pow(n, k);
  for(ll i = 1;i <= n;i++)p[i] = i;
  for(ll i = 0;i < n - 1;i++){
    ll a, b, c;cin >> a >> b >> c;
    if(c == 0){
      if(!same(a, b))unite(a, b);
    }
  }
  for(ll i = 1;i <= n;i++){
    if(sz[i] == 0)continue;
    ans = (ans - bin_pow(sz[i], k) + MOD) % MOD;
  }
  cout << ans << endl;
}
