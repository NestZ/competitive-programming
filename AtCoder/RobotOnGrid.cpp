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

  ll n, m, k;cin >> n >> m >> k;
  vector<vector<char>> arr(n + 2, vector<char>(m + 2, '.'));
  vector<vector<int>> dpx(n + 2, vector<int>(m + 2, 0));
  vector<vector<int>> dpr(n + 2, vector<int>(m + 2, 0));
  vector<vector<int>> dpd(n + 2, vector<int>(m + 2, 0));
  for(ll i = 0;i < k;i++){
    ll x, y;cin >> x >> y;
    char c;cin >> c;
    arr[x][y] = c;
  }
  ll inv3 = bin_pow(3, MOD - 2);
  if(arr[1][1] == '.'){
    dpx[1][1] = dpr[1][1] = dpd[1][1] = bin_pow(3, n * m - k - 1);
  }
  else{
    ll pow = bin_pow(3, n * m - k);
    if(arr[1][1] == 'X')
      dpx[1][1] = pow;
    else if(arr[1][1] == 'R')
      dpr[1][1] = pow;
    else
      dpd[1][1] = pow;
  }
  for(ll i = 1;i <= n;i++){
    for(ll j = 1;j <= m;j++){
      if(i == 1 && j == 1)continue;
      if(arr[i][j] == '.'){
        // from left
        ll left = ((dpr[i][j - 1] * inv3 % MOD) + (dpx[i][j - 1] * inv3 % MOD)) % MOD;
        dpx[i][j] = (dpx[i][j] + left) % MOD;
        dpr[i][j] = (dpr[i][j] + left) % MOD;
        dpd[i][j] = (dpd[i][j] + left) % MOD;
        //from up
        ll up = ((dpd[i - 1][j] * inv3 % MOD) + (dpx[i - 1][j] * inv3 % MOD)) % MOD;
        dpx[i][j] = (dpx[i][j] + up) % MOD;
        dpr[i][j] = (dpr[i][j] + up) % MOD;
        dpd[i][j] = (dpd[i][j] + up) % MOD;
      }
      else{
        //from left
        ll left = (dpr[i][j - 1] + dpx[i][j - 1]) % MOD;
        if(arr[i][j] == 'X')
          dpx[i][j] = (dpx[i][j] + left) % MOD;
        else if(arr[i][j] == 'R')
          dpr[i][j] = (dpr[i][j] + left) % MOD;
        else dpd[i][j] = (dpd[i][j] + left) % MOD;
        //from up
        ll up = (dpd[i - 1][j] + dpx[i - 1][j]) % MOD;
        if(arr[i][j] == 'X')
          dpx[i][j] = (dpx[i][j] + up) % MOD;
        else if(arr[i][j] == 'R')
          dpr[i][j] = (dpr[i][j] + up) % MOD;
        else dpd[i][j] = (dpd[i][j] + up) % MOD;
      }
    }
  }
  ll ans = 0;
  if(arr[n][m] == '.'){
    ans = ((dpx[n][m] + dpr[n][m]) % MOD + dpd[n][m]) % MOD;
  }
  else{
    if(arr[n][m] == 'X')
      ans = dpx[n][m];
    else if(arr[n][m] == 'R')
      ans = dpr[n][m];
    else ans = dpd[n][m];
  }
  cout << ans << endl;
}
