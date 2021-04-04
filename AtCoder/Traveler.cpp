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
  vector<ll> start(200010, INT64_MAX);
  vector<ll> end(200010, INT64_MIN);
  vector<pair<ll, ll>> arr;
  for(int i = 0;i < n;i++){
    ll x, c;cin >> x >> c;
    start[c] = min(start[c], x);
    end[c] = max(end[c], x);
  }
  for(int i = 1;i <= 200000;i++){
    if(start[i] == INT64_MAX)continue;
    arr.push_back({start[i], end[i]});
  }
  int len = arr.size();
  //0 end start
  //1 end end
  vector<vector<ll>> dp(len + 1, vector<ll>(2));
  dp[0][0] = dp[0][1] = 0;
  for(int i = 1;i <= len;i++){
    auto cur_start = arr[i - 1].first;
    auto cur_end = arr[i - 1].second;
    auto lst_start = 0;
    auto lst_end = 0;
    ll cur_cost = abs(cur_start - cur_end);
    if(i > 1){
      lst_start = arr[i - 2].first;
      lst_end = arr[i - 2].second;
    }
    //start at start
    //con start 
    dp[i][1] = dp[i - 1][0] + cur_cost + abs(cur_start - lst_start);
    //con end
    dp[i][1] = min(dp[i][1], dp[i - 1][1] + cur_cost + abs(cur_start - lst_end));
    //start at end
    //con start
    dp[i][0] = dp[i - 1][0] + cur_cost + abs(cur_end - lst_start);
    //con end
    dp[i][0] = min(dp[i][0], dp[i - 1][1] + cur_cost + abs(cur_end - lst_end));
  }
  cout << min(dp[len][0] + abs(arr[len - 1].first), dp[len][1] + abs(arr[len - 1].second)) << endl;
}
