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
  vector<int> one, zero;
  one.push_back(0);
  zero.push_back(0);
  for(int i = 0;i < n;i++){
    int t;cin >> t;
    if(t == 1)one.push_back(i);
    else zero.push_back(i);
  }
  int os = one.size();
  int zs = zero.size();
  vector<vector<int>> dp(os + 2, vector<int>(zs + 2, 1e9));
  dp[0][0] = 0;
  for(int i = 0;i <= os;i++){
    for(int j = 0;j <= zs;j++){
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(one[i] - zero[j]));
      dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
    }
  }
  int ans = INT_MAX;
  for(int i = 1;i <= zs;i++){
    ans = min(ans, dp[os][i]);
  }
  cout << ans << endl;
}
