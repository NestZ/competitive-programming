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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll n, a, b;cin >> n >> a >> b;
    string s;cin >> s;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 2e15));
    //a pipe
    //b pillar
    dp[1][0] = a + b;
    for(ll i = 2;i <= n;i++){
      //from 0
      if(s[i - 1] != '1')
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + a + b);
      dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2 * a + 2 * b);
      //from 1
      if(s[i - 1] != '1')
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + 2 * a + 2 * b);
      dp[i][1] = min(dp[i][1], dp[i - 1][1] + a + 2 * b);
    }
    cout << dp[n][0] + b << endl;
  }
}
