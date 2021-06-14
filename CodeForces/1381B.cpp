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

  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    vector<int> arr(2 * n), v(1, 0);
    for(int i = 0;i < 2 * n;i++)cin >> arr[i];
    int mx = arr[0];
    int cnt = 1;
    for(int i = 1;i < 2 * n;i++){
      if(arr[i] > mx){
        v.push_back(cnt);
        cnt = 1;
        mx = arr[i];
      }
      else cnt++;
    }
    v.push_back(cnt);
    int len = v.size() - 1;
    vector<vector<int>> dp(len + 1, vector<int>(n + 1));
    for(int i = 1;i <= len;i++){
      for(int j = 0;j <= n;j++){
        if(v[i] > j)dp[i][j] = dp[i - 1][j];
        else{
          dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + v[i]);
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
      }
    }
    if(dp[len][n] == n)cout << "YES";
    else cout << "NO";
    cout << endl;
  }
}
