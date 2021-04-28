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

  int n;cin >> n;
  vector<vector<char>> arr(n + 1, vector<char>(n + 1, '.'));
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  dp[1][1] = 1;
  for(int i = 1;i <= n;i++)
    for(int j = 1;j <= n;j++)
      cin >> arr[i][j];
  if(arr[1][1] == '*')dp[1][1] = 0;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      if(arr[i][j] == '*')continue;
      if(arr[i - 1][j] != '*')
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
      if(arr[i][j - 1] != '*')
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
    }
  }
  cout << dp[n][n] << endl;
}
