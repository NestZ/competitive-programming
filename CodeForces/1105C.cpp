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

  ll n, l, r;cin >> n >> l >> r;
  vector<vector<ll>> dp(n + 1, vector<ll>(3));
  dp[0][0] = 1;
  ll cnt0 = 0,cnt1 = 0, cnt2 = 0;
  if(l % 3 == 0){
    cnt0 = (r - l) / 3 + 1;
    if(l + 1 <= r)cnt1 = (r - l - 1) / 3 + 1;
    else cnt1 = 0;
    if(l + 2 <= r)cnt2 = (r - l - 2) / 3 + 1;
    else cnt2 = 0;
  }
  else if(l % 3 == 1){
    if(l + 2 <= r)cnt0 = (r - l - 2) / 3 + 1;
    else cnt0 = 0;
    cnt1 = (r - l) / 3 + 1;
    if(l + 1 <= r)cnt2 = (r - l - 1) / 3 + 1;
    else cnt2 = 0;
  }
  else{
    if(l + 1 <= r)cnt0 = (r - l - 1) / 3 + 1;
    else cnt0 = 0;
    if(l + 2 <= r)cnt1 = (r - l - 2) / 3 + 1;
    else cnt1 = 0;
    cnt2 = (r - l) / 3 + 1;
  }
  cnt0 = max(cnt0, 0ll);
  cnt1 = max(cnt1, 0ll);
  cnt2 = max(cnt2, 0ll);
  for(ll i = 1;i <= n;i++){
    dp[i][0] = (dp[i - 1][0] * cnt0 % MOD + dp[i - 1][1] * cnt2 % MOD + dp[i - 1][2] * cnt1 % MOD) % MOD;
    dp[i][1] = (dp[i - 1][0] * cnt1 % MOD + dp[i - 1][1] * cnt0 % MOD + dp[i - 1][2] * cnt2 % MOD) % MOD;
    dp[i][2] = (dp[i - 1][0] * cnt2 % MOD + dp[i - 1][1] * cnt1 % MOD + dp[i - 1][2] * cnt0 % MOD) % MOD;
  }
  cout << dp[n][0] << endl;
}
