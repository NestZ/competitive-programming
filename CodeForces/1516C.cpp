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
  vector<int> arr(n + 1);
  int sum = 0;
  int odd = -1;
  for(int i = 1;i <= n;i++){
    cin >> arr[i];
    sum += arr[i];
    if(arr[i] & 1)odd = i;
  }
  if(sum & 1)cout << 0;
  else{
    int w = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(w + 1));
    for(int i = 1;i <= n;i++){
      for(int j = 1;j <= w;j++){
        if(arr[i] > j)dp[i][j] = dp[i - 1][j];
        else{
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i]] + arr[i]);
        }
      }
    }
    if(dp[n][w] != w)cout << 0;
    else{
      cout << 1 << endl;
      if(odd != -1)cout << odd;
      else{
        for(int i = 1;i <= n;i++){
          int nw = (sum - arr[i]) / 2;
          if(dp[n][nw] != nw){
            cout << i;
            break;
          }
        }
      }
    }
  }
  cout << endl;
}
