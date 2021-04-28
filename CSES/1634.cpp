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

  int n, x;cin >> n >> x;
  vector<int> c(n);
  vector<int> dp(1000010, 1e9);
  for(int i = 0;i < n;i++){
    cin >> c[i];
    dp[c[i]] = 1;
  }
  for(int i = 1;i <= x;i++){
    for(int j = 0;j < n;j++){
      if(c[j] > i || dp[i - c[j]] == 1e9)continue;
      dp[i] = min(dp[i], dp[i - c[j]] + 1);
    }
  }
  if(dp[x] == 1e9)cout << -1;
  else cout << dp[x];
  cout << endl;
}
