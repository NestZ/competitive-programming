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

  int n, m;cin >> n >> m;
  string sa, sb;cin >> sa >> sb;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  int ans = 0;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if(sa[i - 1] == sb[j - 1])
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
      dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]) - 1);
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}
