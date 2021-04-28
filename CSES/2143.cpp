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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  vector<vector<ll>> dp(1000010, vector<ll>(6));
  dp[1][0] = 1; dp[1][5] = 1;
  for(ll i = 2;i < 1000010;i++){
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % MOD;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    dp[i][2] = (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % MOD;
    dp[i][3] = (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % MOD;
    dp[i][4] = (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % MOD;
    dp[i][5] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % MOD;
  }
  while(t--){
    ll n;cin >> n;
    ll ans = 0;
    for(ll i = 0;i < 6;i++){
      ans = (ans + dp[n][i]) % MOD;
      debug() << imie(dp[n][i]);
    }
    cout << ans << endl;
  }
}
