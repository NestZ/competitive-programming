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

const ll MOD = 998244353;
vector<int> g(200010);
//0 not vis
//1 visiting
//2 visited
vector<int> vis(200010, 0);

bool dfs(int n){
  vis[n] = 1;
  bool ret = false;
  if(vis[g[n]] == 0)ret |= dfs(g[n]);
  else if(vis[g[n]] == 1)ret = true;
  else ret = false;
  vis[n] = 2;
  return ret;
}

ll bin_pow(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1)res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  int cnt = 0;
  for(int i = 1;i <= n;i++)cin >> g[i];
  for(int i = 1;i <= n;i++){
    if(vis[i] != 0)continue;
    if(dfs(i))cnt++;
  }
  debug() << imie(cnt);
  cout << bin_pow(2ll, (ll)cnt) - 1 << endl;
}
