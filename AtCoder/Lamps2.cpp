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

  ll h, w;cin >> h >> w;
  ll ans = 0;
  ll tidy = 0;
  vector<vector<char>> arr(h + 1, vector<char>(w + 1));
  vector<vector<ll>> l(h + 1, vector<ll>(w + 1));
  vector<vector<ll>> r(h + 1, vector<ll>(w + 1));
  vector<vector<ll>> u(h + 1, vector<ll>(w + 1));
  vector<vector<ll>> d(h + 1, vector<ll>(w + 1));
  vector<vector<ll>> sz(h + 1, vector<ll>(w + 1));
  for(int i = 1;i <= h;i++){
    for(int j = 1;j <= w;j++){
      cin >> arr[i][j];
      if(arr[i][j] == '.')tidy++;
    }
  }
  for(int i = 1;i <= h;i++){
    ll cnt = 0;
    for(int j = 1;j <= w;j++){
      l[i][j] = cnt;
      if(arr[i][j] == '.')cnt++;
      else cnt = 0;
    }
    cnt = 0;
    for(int j = w;j >= 1;j--){
      r[i][j] = cnt;
      if(arr[i][j] == '.')cnt++;
      else cnt = 0;
    }
  }
  for(int i = 1;i <= w;i++){
    ll cnt = 0;
    for(int j = 1;j <= h;j++){
      u[j][i] = cnt;
      if(arr[j][i] == '.')cnt++;
      else cnt = 0;
    }
    cnt = 0;
    for(int j = h;j >= 1;j--){
      d[j][i] = cnt;
      if(arr[j][i] == '.')cnt++;
      else cnt = 0;
    }
  }
  for(int i = 1;i <= h;i++){
    for(int j = 1;j <= w;j++){
      if(arr[i][j] == '#')continue;
      sz[i][j] = l[i][j] + r[i][j] + u[i][j] + d[i][j] + 1;
    }
  }
  for(int i = 1;i <= h;i++){
    for(int j = 1;j <= w;j++){
      if(arr[i][j] == '#')continue;
      ll way_to_light = (bin_pow(2ll, sz[i][j]) + MOD - 1) % MOD;
      ll way_to_choose_other = bin_pow(2ll, tidy - sz[i][j]);
      ans = (ans + way_to_light * way_to_choose_other % MOD) % MOD;
    }
  }
  cout << ans << endl;
}
