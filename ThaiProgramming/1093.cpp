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

  int n;cin >> n;
  vector<vector<int>> dp(n + 10, vector<int>(n + 10, 0));
  vector<int> arr(n + 10, 0);
  for (int i = 1;i <= n;i++) cin >> arr[i];
  for (int i = 1;i <= n;i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - arr[i]);
    for (int j = 1;j <= i;j++) {
      dp[i][j] = max(dp[i - 1][j - 1] + arr[i], dp[i - 1][j + 2] - arr[i]);
    }
  }

  cout << dp[n][0] << endl;
}
