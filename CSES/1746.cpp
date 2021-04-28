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

const int MOD = 1e9 + 7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;cin >> n >> m;
  vector<int> arr(n + 1);
  vector<vector<int>> dp(n + 1, vector<int>(m + 2));
  for(int i = 1;i <= n;i++)cin >> arr[i];
  if(arr[1] != 0)dp[1][arr[1]] = 1;
  else{
    for(int i = 1;i <= m;i++)
      dp[1][i] = 1;
  }
  for(int i = 2;i <= n;i++){
    if(arr[i] != 0){
      dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] + 1]) % MOD;
      dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] - 1]) % MOD;
      dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i]]) % MOD;
    }
    else{
      for(int j = 1;j <= m;j++){
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
      }
    }
  }
  int ans = 0;
  for(int i = 1;i <= m;i++){
    ans = (ans + dp[n][i]) % MOD;
  }
  cout << ans << endl;
}
