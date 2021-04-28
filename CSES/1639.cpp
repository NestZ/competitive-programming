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

  string sn, sm;cin >> sn >> sm;
  int n = sn.length();
  int m = sm.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for(int i = 1;i <= n;i++)dp[i][0] = i;
  for(int i = 1;i <= m;i++)dp[0][i] = i;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      int cost = 1;
      if(sn[i - 1] == sm[j - 1])cost = 0;
      int cb = dp[i - 1][j - 1] + cost;
      int cf = dp[i - 1][j] + 1;
      int cs = dp[i][j - 1] + 1;
      dp[i][j] = min({cb, cf, cs});
    }
  }
  cout << dp[n][m] << endl;
}
