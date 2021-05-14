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

  vector<int> dp(200010);
  for(int i = 0;i < 9;i++)dp[i] = 2;
  dp[9] = 3;
  for(int i = 10;i < 200010;i++){
    dp[i] = (dp[i - 9] + dp[i - 10]) % MOD;
  }

  int t;cin >> t;
  while(t--){
    int n, m;cin >> n >> m;
    int ans = 0;
    while(n > 0){
      int x = n % 10;
      ans += ((m + x < 10) ? 1 : dp[m - 10 + x]);
      ans %= MOD;
      n /= 10;
    }
    cout << ans << endl;
  }
}
