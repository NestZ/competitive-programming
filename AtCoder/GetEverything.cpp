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

const int INF = 1e9;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;cin >> n >> m;
  vector<pair<int, int>> box;
  vector<int> dp(1 << n, INF);
  for(int i = 0;i < m;i++){
    int cost, b;cin >> cost >> b;
    int state = 0;
    for(int j = 0;j < b;j++){
      int num;cin >> num;
      num--;
      state |= (1 << num);
    }
    dp[state] = min(dp[state], cost);
    box.push_back({cost, state});
  }
  for(int i = 0;i < (1 << n);i++){
    for(int j = 0;j < m;j++){
      int ns = box[j].second | i;
      dp[ns] = min(dp[ns], dp[i] + box[j].first);
    }
  }
  if(dp[(1 << n) - 1] == INF)cout << -1;
  else cout << dp[(1 << n) - 1];
  cout << endl;
}
