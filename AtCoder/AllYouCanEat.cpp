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

const int mxN = 3010;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;cin >> n >> t;
  vector<int> w(n + 1), v(n + 1);
  vector<bool> used(n + 1, false);
  vector<vector<int>> dp1(mxN, vector<int>(mxN, 0));
  vector<vector<int>> dp2(mxN, vector<int>(mxN, 0));
  for(int i = 1;i <= n;i++)cin >> w[i] >> v[i];
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= t;j++){
      if(w[i] > j){
        dp2[i][j] = max(dp2[i - 1][j], dp1[i - 1][j - 1] + v[i]);
        dp1[i][j] = dp1[i - 1][j];
      }
      else{
        dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - w[i]] + v[i]);
        dp2[i][j] = max(dp2[i - 1][j], dp2[i - 1][j - w[i]] + v[i]);
        dp2[i][j] = max(dp2[i][j], dp1[i - 1][j - 1] + v[i]);
      }
    }
  }
  cout << dp2[n][t] << endl;
}
