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
  vector<int> w(n);
  vector<pair<int, int>> dp(1 << n, {INT_MAX, INT_MAX});
  dp[0] = {0, 0};
  for(int i = 0;i < n;i++)cin >> w[i];
  for(int i = 0;i < (1 << n);i++){
    for(int j = 0;j < n;j++){
      if(!((1 << j) & i)){
        int cnt = dp[i].first;
        int lst_w = dp[i].second;
        if(lst_w + w[j] <= x){
          dp[i | (1 << j)] = min(dp[i | (1 << j)], {cnt, lst_w + w[j]});
        }
        else{
          dp[i | (1 << j)] = min(dp[i | (1 << j)], {cnt + 1, w[j]});
        }
      }
    }
  }
  int ans = dp[(1 << n) - 1].first;
  if(dp[(1 << n) - 1].second > 0)ans++;
  cout << ans << endl;
}
