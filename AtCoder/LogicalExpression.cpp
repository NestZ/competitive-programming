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

  ll n;cin >> n;
  vector<string> arr(n + 1);
  vector<vector<ll>> dp(n + 2, vector<ll>(2));
  dp[1][0] = dp[1][1] = 1;
  for(ll i = 1;i <= n;i++)cin >> arr[i];
  for(ll i = 2;i <= n + 1;i++){
    string cur = arr[i - 1];
    if(cur == "AND"){
      dp[i][0] = 2 * dp[i - 1][0] + dp[i - 1][1];
      dp[i][1] = dp[i - 1][1];
    }
    else{
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = 2 * dp[i - 1][1] + dp[i - 1][0];
    }
  }
  cout << dp[n + 1][1] << endl;
}
