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

int dp[202][202][202] = {};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, g, b;cin >> r >> g >> b;
  vector<int> red(r), green(g), blue(b);
  for(int i = 0;i < r;i++)cin >> red[i];
  for(int i = 0;i < g;i++)cin >> green[i];
  for(int i = 0;i < b;i++)cin >> blue[i];
  sort(red.rbegin(), red.rend());
  sort(green.rbegin(), green.rend());
  sort(blue.rbegin(), blue.rend());
  int ans = 0;
  for(int i = 0;i <= r;i++){
    for(int j = 0;j <= g;j++){
      for(int k = 0;k <= b;k++){
        if(i < r && j < g)
          dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + red[i] * green[j]);
        if(i < r && k < b)
          dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + red[i] * blue[k]);
        if(j < g && k < b)
          dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + green[j] * blue[k]);
        ans = max(ans, dp[i][j][k]);
      }
    }
  }
  cout << ans << endl;
}
