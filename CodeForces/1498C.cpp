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

  int t;cin >> t;
  while(t--){
    int n, k;cin >> n >> k;
    //0 l
    //1 r
    int dp[n + 2][k + 2][2] = {};
    for(int d = 1;d <= k;d++){
      dp[n][d][1] = dp[0][d][0] = 1;
    }
    for(int d = 1;d <= k;d++){
      //shoot to r
      for(int r = n - 1;r >= 0;r--){
        dp[r][d][1] = (dp[r][d - 1][0] + dp[r + 1][d][1]) % MOD;
      }
      //shoot to l
      for(int r = 1;r <= n;r++){
        dp[r][d][0] = (dp[r][d - 1][1] + dp[r - 1][d][0]) % MOD;
      }
    }
    cout << dp[0][k][1] << endl;
  }
}
