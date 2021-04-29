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

  int a, b;cin >> a >> b;
  vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
  for(int i = 1;i <= a;i++){
    for(int j = 1;j <= b;j++){
      if(i == j)dp[i][j] = 0;
      else if(i == 1)dp[i][j] = j - 1;
      else if(j == 1)dp[i][j] = i - 1;
      else{
        for(int k = 1;k < i;k++){
          dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
        }
        for(int k = 1;k < j;k++){
          dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
        }
      }
    }
  }
  cout << dp[a][b] << endl;
}
