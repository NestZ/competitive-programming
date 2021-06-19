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

int num[] = {0b1110111,
            0b0010010,
            0b1011101,
            0b1011011,
            0b0111010,
            0b1101011,
            0b1101111,
            0b1010010,
            0b1111111,
            0b1111011};

int to_dec(string &s){
  int n = s.length();
  int res = 0;
  for(int i = 0;i < n;i++){
    if(s[n - i - 1] == '1'){
      res += (1 << i);
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;cin >> n >> k;
  vector<int> arr(1, 0);
  for(int i = 0;i < n;i++){
    string s;cin >> s;
    arr.push_back(to_dec(s));
  }
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
  vector<vector<pair<int, int>>> from(n + 1, vector<pair<int, int>>(k + 1, {-1, -1}));
  for(int i = 0;i < 10;i++){
    if((arr[n] & num[i]) != arr[n])continue;
    int diff = __builtin_popcount(arr[n] ^ num[i]);
    if(diff <= k){
      dp[n][k - diff] = max(dp[n][k - diff], i);
    }
  }
  for(int i = n;i >= 2;i--){
    for(int j = 0;j <= k;j++){
      if(dp[i][j] == -1)continue;
      for(int l = 0;l < 10;l++){
        if((arr[i - 1] & num[l]) != arr[i - 1])continue;
        int diff = __builtin_popcount(arr[i - 1] ^ num[l]);
        if(diff <= j){
          if(l > dp[i - 1][j - diff]){
            from[i - 1][j - diff] = {i, j};
            dp[i - 1][j - diff] = l;
          }
        }
      }
    }
  }
  if(dp[1][0] == -1)cout << -1;
  else{
    vector<int> ans;
    int i = 1, j = 0;
    for(int l = 0;l < n;l++){
      ans.push_back(dp[i][j]);
      int ni = from[i][j].first;
      int nj = from[i][j].second;
      i = ni; j = nj;
    }
    for(int e : ans)cout << e;
  }
  cout << endl;
}
